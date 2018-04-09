#include <iostream>
#include <string>
#include <vector>
//#include <unordered_map>
//#include <unordered_set>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> cows(N, 0);
	stack<int> s;
	long long nums = 0;
	for (int i = 0; i < N; i++) {
		cin >> cows[i];
		while (!s.empty() && cows[i] >= cows[s.top()]) {
			nums += i - s.top() - 1;
			s.pop();
		}
		s.push(i);
	}
	nums += (1 + s.size() - 1) * (s.size() - 1) / 2;
	cout << nums << endl;
	system("pause");
	return 0;
}
