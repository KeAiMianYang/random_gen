main: Main.o Generator.o PlainArray.o Strategy.o
	g++ Main.o Generator.o PlainArray.o Strategy.o -o Main

Generator: Generator.cpp Generator.hpp Strategy.hpp PlainArray.hpp
	g++ Generator.cpp -c
Strategy: Strategy.cpp Strategy.hpp Generator.hpp PlainArray.hpp
	g++ Strategy.cpp -c
PlainArray: PlainArray.cpp PlainArray.hpp
	g++ PlainArray.cpp -c

clean:
	rm *.o
cleantmp:
	rm *~
