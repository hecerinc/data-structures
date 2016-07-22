#include <iostream>
#include "NodeTree.h"
template<typename T>
class BinaryTree {
public:
	BinaryTree(){root = NULL;}
	~BinaryTree(){
		// Post order traversal
		DestroyNodes(this->root);
		root = NULL;
	}
	void DestroyNodes(Node<T>* root){
		if(root != NULL){
			DestroyNodes(root->left);
			DestroyNodes(root->right);
			delete root;
		}
	}
	void insert(T item){
		insertNode(this->root, item);
	}
	void insertNode(Node<T>*& root, T item){
		if(root == NULL)
			root = new Node<T>(item);
		else if(root->data > item)
			insertNode(root->left, item);
		else
			insertNode(root->right, item);
	}
	void remove(T item){
		removeNode(this->root, item);
	}
	void removeNode(Node<T>*& root, T item){
		// Find the node's parent
		if(root == NULL)
			return;
		else if(root->data > item)
			return removeNode(root->left, item);
		else if(root->data < item)
			return removeNode(root->right, item);
		else // Found it!
			return deleteNode(root); // Delete the node
	}
	void deleteNode(Node<T>*& root){
		// Three cases:
		// 	1. Node is leaf
		// 	2. Node has one child
		// 	3. Node has two children
		Node<T>* tmp = root;

		// Cases 1 & 2
		if(root->left == NULL){
			root = root->right;
			delete tmp;
		}
		else if(root->right == NULL){
			root = root->left;
			delete tmp;
		}
		else{ // Case 3
			// 1. Find (logical) successor or predecessor (use predecessor)
			// 2. Assign value of predecessor to this node
			// 3. Delete predecessor node
			Node<T>* predecessor = getPredecessor(root);
			root->data = predecessor->data;
			removeNode(root->left, root->data);
		}
	}
	Node<T>* getPredecessor(Node<T>* root){ 
		// Predecessor = largest of the smallest
		root = root->left;
		while(root->right != NULL)
			root = root->right;
		return root;
	}
	void print(){
		printPreOrder(this->root);
		std::cout << std::endl;
	}
	// In order traversal
	void printTree(Node<T>* root){ // ← ↑ →
		if(root != NULL){
			printTree(root->left);
			std::cout << root->data << " ";
			printTree(root->right);
		}
	}
	// Post Order traversal
	void printPostOrder(Node<T>* root){
		if(root != NULL){
			printPostOrder(root->left);
			printPostOrder(root->right);
			std::cout << root->data << " ";
		}
	}
	// Pre Order traversal
	void printPreOrder(Node<T>* root){
		if(root != NULL){
			std::cout << root->data << " ";
			printPreOrder(root->left);
			printPreOrder(root->right);
		}
	}
	void makeEmpty(){
		DestroyNodes(this->root);
		root = NULL;
	}
	bool find(T item){
		return find(this->root, item);
	}
	bool findNode(Node<T>* root, T item){
		if(root == NULL)
			return false;
		else if(root->data == item)
			return true;
		else if(root->data > item)
			return findNode(root->left);
		else
			return findNode(root->right);
	}
	bool isEmpty(){return root == NULL;}
	int length(){
		return getLength(this->root);
	}
	int getLength(Node<T>* root){
		if(root == NULL)
			return 0;
		// Number of nodes in left subtree + 
		// Number of nodes in right subtree + 1
		return getLength(root->left) + getLength(root->right) + 1;
	}
private:
	Node<T>* root;
};
