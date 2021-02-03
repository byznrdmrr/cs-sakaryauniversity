#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

#include "ElemanYok.hpp"

template <typename Nesne>
class Dugum{
	public:
		Nesne eleman;
		Dugum *ileri;
		Dugum(const Nesne& elm,Dugum *ilr=NULL){
			eleman=elm;
			ileri=ilr;
		}
};


template <typename Nesne>
class Stack{
	private:
		Dugum<Nesne> *stackBasi;
	public:
		Stack(){
			stackBasi=NULL;
		}
		bool isEmpty() const{
			return stackBasi == NULL;
		}
		void push(const Nesne& eleman){
			stackBasi = new Dugum<Nesne>(eleman,stackBasi); 
		}
		void pop() throw(ElemanYok){
			if(isEmpty()) throw ElemanYok("Eleman yok");
			Dugum<Nesne> *silinecek = stackBasi;
			stackBasi = stackBasi->ileri;
			delete silinecek;
		}
		const Nesne& top() const throw(ElemanYok){
			if(isEmpty()) throw ElemanYok("Eleman yok");
			return stackBasi->eleman;
		}		
		void makeEmpty(){
			while(!isEmpty())
				pop();
		}
		~Stack(){
			makeEmpty();
		}		
};
#endif