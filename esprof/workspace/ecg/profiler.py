from instrumentor import instrumentor

for func in instrumentor.functions:
    if len(func.callees) > 0:
        init_code = ''
        for idx in range(len(func.callees)):
            init_code += f'__ecg_current->children[{idx}].address = (void*){func.calls[idx].name};'
            func.callees[idx].before_snippet = f'_ECG_CALLEE_BEFORE({idx});'
            func.callees[idx].after_snippet = '_ECG_CALLEE_AFTER();'
        func.entry_snippet = f'_ECG_FUNCTION_ENTER((void*){func.name}, {len(func.calls)}, {{{init_code}}});'
        func.exits_snippet = '_ECG_FUNCTION_EXIT();'

instrumentor.header_snippet = '#include <esprof-callgraph.h>'
instrumentor.instrument()
