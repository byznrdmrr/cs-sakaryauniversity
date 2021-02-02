#ifndef KUYRUKBOS_HPP
#define KUYRUKBOS_HPP

#include "Hata.hpp"

class KuyrukBos : public Hata{
	public:
		KuyrukBos(const string &msg):Hata(msg) { }
};
#endif