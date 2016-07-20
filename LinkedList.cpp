#include "Node.h"
#include <iostream>

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
	}
	void push_back(const T data){
		Node<T>* p = new Node<T>(data);
		// Assume we only have head
		Node<T>* temp = head;
		if(temp == NULL){
			head = p;
			return;
		}
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = p;
		length++;
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
		length--;
	}
	T getItem(int index){
		Node<T>* p = head;
		int i = 0;
		if(index > length-1)
			return NULL;
		while(p != NULL){
			if(i == index)
				return p->data;
			p = p->next;
			i++;
		}
		return NULL;
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
	int getLength(){return length;}

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
	static void FrontBackSplit(Node<T>* source, Node<T>** frontRef, Node<T>** backRef){
		Node<T>* tmp = new Node<T>;
		Node<T>* p = tmp;
		Node<T>* f = tmp;
		tmp->next = source;
		while(p != NULL && p->next != NULL){
			p = p->next->next;
			f = f->next;
		}
		*backRef = f->next;
		f->next = NULL;
		*frontRef = source;
	}
	Node<T>* head;
private:
	int length;
};