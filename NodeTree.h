#ifndef Node_Tree_Structure
#define Node_Tree_Structure
template<typename T>
struct NodeTree {
	T data;
	NodeTree<T>* left;
	NodeTree<T>* right;
	NodeTree(T data){
		this->data = data;
		left = right = NULL;
	}
	NodeTree(){data = NULL;
		left = right = NULL; }
};
#endif
