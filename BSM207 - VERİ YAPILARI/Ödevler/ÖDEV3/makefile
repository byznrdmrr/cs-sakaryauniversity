hepsi: program calistir

program:
	g++ -I ./include/ -o ./lib/IslemYoneticisi.o -c ./src/IslemYoneticisi.cpp
	g++ -I ./include/ -o ./lib/IslemKuyrugu.o -c ./src/IslemKuyrugu.cpp
	g++ -I ./include/ -o ./lib/Islem.o -c ./src/Islem.cpp
	g++ -I ./include/ -o ./lib/Islemci.o -c ./src/Islemci.cpp
	g++ -I ./include/ -o ./lib/program.o -c ./src/program.cpp
	g++ -I ./include/ -o ./bin/program ./lib/Islem.o ./lib/IslemKuyrugu.o ./lib/Islemci.o ./lib/IslemYoneticisi.o ./lib/program.o

calistir:	
	./bin/program