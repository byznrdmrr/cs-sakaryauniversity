#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
using namespace std;
#define MAX 101

struct Dugum{
	int veri;
	Dugum *ileri;
	Dugum(int vr,Dugum *ilr=NULL){
		veri=vr;
		ileri=ilr;
	}
};

class Hash{
	private:
		Dugum* Dizi[MAX];
	public:
		Hash();
		int HashCode(int);
		void Ekle(int);
		bool Cikar(int);
		void Temizle();
		bool Bul(int);
		bool Bosmu() const;
		void Yaz() const;
		~Hash();
};
#endif