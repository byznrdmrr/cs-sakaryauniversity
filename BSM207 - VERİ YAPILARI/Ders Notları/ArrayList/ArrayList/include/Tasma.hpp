#ifndef TASMA_HPP
#define TASMA_HPP

#include "Hata.hpp"

class Tasma : public Hata{
	public:
		Tasma(const string &msg):Hata(msg) { }
};
#endif