#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree()
{
}
HuffmanTree::~HuffmanTree()
{
}
void HuffmanTree::AgacOlustur(ifstream &fs)
{
	int freq[256];   // Türkçe karakterler alýnmýyor.
	
	for(int i=0;i<256;i++)
		freq[i]=0;
		
	while(!fs.eof())
	{
		char ch;
		fs.get(ch);
		if(!fs.eof())
		{
			unsigned int key = ch;
			freq[key]++;
		}
	}
	
	BinaryTree *ikiliAramaAgaci = new BinaryTree();
	for(int i=0;i<256;i++)
	{
		if(freq[i] > 0)
		{	
			Dugum *yeni = new Dugum((char)i,freq[i]);
			ikiliAramaAgaci->Insert(yeni);
		}		
	}
	
	while(ikiliAramaAgaci->count()>1)
	{	
		Dugum *T1 = ikiliAramaAgaci->RemoveMin();
		Dugum *T2 = ikiliAramaAgaci->RemoveMin();
		
		Dugum *T3 = new Dugum(0,T1->tekrarlanma+T2->tekrarlanma,T1,T2);
		
		ikiliAramaAgaci->Insert(T3);
	}
	root = ikiliAramaAgaci->RemoveMin();
	delete ikiliAramaAgaci;
	KoduYaz();
}
void HuffmanTree::KoduYaz()
{
	string binary = "";
	KoduYaz(root,binary);
}
void HuffmanTree::KoduYaz(Dugum *&sub_root,string binary)
{
	if(sub_root==NULL)
		return;
		
	if(sub_root->karakter!=0)
	{
		cout<<sub_root->karakter<<" "<<binary<<endl;		
	}
	
	if(sub_root->left != NULL)
	{	
		KoduYaz(sub_root->left,binary+"0");	
	}
	if(sub_root->right != NULL)
	{ 
		KoduYaz(sub_root->right,binary+"1");
	}
}