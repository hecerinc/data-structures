#include <iostream>
#include <vector>
#include <cmath>
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
int getHeight(NodeTree<int>* root){
	if(root == NULL) return 0;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return left > right? left + 1 : right + 1; // Plus the current node!
}
bool isBalanced(NodeTree<int>* root){
	if(root == NULL) return true;
	return abs(getHeight(root->left) - getHeight(root->right)) <= 1;
}
bool isBST(NodeTree<int>* root){
	if(root == NULL) return true;
	bool left = isBST(root->left);
	if(!left)
		return false;
	bool right = isBST(root->right);
	if(!right)
		return false;
	bool leftNull = root->left == NULL || root->left->data < root->data;
	bool rightNull = root->right == NULL || root->right->data > root->data;
	return leftNull && rightNull;
}
void listDepths(NodeTree<int>* root, vector< LinkedList<int>* >& arr, int level){
	if(root == NULL)
		return;
	LinkedList<int>* a = NULL;
	if(level == arr.size()){
		a = new LinkedList<int>();
		arr.push_back(a);
	}
	else
		a = arr[level];
	arr[level]->push_back(root->data);
	listDepths(root->left, arr, level + 1);
	listDepths(root->right, arr, level + 1);
}
void reverse(char* str){
	int size = sizeof(str)/sizeof(char);
	int j = size; int i = 0;
	char t;
	while(j > i){
		t = str[i];
		str[i] = str[j];
		str[j] = t;
		j--;
		i++;
	}
}
int main(){
	char s[6] = "abcde";
	cout << s << endl;
	reverse(s);
	cout << s << endl;
	// NodeTree<int>* root = new NodeTree<int>(12);
	// NodeTree<int>* p = root;
	// root->left = new NodeTree<int>(10);
	// root->right = new NodeTree<int>(14);
	// p = p->left;
	// p->left = new NodeTree<int>(5);
	// p->right = new NodeTree<int>(2);
	// p = p->left;
	// p->left = new NodeTree<int>(3);
	// p->right = new NodeTree<int>(7);
	// p->left->right = new NodeTree<int>(4);

	// root->left->left = new NodeTree<int>(3);

	// LinkedList<int> arr[5];
	// vector< LinkedList<int>* > arr;
	// NodeTree<int>* dummy = new NodeTree<int>();
	// dummy->right = root;
	// listDepths(root, arr, 0);
	// for (int i = 0; i < 5; i++) {
	// 	arr[i]->print();
	// }
	// if(isBST(root))
	// 	cout << "true" << endl;
	// else
	// 	cout << "false" << endl;
}