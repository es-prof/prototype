#include <cassert>
#include <cstdio>
#include <fstream>
#include <json/json.h>

#include "python_interface.h"

string header_snippet;
string esprof_filename;

#define INST_POINT_HEADER        (0)
#define INST_POINT_FUNCTION_BASE (1)

void test_call_python(vector<itemRef *> &itemvec) {
    char file_input[] = "/tmp/esprof.input.json.XXXXXX";
    char file_output[] = "/tmp/esprof.output.json.XXXXXX";
    mkstemp(file_input);
    mkstemp(file_output);

#if 0 // for debug
    static const char *itemkind_strs[] = { "ROUTINE", "BODY_BEGIN", "FIRST_EXECSTMT", "BODY_END", "RETURN", "EXIT", "INSTRUMENTATION_POINT", "START_TIMER", "STOP_TIMER", "START_DO_TIMER", "GOTO_STOP_TIMER", "START_LOOP_TIMER", "STOP_LOOP_TIMER", "ALLOCATE_STMT", "DEALLOCATE_STMT", "IO_STMT", "FUNCTION_CALL" };
    for (size_t i = 0; i < itemvec.size(); ++i) {
        itemRef &item = *itemvec[i];
        auto pdb = item.item;

        cerr << "New Instrumentation Point " << itemkind_strs[item.kind] << 
          ", snippet: " << item.snippet <<
          ", line: " << item.line << ", col: " << item.col <<
          ", beg line: " << item.begin.line() << ", beg col: " << item.begin.col() <<
          ", end line: " << item.end.line() << ", end col: " << item.end.col();
        if (pdb) {
            cerr << ", Full Name: " << pdb->fullName();
        }
        cerr << endl;
    }
#endif

    Json::Value functions(Json::arrayValue);
    for (size_t i = 0; i < itemvec.size(); ++i) {
        itemRef &item = *itemvec[i];

        // Assume: ROUTINE begins items of a single FUNCTION.
        if (item.kind == ROUTINE) {
            Json::Value function;
            Json::Value calls(Json::arrayValue);
            Json::Value exits(Json::arrayValue);
            function["prototype"] = item.item->fullName();

            for (; i < itemvec.size() - 1; ++i) {
                size_t j = i + 1; // look ahead
                //cout << "j: " << j << endl;
                itemRef &item = *itemvec[j];
                if (item.kind == ROUTINE) break;
                if (item.kind == BODY_END) break; // TODO: for main() only?
                assert(item.kind == INSTRUMENTATION_POINT || item.kind == FUNCTION_CALL);
                if (item.kind == FUNCTION_CALL) {
                    assert(item.attribute == BEFORE);
                    size_t before = j, after = j + 1;
                    itemRef &itemAfter = *itemvec[after];
                    assert(itemAfter.snippet == item.snippet && itemAfter.attribute == AFTER);
                    Json::Value call;
                    call["prototype"] = item.snippet;
                    call["before"] = before + INST_POINT_FUNCTION_BASE;
                    call["after"] = after + INST_POINT_FUNCTION_BASE;
                    calls.append(call);
                    i++; // skip AFTER
                } else if (item.snippet == "entry") {
                    function["entry"] = j + INST_POINT_FUNCTION_BASE;
                } else if (item.snippet == "exit") {
                    exits.append(j + INST_POINT_FUNCTION_BASE);       
                } else {
                    cout << "Unknown: " << item.snippet << endl;
                    assert(false);
                }
            }

            if (exits.size() == 0) {
                cout << "No exit: " << function["prototype"] << endl;
                assert(false);
            }

            function["callees"] = calls;
            function["exits"] = exits;
            functions.append(function);

            /*
            assert(i + 1 < itemvec.size());
            itemRef &routine = *itemvec[i + 1];
            assert(routine.kind == ROUTINE);
            assert(routine.item->fullName() == item.item->fullName());
            */

        }
    }

    Json::Value root;
    root["filename"] = esprof_filename;
    root["header"] = INST_POINT_HEADER;
    root["functions"] = functions;

    // Write input json file
    std::ofstream fout(file_input);
    fout << root << std::endl;
    fout.close();

    // Call python script
#define MAX_CMDLINE_SIZE 256
    char cmdline[MAX_CMDLINE_SIZE];
    int required_size = snprintf(cmdline, MAX_CMDLINE_SIZE, "python %s %s %s",
            getenv("PROFILER_BIN"), file_input, file_output);
    assert(required_size < MAX_CMDLINE_SIZE);
    system(cmdline);

    // Read output json file
    std::ifstream fin(file_output);
    fin >> root;
    fin.close();
    root = root["requests"];
    for (auto it = root.begin(); it != root.end(); it++) {
        int idx = std::stoi(it.key().asString());
        if (idx == INST_POINT_HEADER) {
            header_snippet = (*it).asString();
        } else {
            itemvec[idx - INST_POINT_FUNCTION_BASE]->snippet = (*it).asString();
        }
    }

    // Clean up
    remove(file_input);
    remove(file_output);
}
