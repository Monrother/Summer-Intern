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

int n;

bool flag = false;

void printVector(const vector<int>& vec) {
	int m = vec.size();
	for (int i = 0; i < m; i++)
		cout << vec[i] << " ";
	cout << endl;
}

void dfs(int index, int k, vector<int>& cur_res, int cur_sum) {
	if (k == 0 && cur_sum == n) {
		printVector(cur_res);
		flag = true;
		return;
	}

	for (int i = index; i <= 10-k;i++){
		if (cur_sum + i <= n) {
			cur_sum += i;
			cur_res.push_back(i);
			dfs(i+1, k-1,cur_res,cur_sum);
			cur_sum -= i;
			cur_res.pop_back();
		}
		else
			return;
	}
}

int main() {
	int k;
	cin >> k >> n;
	int cur_sum = 0;
	vector<int> cur_res;
	dfs(1, k, cur_res, cur_sum);
	if (flag == false)
		cout << "None" << endl;
	system("pause");
	return 0;
}