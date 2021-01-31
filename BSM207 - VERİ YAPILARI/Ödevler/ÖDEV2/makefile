hepsi: derle calistir oynat
derle:
	g++ -I include/ -o lib/top.o -c src/top.cpp
	g++ -I include/ -o lib/yapi.o -c src/yapi.cpp
calistir:
	g++ -I include/ -o bin/cikti  lib/top.o lib/yapi.o src/test.cpp
oynat:
	bin/cikti
	