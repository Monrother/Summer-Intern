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

unordered_map<int, int> solve(vector<int> vec) {
	unordered_map<int, int> res;
	stack<int> st;
	if (vec.size() == 0)
		return res;
	st.push(0);
	for (int i = 1; i < vec.size(); i++) {
		while (!st.empty() && vec[i] > vec[st.top()]) {
			res[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	return res;
}


int main() {
	vector<int> vec{ 2,5,3,9,7 };
	stack<int> st;
	unordered_map<int, int> map;
	map = solve(vec);
	for (int i = 0; i < vec.size(); i++) {
		if (map.find(i) != map.end()) {
			cout << i << ":" << vec[i] << " " << map[i] << ":" << vec[map[i]] << endl;
			
		}
		else {
			cout << i << ":" << vec[i] << "没有更大的后续元素" << endl;
		}
	}
	system("pause");
	return 0;
}
