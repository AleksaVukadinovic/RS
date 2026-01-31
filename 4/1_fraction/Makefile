PROGRAM = fraction.out
CXX 	= g++
CXXFLAGS 	= -g -std=c++17 -Wall -Wextra

$(PROGRAM): main.o fraction.o
	$(CXX) -o $(PROGRAM) $^

fraction.o: Fraction.cpp Fraction.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
