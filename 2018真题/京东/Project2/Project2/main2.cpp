#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = 100000007;

typedef vector<int> vec;
typedef vector<vector<int> > mat;

bool isPalindrome(string s) {
	int len = s.length();
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

template<class T>
void printMatrix(const vector<vector<T> >& matrix) {
	int m = matrix.size();
	if (m == 0)
		return;
	int n = matrix[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	string s;
	getline(cin, s);
	int len = s.length();
	vector<vector<ll> > dp(len, vector<ll>(len, 0));
	for (int i = 0; i < len; i++)
		dp[i][i] = 1;
	//printMatrix(dp);
	for (int k = 1; k < len; k++) {
		for (int i = 0; i < len-k; i++) {
			int j = i + k;
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
			if (s[i] == s[j])
				dp[i][j] += 1;
			else
				dp[i][j] -= dp[i + 1][j - 1];
		}
	}
	//printMatrix(dp);
	cout << dp[0][len - 1] << endl;
	system("pause");
	return 0;
}
