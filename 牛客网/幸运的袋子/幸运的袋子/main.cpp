#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> vec(n, 0);
	long long sum = 0;
	long long pro = 1;
	int count1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (vec[i] == 1)
			count1++;
	}
	


	system("pause");
	return 0;
}
