#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

template <typename Nesne>
class Node
{
	public:
		Node(const Nesne& yeni=Nesne(),Node *n=NULL,Node *p=NULL)
		{
			eleman=yeni;
			next=n;
			prev=p;
		}
		Nesne eleman;
		Node *next;
		Node *prev;
};
#endif