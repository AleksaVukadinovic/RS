PROGRAM = raii.out
CXX=g++
CFLAGS = -std=c++20 -Wall -Wextra

$(PROGRAM): main.o
	$(CXX) -o $(PROGRAM) main.o

.PHONY: clean

clean:
	-rm *.o $(PROGRAM)