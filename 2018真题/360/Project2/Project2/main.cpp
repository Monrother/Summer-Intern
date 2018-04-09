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
		int r, g, b;
		cin >> r >> g >> b;
		vector<int> vec{r,g,b};
		sort(vec.begin(), vec.end());
		if (vec[2] >= 2 * (vec[1] + vec[0]))
			cout << vec[0] + vec[1] << endl;
		else
			cout << (r+g+b) / 3 << endl;
	}
	system("pause");
	return 0;
}
