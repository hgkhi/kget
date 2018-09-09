CXX=g++
CXXFLAGS=-Wall -std=c++11
TARGET=kget.o http_manager.o
NAME=kget

all: $(TARGET)

debug: CXXFLAGS+=-g -O0

%.o: %.cc
	$(CXX) $? $(CXXFLAGS) -c -o $@ 

clean:
	rm *.o
