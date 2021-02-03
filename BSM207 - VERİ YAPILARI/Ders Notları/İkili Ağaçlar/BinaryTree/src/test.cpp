#include "BinaryTree.hpp"

int main(){
	BinaryTree<int> *agac = new BinaryTree<int>();
	agac->Ekle(15);
	agac->Ekle(1);
	agac->Ekle(157);
	agac->Ekle(215);
	agac->Ekle(120);
	agac->Inorder(); cout<<endl;
	agac->Preorder(); cout<<endl;
	agac->Postorder();
	delete agac;
	return 0;
}