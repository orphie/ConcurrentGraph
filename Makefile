# GNU Make

# Parallel compile
ifndef MAKEFLAGS
    MAKEFLAGS=-j 2
endif

ifndef CXX
    CXX=g++
endif

ifndef OBJDIR
    OBJDIR=obj
endif

ifndef BINDIR
    BINDIR=bin
endif

ifndef CXXFLAGS
    CXXFLAGS=-std=c++14 -g -Wall -Werror -I${PWD}
endif

# Lib: multi-thread; boost
LIBS+=-lpthread -L/usr/lib/x86_64-linux-gnu/ -lboost_program_options 


# Directories
LIBTESTGRAPHOBJ      =       $(OBJDIR)/TestConcurrentGraph.o

# Binaries
TestConcurrentGraph: mkbindir $(LIBTESTGRAPHOBJ) 
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/testConcurrentGraph \
           $(LIBTESTGRAPHOBJ) \
           $(LIBS)

Test : TestConcurrentGraph


# Object dir
mkobjdir  :
	mkdir -p $(OBJDIR)

# Binary dir
mkbindir  :
	mkdir -p $(BINDIR)

$(OBJDIR)/TestConcurrentGraph.o : mkobjdir libGraph/test/test_concurrent_graph.cc
	$(CXX) $(CXXFLAGS) -c -o ${OBJDIR}/TestConcurrentGraph.o libGraph/test/test_concurrent_graph.cc

# Clean
clean:
	rm -rf ${OBJDIR} ${BINDIR}
