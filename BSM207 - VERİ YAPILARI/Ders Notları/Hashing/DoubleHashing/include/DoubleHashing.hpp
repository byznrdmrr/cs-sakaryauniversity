#ifndef DOUBLEHASHING_HPP
#define DOUBLEHASHING_HPP

#include <iostream>
using namespace std;

#define MAX 101
#define YAKINASAL 97

#include "ElemanYok.hpp"
#include "TabloDolu.hpp"

// Eksi değer kabul edilmeyen Double Hashing
class DoubleHashing{
	private:
		int *tablo;
		int elemanSayisi;
		
	public:
		DoubleHashing();
		int Hash1(int);
		int Hash2(int);
		bool Dolumu()const;
		void Ekle(int);
		bool Ara(int);
		void Cikar(int);
		void Temizle();
		void Yaz();
		~DoubleHashing();
};

#endif