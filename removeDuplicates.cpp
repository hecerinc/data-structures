#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> removeDuplicates(vector<int> arr) {
	int count = 0;
	unordered_map<int, int> map;
	for (int i = 0; i < arr.size(); i++) {
		if(map.find(arr[i]) == map.end())
			map[arr[i]] = 1;
		else {
			map[arr[i]] += 1;
			count++;
		}
	}
	vector<int> unique(arr.size() - count);
	int j = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if(map[arr[i]] != 0) {
			unique[j++] = arr[i];
			map[arr[i]] = 0;
		}
	}
	return unique;
}

int main(){
	vector<int> a = {1,1,2,3,5,5,4,7,4,2, 10};
	vector<int> result = removeDuplicates(a);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout <<  endl;
}
