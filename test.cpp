#include <iostream>
#include "LinkedList.cpp"
#include "NodeTree.h"
using namespace std;

LinkedList<int>* merge(NodeTree<int>* a, NodeTree<int>* b){
	LinkedList<int>* result = new LinkedList<int>();
	if(a != NULL)
		result->push_back(a->data);
	if(b != NULL)
		result->push_back(b->data);
	return result;
}
void listDepths(NodeTree<int>* root, LinkedList<int> arr[], int i){
	if(root == NULL)
		return;
	LinkedList<int>* list = merge(root->left, root->right);
	// (*list).print();
	arr[i].append(*list);
	listDepths(root->left, arr, i+1);
	listDepths(root->right, arr, i+1);
}
int main(){
	NodeTree<int>* root = new NodeTree<int>(7);
	NodeTree<int>* p = root;
	p->left = new NodeTree<int>(2);
	p->right = new NodeTree<int>(5);
	p = p->left;
	p->left = new NodeTree<int>(3);
	p->right = new NodeTree<int>(8);
	p->left->left = new NodeTree<int>(15);
	p->right->left = new NodeTree<int>(21);
	p->right->left->right = new NodeTree<int>(22);
	p = root->right;
	p->left = new NodeTree<int>(9);
	p->right = new NodeTree<int>(17);
	p->left->right = new NodeTree<int>(12);

	LinkedList<int> arr[5];
	NodeTree<int>* dummy = new NodeTree<int>();
	dummy->right = root;
	listDepths(dummy, arr, 0);
	for (int i = 0; i < 5; i++) {
		arr[i].print();
	}

}