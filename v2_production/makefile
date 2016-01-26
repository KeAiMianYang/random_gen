main: Main.o Generator.o PlainArray.o Strategy.o
	g++ Main.o Generator.o PlainArray.o Strategy.o -o Main

testSetRange: testChangeRange.o Generator.o Strategy.o PlainArray.o
	g++ testChangeRange.o Generator.o Strategy.o PlainArray.o -o testSetRange

objects: Generator.cpp PlainArray.cpp Strategy.cpp
	make Generator Strategy PlainArray

Main: Main.c PlainArray.hpp Generator.hpp Strategy.hpp
	g++ Main.cpp -c

testChangeRange.o: testChangeRange.cpp Generator.hpp PlainArray.hpp Strategy.hpp
	g++ testChangeRange.cpp -c

Generator.o: Generator.cpp Generator.hpp Strategy.hpp PlainArray.hpp
	g++ Generator.cpp -c
Strategy.o: Strategy.cpp Strategy.hpp Generator.hpp PlainArray.hpp
	g++ Strategy.cpp -c
PlainArray.o: PlainArray.cpp PlainArray.hpp
	g++ PlainArray.cpp -c

clean:
	rm *.o
cleantmp:
	rm *~
