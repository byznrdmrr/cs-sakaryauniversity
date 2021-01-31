
#include "HuffmanTree.hpp"

int main()
{
	ifstream fs("../yazi.txt");
	if(fs.is_open())
	{
		HuffmanTree *huffmanAgac = new HuffmanTree();
		huffmanAgac->AgacOlustur(fs);
		delete huffmanAgac;
		fs.close();
	}
	else
	{
		cout<<"Dosya açýlamýyor."<<endl;
	} 	
}