PROGRAM = list.out
CXX 	= g++
CXXFLAGS 	= -g -std=c++17 -Wall -Wextra

$(PROGRAM): main.o list.o
	$(CXX) -o $(PROGRAM) $^

list.o: List.cpp List.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
