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


ll solve(string str) {
	int len = str.length();
	vector<vector<ll> > dp(len, vector<ll>(len, 0));
	for (int j = 0; j < len; j++) {
		dp[j][j] = 1;
		for (int i = j - 1; i >= 0; i--) {
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
			if (str[i] == str[j])
				dp[i][j] += 1 + dp[i + 1][j - 1];
		}
	}
	return dp[0][len - 1];
}

int main() {
	string s;
	getline(cin, s);
	cout << solve(s) << endl;
	system("pause");
	return 0;
}