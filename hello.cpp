#include <iostream>
#include <string>
#include <iomanip>
#include "NodeTree.h"

using namespace std;
void postOrder(Node<int>* p, int indent) {
	if(p != NULL) {
		cout << p->data << endl;
		if(p->left) postOrder(p->left, indent+4);
		if(p->right) postOrder(p->right, indent+4);
		if(indent) {
			cout << setw(indent) << ' ';
		}

	}
}
// void postorder(Node<int>* p, int indent)
// {
// 	if(p != NULL) {
// 		if(p->right) {
// 			postorder(p->right, indent+4);
// 		}
// 		if (indent) {
// 			std::cout << std::setw(indent) << ' ';
// 		}
// 		if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
// 		std::cout<< p->data << "\n ";
// 		if(p->left) {
// 			std::cout << std::setw(indent) << ' ' <<" \\\n";
// 			postorder(p->left, indent+4);
// 		}
// 	}
// }
void printTree(Node<int>* root){ // ← ↑ →
	if(root != NULL){
		printTree(root->left);
		std::cout << root->data << " ";
		printTree(root->right);
	}
}
Node<int> * minBST(int arr[], int l, int r) {
	if(r < l) {return NULL;}
	int mid = (r-l)/2 + l;
	Node<int> * root = new Node<int>(arr[mid]);
	root->left = minBST(arr, l, mid-1);
	root->right = minBST(arr, mid+1, r);
	return root;
}
Node<int> * constructBST(int arr[], int size) {
	return minBST(arr, 0, size-1);
}

int main() {
	int x[] = {2,7,9,12,16};
	Node<int> * tree = constructBST(x, 5);
	postOrder(tree, 0);

}
