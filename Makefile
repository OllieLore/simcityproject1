output: main.o zonenode.o
	g++ main.o zonenode.o -o output

main.o: main.cpp
	g++ -c main.cpp

zonenode.o: zonenode.cpp zonenode.h
	g++ -c zonenode.cpp

clean:
	rem *.o output
