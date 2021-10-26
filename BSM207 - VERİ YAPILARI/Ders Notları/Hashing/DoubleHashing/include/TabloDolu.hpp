#ifndef TABLODOLU_HPP
#define TABLODOLU_HPP

#include "Hata.hpp"

class TabloDolu : public Hata{
	public:
		TabloDolu(string msg = "Hash Tablosu Dolu") : Hata(msg) {
		}
};
#endif