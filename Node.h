#ifndef Node_Structure
#define Node_Structure
template<typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(T data){
		this->data = data;
		next = NULL;
	}
	Node(){
		this->data = NULL;
		next = NULL;
	}
};
#endif