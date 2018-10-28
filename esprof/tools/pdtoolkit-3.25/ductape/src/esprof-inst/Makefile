
INC=../../inc
CCFLAGS=-I$(INC)
LINK=$(CXX)
LIB=../../lib/libpdb.a -ljsoncpp

PLATFORM=x86_64
COMPDIR=
PDTDIR=/home/liyixiao/profiler/pdtoolkit-3.25

BIN=$(PDTDIR)/$(PLATFORM)/$(COMPDIR)/bin

PROG=esprof-inst
INSTALL=cp $(PROG) $(BIN)

OBJS=tau_instrument.o tau_instrumentor.o tau_selective.o python_interface.o

all: $(PROG)

tau_instrument.o: tau_instrument.cpp
	$(CXX) $(CCFLAGS) -c tau_instrument.cpp

tau_selective.o: tau_selective.cpp
	$(CXX) $(CCFLAGS) -c tau_selective.cpp

tau_instrumentor.o: tau_instrumentor.cpp
	$(CXX) $(CCFLAGS) -c tau_instrumentor.cpp

python_interface.o: python_interface.cpp
	$(CXX) $(CCFLAGS) -c python_interface.cpp

$(PROG): $(OBJS)
	$(LINK) $(CCFLAGS) $(OBJS) -o $(PROG) $(LIB)

install: $(PROG)
	$(INSTALL)

remove:
	rm -rf *.cpp *.h
clean:
	rm -rf core *.o $(PROG) libpdb.a *~
	rm -rf a.out *.ti *.ii ii_files ti_files
