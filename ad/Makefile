INC=-I..
#INC+=-I../include/boost
INC+=-I/opt/local/include
LIBS=
CXX=g++

#flags
CFLAGS=-g 
#CFLAGS+=-Wall 
CFLAGS+=-std=c++11 -stdlib=libc++
CPP_FLAGS=-stdlib=libc++
CPP_FLAGS+=$(INC)

#file 
SRCDIR=.
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJSDIR=.
OBJS=$(SOURCES:.cpp=.o)

#pch file
PCH_SOURCE=pre_compiled_header.hpp
PCH=$(PCH_SOURCE).gch
PCH_CFLAGS=-cc1 -emit-pch -fblocks -fexceptions -fcxx-exceptions -fmax-type-align=16 -std=c++11 -stdlib=libc++
PCH_CFLAGS+=-relocatable-pch

TARGET=main

all: depend $(TARGET)

pch: $(PCH_SOURCE)
	$(CXX) $(PCH_CFLAGS) -o $(PCH) $(INC) $(PCH_SOURCE) 

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(LIBS) $(INC) $(OBJS)

SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) $(INC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: depend
depend: $(OBJS:.o=.cpp)
	-@ $(RM) depend.inc
	-@ for i in $^; do g++ $(INC) $(CPP_FLAGS) -MM $$i  | sed "s/\ [_a-zA-Z0-9][_a-zA-Z0-9]*\.cpp//g" >> depend.inc; done

-include depend.inc


