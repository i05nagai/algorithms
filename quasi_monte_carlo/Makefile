INC=-IC:\Users\admin\Documents\Programming\cpp\libraries\boost_1_60_0
INC+=-I..
LIBS=
CFLAGS=-Wall -g -std=c++11
CXX=g++
SRCDIR=.
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJSDIR=.
OBJS=$(SOURCES:.cpp=.o)
PCH_SOURCE=pre_compiled_header.h
PCH=$(PCH_SOURCE).gch
TARGET=quasi_monte_carlo

all: depend $(TARGET)

pch: $(PCH_SOURCE)
	$(CXX) $(INC) $(PCH_SOURCE)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(LIBS) $(INC) $(OBJS)

SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) $(INC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f 

.PHONY: depend
depend: $(OBJS:.o=.cpp)
	-@ $(RM) depend.inc
	-@ for i in $^; do cpp -MM $$i $(INC) | sed "s/\ [_a-zA-Z0-9][_a-zA-Z0-9]*\.cpp//g" >> depend.inc; done

-include depend.inc

