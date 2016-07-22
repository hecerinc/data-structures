#ifndef Node_Tree_Structure
#define Node_Tree_Structure
template<typename T>
struct Node {
	T data;
	Node<T>* left;
	Node<T>* right;
	Node(T data){
		this->data = data;
		left = right = NULL;
	}
	Node(){data = left = right = NULL; }
};
#endif
