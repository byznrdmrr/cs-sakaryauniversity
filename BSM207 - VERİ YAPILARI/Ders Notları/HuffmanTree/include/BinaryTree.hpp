#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
using namespace std;

#include "Dugum.hpp"

struct Node{
	Dugum* eleman;
	Node *left;
	Node *right;
	Node(Dugum* yeni,Node *L=NULL,Node *R=NULL)
	{
		eleman=yeni;
		left=L;
		right=R;
	}
};

class BinaryTree{
	private:
		Node *root;
		void SearchAndInsert(Node *&sub_root,Dugum *yeni)
		{
			if(sub_root == NULL)
			{
				sub_root = new Node(yeni);
			}
			else if(yeni->tekrarlanma <= sub_root->eleman->tekrarlanma)
				return SearchAndInsert(sub_root->left,yeni);
			else if(yeni->tekrarlanma > sub_root->eleman->tekrarlanma)
				return SearchAndInsert(sub_root->right,yeni);
		}
		bool SearchAndRemove(Node *&sub_root,Dugum *veri)
		{
			if(sub_root == NULL || sub_root->eleman->karakter == veri->karakter)
				return RemoveNode(sub_root);
			else if(veri->tekrarlanma < sub_root->eleman->tekrarlanma)
				return SearchAndRemove(sub_root->left,veri);
			else
				return SearchAndRemove(sub_root->right,veri);
		}
		Dugum* SearchAndRemoveMin(Node *&sub_root)
		{
			if(sub_root->left == NULL)
			{
				Dugum* dondur = sub_root->eleman;
				RemoveNode(sub_root);
				return dondur;
			}
			return SearchAndRemoveMin(sub_root->left);
		}
		bool RemoveNode(Node *&sub_root)
		{
			if(sub_root == NULL) return false;
			Node *del = sub_root;
			if(sub_root->right == NULL) sub_root = sub_root->left;
			else if(sub_root->left == NULL)sub_root = sub_root->right;
			else{
				del = sub_root->left;
				Node *parent = sub_root;
				while(del->right != NULL){
					parent=del;
					del=del->right;
				}
				sub_root->eleman = del->eleman;
				if(parent == sub_root) sub_root->left = del->left;
				else parent->right = del->left;
			}
			delete del;
			return true;
		}
		void makeEmpty(Node *&sub_root)
		{
			if(sub_root != NULL)
			{
				makeEmpty(sub_root->left);
				makeEmpty(sub_root->right);
				delete sub_root;
				sub_root = NULL;
			}
		}
		bool find(Node *sub_root,Dugum *veri)
		{
			if(sub_root == NULL) return false;
			else if(veri->tekrarlanma < sub_root->eleman->tekrarlanma)
				return find(sub_root->left,veri);
			else if(veri->tekrarlanma > sub_root->eleman->tekrarlanma)
				return find(sub_root->right,veri);
			else
				return true;
		}
		void print(ostream &ekran,Node *sub_root)
		{
			if(sub_root != NULL)
			{
				print(ekran,sub_root->left);
				ekran<<sub_root->eleman<<" ";
				print(ekran,sub_root->right);
			}
		}
		void printPreOrder(Node *sub_root)
		{
			if(sub_root != NULL)
			{
				cout<<sub_root->eleman<<" ";				
				printPreOrder(sub_root->left);
				printPreOrder(sub_root->right);
			}
		}
		void printPostOrder(Node *sub_root)
		{
			if(sub_root != NULL)
			{				
				printPostOrder(sub_root->left);
				printPostOrder(sub_root->right);
				cout<<sub_root->eleman<<" ";
			}
		}
		int count(Node *sub_root)
		{
			if(sub_root == NULL) return 0;
			return 1+count(sub_root->left)+count(sub_root->right);
		}
		
	public:
		BinaryTree()
		{
			root=NULL;
		}
		~BinaryTree()
		{
			makeEmpty();
		}
		bool isEmpty() const
		{	
			return root==NULL;
		}
		void Insert(Dugum *yeni)
		{
			SearchAndInsert(root,yeni);
		}
		void Remove(Dugum *veri)
		{
			SearchAndRemove(root,veri);
		}
		void makeEmpty()
		{
			makeEmpty(root);
		}
		bool find(Dugum *veri)
		{
			return find(root,veri);
		}
		void print(ostream &ekran)
		{
			print(ekran,root);
		}
		void printPreOrder()
		{
			printPreOrder(root);
		}
		void printPostOrder()
		{
			printPostOrder(root);
		}
		int count()
		{
			return count(root);
		}
		Dugum* RemoveMin()
		{
			return SearchAndRemoveMin(root);
		}
		// << Operatör overloading
		friend ostream& operator<<(ostream &ekran,BinaryTree *tree) 
		{
			tree->print(ekran);
			return ekran;
		}
};
#endif