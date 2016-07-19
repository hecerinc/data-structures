#include "Node.h"
#include <iostream>
template<typename T>
class Queue {
public:
	Queue(){
		front = rear = NULL;
		length = 0;
	}
	~Queue(){
		makeEmpty();
	}
	void enqueue(T data){
		Node<T>* p = new Node<T>(data);
		if(front == NULL)
			front = p;
		else
			rear->next = p;
		rear = p;
		length++;
	}
	T dequeue(){
		if(front == NULL)
			return NULL;
		Node<T> *p = front;
		T d = front->data;
		front = front->next;				
		if(front == NULL)
			rear = NULL;
		delete p;
		length--;
		return d;
	}
	T top(){
		if(front == NULL)
			return NULL;
		return front->data;
	}

	bool isEmpty(){return front == NULL;}
	void makeEmpty(){
		Node<T>* p = front;
		while(p != NULL){
			p = p->next;
			delete front;
			front = p;
		}
		rear = NULL;
	}
private:
	Node<T>* front;
	Node<T>* rear;
	int length;
};
