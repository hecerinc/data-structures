#include <iostream>
#include <unordered_map>
// #include <vector>

using namespace std;


int firstUnique(int arr[], int size) {
	unordered_map<int, bool> map;
	for (int i = 0; i < size; i++)
	{
		if(map.find(arr[i]) == map.end()) { // if not contains
			map[arr[i]] = true;
		}
		else{
			map[arr[i]] = false;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if(map[arr[i]])
			return arr[i];
	}
	return -1;
}
int main() {
	int arr[] = {1,2,4,1,5,4,7,2};
	int size = sizeof(arr)/sizeof(int);
	cout << firstUnique(arr, size) << endl;
}
