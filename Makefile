.PHONY = all clean

CXX = g++
CXXFLAGS= -Werror -Wall  -O2

WX_CXXFLAGS := $(shell wx-config --cxxflags)
WX_LIBS := $(shell wx-config --libs)

SRCDIR=src
INCLUDEDIR=include
BINSDIR=bin

SOFT = ${BINSDIR}/vtux

SRCS := $(wildcard ${SRCDIR}/*.cpp)
OBJS := $(SRCS:%.cpp=$(BINSDIR)/%.o)

all: ${SOFT}

${SOFT}: ${OBJS}
	@echo "Checking objects..."
	${CXX} ${WX_CXXFLAGS} ${CXXFLAGS} -o $@ $^ ${WX_LIBS} 

${BINSDIR}/%.o :%.cpp
	@echo "Creating bin and bin/src directories"
	mkdir -p ${BINSDIR}
	mkdir -p  ${BINSDIR}/${SRCDIR}
	@echo "Creating objects..."
	${CXX} -c ${WX_CXXFLAGS} ${CXXFLAGS} -I ${INCLUDEDIR} $< -o  $@  ${WX_LIBS} 


clean:
	rm -rf ${BINSDIR}/${SRCDIR}
	rm -rf ${BINSDIR}