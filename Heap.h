#ifndef Heap_Structure
#define Heap_Structure
template<typename T>
void swap(T& a, T& b){
	T x = a;
	a = b;
	b = x;
}
template<typename T>
struct Heap{
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	T* elements;
	int length;
};
template<typename T>
void Heap<T>::ReheapDown(int root, int bottom){ // Pass the actual bottom (length-1)
	int maxChild, rightChild, leftChild;
	leftChild = root*2 + 1;
	rightChild = root*2 + 2;
	// Calculate the maxChild
	if(leftChild <= bottom){ // if node has a child, it has a left child (complete binary tree) so check if leftChild exists 
		if(leftChild == bottom) // if the left child is the last (leaf node), then there can't be a right child 
			maxChild = leftChild;
		else{
			if(elements[leftChild] <= elements[rightChild]) // compare left and right children, see who's bigger
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		// Once we found which of the two children is bigger, compare it to the root node, see if it's bigger or smaller than that
		if(elements[root] < elements[maxChild]){ // The only interesting case is when the root is less than the maxChild
			swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
		// If root is actually bigger than maxChild, then the heap order property is met, so there is nothing to be done
	}
}
template<typename T>
void Heap<T>::ReheapUp(int root, int bottom){ // Pass the actual root (elements[0]), and actual bottom (this is where the newly inserted node lives)
	// Compare it to the parent node
	// If the parent node is < bottom (current) node, swap
	int parent;
	if(bottom > root){ // Check that there is > 1 root
		parent = (bottom-1)/2;
		if(elements[parent] < elements[bottom]){
			swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}

}
#endif
