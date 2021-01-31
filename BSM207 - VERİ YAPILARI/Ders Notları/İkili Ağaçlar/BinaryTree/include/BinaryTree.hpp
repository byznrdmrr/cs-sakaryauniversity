#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
using namespace std;

template <typename Nesne>
struct Dugum{
	Nesne veri;
	Dugum<Nesne> *sol;
	Dugum<Nesne> *sag;
	Dugum(const Nesne& vr,Dugum<Nesne> *sl=NULL,Dugum<Nesne> *sg=NULL){
		veri=vr;
		sol=sl;
		sag=sg;
	}
};

/**
	Ýkili Arama Aðacý
*/
template <typename Nesne>
class BinaryTree{
	private:
		Dugum<Nesne> *root;
		
		void AraveEkle(Dugum<Nesne> *&alt_root,const Nesne &yeni)
		{
			if(alt_root == NULL) alt_root = new Dugum<Nesne>(yeni);
			else if(yeni <= alt_root->veri)
				AraveEkle(alt_root->sol,yeni);
			else if(yeni > alt_root->veri)
				AraveEkle(alt_root->sag,yeni);
		}
		bool AraveSil(Dugum<Nesne> *&alt_root,const Nesne &yeni)
		{
			if(alt_root == NULL || alt_root->veri == yeni)
				return DugumSil(alt_root);
			else if(yeni < alt_root->veri)
				return AraveSil(alt_root->sol,yeni);
			else
				return AraveSil(alt_root->sag,yeni);
		}
		bool DugumSil(Dugum<Nesne> *&alt_root)
		{
			if(alt_root == NULL) return false; //Hata oluþur
			
			Dugum<Nesne> *silinecekDugum = alt_root;
			
			if(alt_root->sag == NULL) alt_root = alt_root->sol;
			else if(alt_root->sol == NULL)alt_root = alt_root->sag;
			else{
				silinecekDugum = alt_root->sol;
				Dugum<Nesne> *ebeveynDugum = alt_root;
				while(silinecekDugum->sag != NULL){
					ebeveynDugum=silinecekDugum;
					silinecekDugum=silinecekDugum->sag;
				}
				alt_root->veri = silinecekDugum->veri;
				if(ebeveynDugum == alt_root) alt_root->sol = silinecekDugum->sol;
				else ebeveynDugum->sag = silinecekDugum->sol;
			}
			delete silinecekDugum;
			return true;
		}
		void Inorder(Dugum<Nesne> *alt_root) const{
			if(alt_root != NULL){
				Inorder(alt_root->sol);
				cout<<alt_root->veri<<" ";
				Inorder(alt_root->sag);
			}
		}
		void Preorder(Dugum<Nesne> *alt_root) const{
			if(alt_root != NULL){
				cout<<alt_root->veri<<" ";
				Preorder(alt_root->sol);
				Preorder(alt_root->sag);
			}
		}
		void Postorder(Dugum<Nesne> *alt_root) const{
			if(alt_root != NULL){
				Postorder(alt_root->sol);
				Postorder(alt_root->sag);				
				cout<<alt_root->veri<<" ";
			}
		}
	public:
		BinaryTree(){
			root=NULL;
		}
		bool bosmu() const {
			return root == NULL;
		}
		void Ekle(const Nesne &yeni)
		{
			AraveEkle(root,yeni);
		}
		bool Sil(const Nesne &veri)
		{
			return AraveSil(root,veri);
		}
		void Inorder() const{
			Inorder(root);
		}
		void Preorder() const{
			Preorder(root);
		}
		void Postorder() const{
			Postorder(root);
		}
		void makeEmpty(){
			while(!bosmu())
				DugumSil(root);
		}
		~BinaryTree(){
			makeEmpty();
		}
};
#endif