project2.exe: main.o character.o
	g++ -g -ggdb -o project2.exe main.o character.o
main.o: main.cpp
	g++ -g -ggdb -c main.o main.cpp
character.o: character.cpp
	g++ -g -ggdb -c character.o character.cpp

run: project2.exe
	./project2.exe