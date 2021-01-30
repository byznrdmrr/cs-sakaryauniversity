#ifndef ELEMANYOK_HPP
#define ELEMANYOK_HPP

#include "Hata.hpp"

class ElemanYok : public Hata{
	public:
		ElemanYok(const string &msg):Hata(msg) { }
};
#endif