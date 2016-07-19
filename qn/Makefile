INC=-I../include/boost
INC+=-I..
LIBS=
CXX=g++
SRCDIR=.
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJSDIR=.
OBJS=$(SOURCES:.cpp=.o)
PCH_SOURCE=pre_compiled_header.h
PCH=$(PCH_SOURCE).gch
PCH_FLAGS=-cc1 -emit-pch 
PCH_FLAGS+=-relocatable-pch 
PCH_FLAGS+=-std=c++11 -stdlib=libc++
PCH_FLAGS+=-x c++-header
PCH_FLAGS+=-fexceptions -fcxx-exceptions
PCH_FLAGS+=-o $(PCH)
TARGET=main
CFLAGS=-g 
#CFLAGS+=-Wall 
CFLAGS+=-std=c++11 -stdlib=libc++
#CFLAGS+=-x c++-header
#CFLAGS+=-inlcude $(PCH_SOURCE)

all: depend $(TARGET)

pch: $(PCH_SOURCE)
	$(CXX) $(PCH_FLAGS) $(INC) $(PCH_SOURCE) 

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
	-@ for i in $^; do g++ -MM $$i $(INC) | sed "s/\ [_a-zA-Z0-9][_a-zA-Z0-9]*\.cpp//g" >> depend.inc; done

-include depend.inc

