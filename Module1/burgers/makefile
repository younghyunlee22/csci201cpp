all: burger main common
	g++ -pedantic-errors -g -fdiagnostics-color=always -o main common.o burger.o main.o
main: burger.h main.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c main.cpp -o main.o
burger: burger.h burger.cpp common.h
	g++ -pedantic-errors -fdiagnostics-color=always -g -c burger.cpp -o burger.o
common: common.h common.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g -c common.cpp -o common.o
