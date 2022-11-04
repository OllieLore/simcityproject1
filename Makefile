output: main.o zonenode.o residentialzone.o industrialzone.o commercialzone.o
	g++ main.o zonenode.o residentialzone.o industrialzone.o commercialzone.o -o output

main.o: main.cpp
	g++ -c main.cpp

zonenode.o: zonenode.cpp zonenode.h
	g++ -c zonenode.cpp

residentialzone.o: residentialzone.cpp residentialzone.h
	g++ -c residentialzone.cpp

industrialzone.o: industrialzone.cpp industrialzone.h
	g++ -c industrialzone.cpp

commercialzone.o: commercialzone.cpp commercialzone.h
	g++ -c commercialzone.cpp commercialzone.h

clean:
	rem *.o output
