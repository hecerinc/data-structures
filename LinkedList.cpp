#include "Node.h"
#include <iostream>
#include <cassert>
template<typename T>
class LinkedList {
public:
	LinkedList(){
		head = NULL;
		length = 0;
	}
	~LinkedList(){
		makeEmpty();
	}
	void makeEmpty(){
		// Delete all nodes
		Node<T>* p = head;
		Node<T>* q = head;

		while(p != NULL){
			p = p->next;
			delete q;
			q = p;
		}

		head = NULL;
		this->length = 0;
	}
	void push_back(const T data){
		Node<T>* p = new Node<T>(data);
		// Assume we only have head
		Node<T>* temp = head;
		if(temp == NULL){
			head = p;
			this->length = 1;
			return;
		}
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = p;
		this->length = this->length + 1;
	}
	void deleteItem(const T data){
		Node<T>* temp = head;
		Node<T>* prev = head;
		if(temp == NULL)
			return;
		else 
			temp = temp->next;

		while(temp != NULL && temp->data != data){
			temp = temp->next;
			prev = prev->next;
		}
		if(temp == NULL)
			return;
		// Found it delete
		prev->next = temp->next;
		delete temp;
		temp = prev = NULL;
		this->length = this->length - 1;
	}
	T getItem(int index) const{
		Node<T>* p = head;
		int i = 0;
		if(index > length-1){
			throw 1;
		}
		while(p != NULL){
			if(i == index)
				return p->data;
			p = p->next;
			i++;
		}
		throw 1;
	}
	T first(){
		if(head == NULL)
			throw 1;
		return head->data;
	}
	void reverse(){
		Node<T>* previous;
		Node<T>* current;
		Node<T>* next;
		previous = NULL;
		current = this->head;
		while(current != NULL){
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		head = previous;
	}
	bool isEmpty(){return head == NULL;}
	int size(){return this->length;} // API methods
	void empty(){makeEmpty();} // API methods

	void print(){
		Node<T>* p = head;
		while(p != NULL){
			std::cout << p->data;
			if(p->next != NULL)
				std::cout << " -> ";
			p = p->next;
		}
		std::cout << std::endl;
	}
	void push(T newData){
		this->length = this->length + 1;
		LinkedList<T>::Push(&head, newData);
	}
	T pop(){
		this->length = this->length - 1;
		return LinkedList<T>::Pop(&head);
	}
	T operator[](int i) const {return this->getItem(i);}
	// TODO: document this bug:
	// T& operator[](int i) {return 100;}
	// T& operator[](unsigned int i){ return getItem(i);}
	// const T& operator[](unsigned int i) const{ return getItem(i);}

	// Add this method to the object's API (calling the static version)
	void frontBackSplit(Node<T> ** frontRef, Node<T> ** backRef){ 
		return LinkedList<T>::FrontBackSplit(this->head, frontRef, backRef);
	}




	// Methods from Linked Lists Problems
	// These methods are the static versions that come in the PDF
	// http://cslibrary.stanford.edu/105/LinkedListProblems.pdf
	// ==============================================================================================================

	static void FrontBackSplit(Node<T>* source, Node<T>** frontRef, Node<T>** backRef){
		// TODO: handle 0 elements?

		// Handle the case where there is only one element
		if(source->next == NULL) { 
			*frontRef = source;
			*backRef = source;
			return;
		}

		Node<T>* tmp = new Node<T>;
		Node<T>* p = tmp;
		Node<T>* f = tmp;
		tmp->next = source;

		while(p != NULL && p->next != NULL){
			p = p->next->next; // Tortoise and the Hare
			f = f->next;
		}

		*backRef = f->next;
		f->next = NULL;
		*frontRef = source;
	}
	static void moveNode(Node<T>** destRef, Node<T>** sourceRef){
		assert(*sourceRef != NULL);
		T val = Pop(&(*sourceRef));
		Push(&(*destRef), val);
	}
	static T Pop(Node<T>** headRef){
		assert(*headRef != NULL);
		Node<T>* p = *headRef;
		*headRef = (*headRef)->next;
		T data = p->data;
		delete p;
		return data;
	}
	static void Push(Node<T>** headRef, T newData){
		Node<T>* p = new Node<T>(newData);
		p->next = *headRef;
		*headRef = p;
	}
	static Node<T>* shuffleMerge(Node<T>* a, Node<T>* b){
		Node<T>* h = NULL;
		Node<T>** p = &h;
		while(a != NULL && b != NULL){
			if(a != NULL){
				moveNode(p, &a);
				p = &((*p)->next);
			}
			if(b != NULL){
				moveNode(p, &b);
				p = &((*p)->next);
			}
		}
		return h;
	}
	static Node<T>* SortedMerge(Node<T>* a, Node<T>* b){
		Node<T>* h = NULL; // head
		Node<T>** p = &h;
		while(a != NULL && b != NULL){
			moveNode(p, minNode(&a, &b));
			p = &((*p)->next);
		}
		while(a != NULL){
			moveNode(p, &a);
			p = &((*p)->next);
		}
		while(b != NULL){
			moveNode(p, &b);
			p = &((*p)->next);
		}
		return h;
	}
	static Node<T>** minNode(Node<T>** a, Node<T>**b){
		return ((*a)->data < (*b)->data) ? a : b;
	}
	static void MergeSort(Node<T>** headRef){
		Node<T>* h = *headRef;
		if(h != NULL && h->next != NULL){
			Node<T>* a;
			Node<T>* b;
			FrontBackSplit(h, &a, &b);
			MergeSort(&a);
			MergeSort(&b);
			*headRef = SortedMerge(a, b);
		}
	}


	Node<T>* head;

private:
	int length;

};
