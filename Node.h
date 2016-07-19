template<typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(T data){
		this->data = data;
		next = NULL;
	}
};
