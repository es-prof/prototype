import json
import os
import sys
from typing import Dict, List


class FunctionCall:
    def __init__(self, json_data):
        self._prototype: str = json_data['prototype']
        self._before_id: int = json_data['before']
        self._after_id: int = json_data['after']
        self._before_snippet: str = f'/* ESPROF before call: {self.name} */'
        self._after_snippet: str = f'/* ESPROF after call: {self.name} */'
        pass

    @property
    def prototype(self) -> str:
        return self._prototype

    @property
    def name(self) -> str:
        return (self._prototype.split('(')[0]).split(' ')[-1]

    @property
    def before_snippet(self) -> str:
        return self._before_snippet

    @before_snippet.setter
    def before_snippet(self, snippet: str):
        self._before_snippet = snippet

    @property
    def after_snippet(self) -> str:
        return self._after_snippet

    @after_snippet.setter
    def after_snippet(self, snippet: str):
        self._after_snippet = snippet

    def dump(self) -> Dict[int, str]:
        data = {}
        if self._before_snippet != '':
            data[self._before_id] = self._before_snippet
        if self._after_snippet != '':
            data[self._after_id] = self._after_snippet
        return data


class Function:
    def __init__(self, json_data):
        self._prototype: str = json_data['prototype']
        self._entry_id: int = json_data['entry']
        self._exits_id: List[int] = json_data['exits']
        self._entry_snippet: str = f'/* ESPROF entry: {self.prototype} */'
        self._exits_snippet: str = f'/* ESPORF exit: {self.prototype} */'
        self._calls = [FunctionCall(x) for x in json_data['callees']]

    @property
    def prototype(self) -> str:
        return self._prototype

    @property
    def name(self) -> str:
        return (self._prototype.split('(')[0]).split(' ')[-1]

    @property
    def callees(self) -> List[FunctionCall]:
        return self._calls

    @property
    def entry_snippet(self) -> str:
        return self._entry_snippet

    @entry_snippet.setter
    def entry_snippet(self, snippet: str):
        self._entry_snippet = snippet

    @property
    def exits_snippet(self) -> str:
        return self._exits_snippet

    @exits_snippet.setter
    def exits_snippet(self, snippet: str):
        self._exits_snippet = snippet

    def dump(self) -> Dict[int, str]:
        data = {}
        if self._entry_snippet != '':
            data[self._entry_id] = self._entry_snippet
        if self._exits_snippet != '':
            for id_ in self._exits_id:
                data[id_] = self._exits_snippet
        for fc in self.callees:
            data.update(fc.dump())
        return data


class Instrumentor:
    def __init__(self, file_in, file_out):
        self._functions: List[Function] = []
        self._file_out: str = file_out
        self._header_snippet: str = ''

        json_data = json.load(open(file_in))
        print(json_data)
        self._header_id: int = json_data['header']
        self._filename: str = json_data['filename']
        for data in json_data['functions']:
            self._functions.append(Function(data))

    @property
    def filename(self) -> str:
        return self._filename

    @property
    def functions(self) -> List[Function]:
        return self._functions

    @property
    def header_snippet(self) -> str:
        return self._header_snippet

    @header_snippet.setter
    def header_snippet(self, snippet: str):
        self._header_snippet = snippet

    def instrument(self):
        data = {self._header_id: self.header_snippet}
        for func in self._functions:
            data.update(func.dump())

        data = {'requests': data}
        with open(self._file_out, 'w') as f:
            json.dump(data, f)
        #with open(self._file_out, 'r') as f:
        #    print(f.readlines())


#print(sys.argv)
instrumentor = Instrumentor(sys.argv[1], sys.argv[2])
