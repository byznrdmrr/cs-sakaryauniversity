#ifndef HATA_HPP
#define HATA_HPP

#include <iostream>
using namespace std;

class Hata{
	private:
		string mesaj;
	public:
		Hata(string msg){
			mesaj=msg;
		}
		string Mesaj() const{
			return mesaj;
		}
};

#endif