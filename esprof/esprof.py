#!/usr/bin/env python

import os
import subprocess
import sys
import tempfile

# Paths
PYT_PATH = os.path.dirname(os.path.realpath(__file__))
PDT_PATH = f'{PYT_PATH}/tools/pdtoolkit-3.25/x86_64/bin'
INST_BIN = f'{PYT_PATH}/tools/esprof-inst/esprof-inst'
REQ_FILE = f'{PYT_PATH}/tools/esprof-inst/select.tau'

#
# TODO: only g++ is supported currently
#
compiler: str = sys.argv[1]
assert compiler.endswith('g++')


def call(args):
    p = subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    stdout = []
    while True:
        line = p.stdout.readline().decode('utf-8')
        stdout.append(line)
        print(line, end='')
        if line == '' and p.poll() is not None:
            break
    return ''.join(stdout)


#
# Generate pdb
#
# TODO: for now, assume that input file is ALWAYS at last
src_filename = sys.argv[-1]
cmd = [f'{PDT_PATH}/cxxparse', src_filename, *sys.argv[2:-1], r'-D__insn_mfspr(...)']
for i, v in enumerate(cmd):
    if v.startswith('-D'):
        cmd[i] = v.replace('(', r'\\\(').replace(')', r'\\\)')
    elif v.startswith('-isystem'):
        cmd[i] = v.replace('-isystem', '--sys_include')
        pass
    elif v.startswith('-o'):
        if v == '-o':  # also used by pdb
            cmd[i + 1] = ''
        cmd[i] = ''
pdb_filename = tempfile.mkstemp('.pdb')[1]
cmd += ['-o', pdb_filename]
os.system(' '.join(cmd))

#
# Instrument code
#

inst_src_filename = tempfile.mkstemp(os.path.splitext(src_filename)[1], dir=os.path.dirname(src_filename))[1]
cmd = f'PYTHONPATH={PYT_PATH} {INST_BIN} {pdb_filename} {src_filename} -o {inst_src_filename} -f {REQ_FILE}'
os.system(cmd)

#
# Compile instrumented code
#
# TODO: for now, assume that input file is ALWAYS at last
cmd = sys.argv[1:-1]
cmd.append(os.getenv('PROFILER_OPT'))
if not any(x.startswith('-o') for x in cmd):
    cmd += ['-o', f'{os.path.splitext(src_filename)[0]}.o']
cmd.append(inst_src_filename)
call(cmd)
print(inst_src_filename)

# Clean up
os.remove(pdb_filename)
os.remove(inst_src_filename)
