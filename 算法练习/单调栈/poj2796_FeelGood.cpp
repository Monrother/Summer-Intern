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

	system("pause");
	return 0;
}