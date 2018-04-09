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

bool isPalindrome(string s){
	int len = s.length();
	for (int i = 0; i < s.length()/2;i++){
		if (s[i]!= s[len - 1-i])
			return false;
	}
	return true;
}

int main() {
	string s;
	int len = s.length();
	vector<vector<ll> > dp(len, vector<ll>(len, 0));
	for (int i = 0; i < len; i++)
		dp[i][i] = 1;
	for (int i = 0; i < len-1;i++){
		for(int j = i+1; j < len;j++){
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			if (isPalindrome(s.substr(i, j-1+1))
				dp[i][j]++;
		}
	}
	cout << dp[0][len-1]<<endl;
	system("pause");
	return 0;
}