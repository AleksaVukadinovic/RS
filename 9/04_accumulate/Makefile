a.out: main.o http.o middle.o
	g++ main.o http.o middle.o -o a.out

main.o: main.cpp Middleware.hpp HttpRequest.hpp
	g++ -c main.cpp -o main.o

middle.o: Middleware.cpp Middleware.hpp HttpRequest.hpp
	g++ -c Middleware.cpp -o middle.o

http.o: HttpRequest.cpp HttpRequest.hpp
	g++ -c HttpRequest.cpp -o http.o
