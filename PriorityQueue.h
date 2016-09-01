#include "Heap.h"
template<typename T>
class PriorityQueue {
public:
	PriorityQueue(int);
	~PriorityQueue();
	void MakeEmpty();
	bool isFull() const;
	bool isEmpty() const;	
	void Enqueue(T item);
	void Dequeue(T & item);
	T Top();
private:
	int length, maxItems;
	Heap<T> items;
};
template<typename T>
PriorityQueue<T>::PriorityQueue(int max){
	maxItems = max;
	items.elements = new T[max];
	length = 0;
}
template<typename T>
PriorityQueue<T>::~PriorityQueue(){
	delete[] items.elements;
}
template<typename T>
bool PriorityQueue<T>::isFull() const{
	return maxItems == length;
}
template<typename T>
bool PriorityQueue<T>::isEmpty() const{
	return length == 0;
}
template<typename T>
void PriorityQueue<T>::Enqueue(T item) {
	if(isFull())
		throw 20;//fullQueue();
	items.elements[length - 1] = item;
	items.ReheapUp(0, length - 1);
	length++;
}
template<typename T>
void PriorityQueue<T>::Dequeue(T & item){
	// Always dequeues top item
	if(length == 0)
		throw 20; //emptyQueue();
	item = items.elements[0];
	items.elements[0] = items.elements[length - 1]; // Set as root node the bottom node (max leaf)
	length--;
	items.ReheapDown(0, length - 1); // Fix broken tree
}
