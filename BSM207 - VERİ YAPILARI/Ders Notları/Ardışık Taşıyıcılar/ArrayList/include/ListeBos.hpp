#ifndef LISTEBOS_HPP
#define LISTEBOS_HPP

#include "Hata.hpp"

class ListeBos : public Hata{
	public:
		ListeBos(const string &msg):Hata(msg) { }
};
#endif