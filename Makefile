CXX=c++
CXXFLAGS=-g -std=c++11 

main: Funkcijos.o stud.o 
	g++ -std=c++11 -o main main.cpp Funkcijos.o stud.o
Funkcijos:
	g++ -std=c++11 -c Funkcijos.cpp
stud:
	g++ -std=c++11 -c stud.cpp
clean:
	rm *.o main
