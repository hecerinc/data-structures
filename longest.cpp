// Longest Common Subsequence
// Dynamic Programming - based solution (memoisation)

/*

Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences.

The solution given below is O(mn) (length of strings)

*/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int LCS(string x, string y, int m, int n, vector< vector<int> > &memo){
	// cout << "LCS(" << m << ", " << n << ")" << endl;
	if(m < 0 || n < 0)
		return 0;

	if(m >= 0 && n >= 0 && memo[m][n] != -1)
		return memo[m][n];

	if(x[m] == y[n])
		return 1 + LCS(x, y, m-1, n-1, memo);

	if(m-1 >= 0)
		memo[m-1][n] = LCS(x, y, m-1, n, memo);
	if(n-1 >= 0)
		memo[m][n-1] = LCS(x, y, m, n-1, memo);
	return max(LCS(x, y, m-1, n, memo), LCS(x, y, m, n-1, memo));
}
int main() {
	// code
	int T; // test cases
	cin >> T;
	while(T--) {
		int m, n;
		string x, y;
		cin >> m >> n;
		vector< vector<int> > memo(m, vector<int>(n, -1));
		cin >> x;
		cin >> y;
		cout << LCS(x, y, m-1, n-1, memo) << endl;
	}
	return 0;
}
