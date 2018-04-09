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

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<int> vec(n, 0);
		
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
		}
		int pre = vec[0];
		int count = 1;
		for (int i = 1; i < n; i++) {
			if (vec[i] > pre) {
				pre = vec[i];
				count++;
			}

		}
		cout << count << endl;
	}
	
	//system("pause");
	return 0;
}