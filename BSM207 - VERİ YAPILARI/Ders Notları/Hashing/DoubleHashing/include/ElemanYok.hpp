#ifndef ELEMANYOK_HPP
#define ELEMANYOK_HPP

#include "Hata.hpp"

class ElemanYok : public Hata{
	public:
		ElemanYok(string msg = "Eleman Bulunamadi") : Hata(msg) {
		}
};
#endif