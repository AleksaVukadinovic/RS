CXX = g++
CXXFLAGS = -Wall -std=c++17

a.out: main.o Student.o MasterStudent.o
	$(CXX) $(CXXFLAGS) main.o Student.o MasterStudent.o -o main

main.o: main.cpp Student.hpp MasterStudent.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Student.o: Student.cpp Student.hpp
	$(CXX) $(CXXFLAGS) -c Student.cpp

MasterStudent.o: MasterStudent.cpp MasterStudent.hpp Student.hpp
	$(CXX) $(CXXFLAGS) -c MasterStudent.cpp
