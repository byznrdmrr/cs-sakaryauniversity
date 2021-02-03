#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <iostream>
#include <fstream>
using namespace std;

#include "Dugum.hpp"
#include "BinaryTree.hpp"

class HuffmanTree
{
	private:
		Dugum* root;
	public:
		HuffmanTree();
		~HuffmanTree();
		void AgacOlustur(ifstream &);
		void KoduYaz();
		void KoduYaz(Dugum *&,string);
		void Print();
};
#endif