#ifndef HEAPTREE_HPP
#define HEAPTREE_HPP
// Önemli: Bu ikili arama aðacý deðildir. Sadece ikili aðaçtýr.
#include <iostream>
using namespace std;

template <typename Nesne>
struct Dugum{
	Nesne eleman;
	Dugum *sol;
	Dugum *sag;
	int npl;
	Dugum(const Nesne& yeni,Dugum *L=NULL,Dugum *R=NULL,int np=0)
	{
		eleman=yeni;
		sol=L;
		sag=R;
		npl=np;
	}
};

template <typename Nesne>
class HeapTree{ 
	private:
		Dugum<Nesne> *root;
		Dugum<Nesne>* Birlestir(Dugum<Nesne> *h1,Dugum<Nesne> *h2) 
		{
			if(h1 == NULL) return h2;
			if(h2 == NULL) return h1;
			if(h1->eleman < h2->eleman)return BirlestirDetay(h1,h2);
			else return BirlestirDetay(h2,h1);
		}
		Dugum<Nesne>* BirlestirDetay(Dugum<Nesne> *h1,Dugum<Nesne> *h2) 
		{
			if(h1->sol == NULL) h1->sol = h2;
			else
			{
				h1->sag = Birlestir(h1->sag,h2);
				if(h1->sol->npl < h1->sag->npl) CocuklariDegis(h1);
				h1->npl=h1->sag->npl+1;
			}
			return h1;
		}
		void CocuklariDegis(Dugum<Nesne> * &t)
		{
			Dugum<Nesne>* temp = t->sol;
			t->sol = t->sag;
			t->sag = temp;
		}	
		bool RootSil()
		{
			if(root == NULL) return false;
			Dugum<Nesne> *del = root;
			root=Birlestir(root->sol,root->sag);
			delete del;
			return true;
		}
		void Bosalt(Dugum<Nesne> *&sub_root)
		{
			if(sub_root != NULL)
			{
				Bosalt(sub_root->sol);
				Bosalt(sub_root->sag);
				delete sub_root;
			}
			sub_root = NULL;
		}
		
	public:
		HeapTree()
		{
			root=NULL;
		}
		~HeapTree()
		{
			Bosalt();
		}
		bool Bosmu() const
		{	
			return root==NULL;
		}
		void Ekle(const Nesne &yeni)
		{
			root = Birlestir(new Dugum<Nesne>(yeni),root);
		}
		void Bosalt()
		{
			Bosalt(root);
		}
		void Yaz(ostream &ekran)
		{
			while(!Bosmu())
			{
				ekran<<root->eleman<<" ";
				RootSil();
			}
		}
		// << Operatör overloading
		friend ostream& operator<<(ostream &ekran,HeapTree<Nesne> *tree) 
		{
			tree->Yaz(ekran);
			return ekran;
		}
};
#endif