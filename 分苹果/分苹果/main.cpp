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

typedef vector<int> vecint;

int main() {
	int n;
	cin >> n;
	vecint vec(n, 0);
	int sum = 0;
	int parity = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		sum += vec[i];
		parity += vec[i] & 1;
	}
	if (sum % n != 0 || parity != 0 && parity != n) {
		cout << -1 << endl;
		return 0;
	}
	int mean = sum / n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (vec[i] > mean)
			count += (vec[i] - mean) / 2;
	}
	cout << count << endl;
	system("pause");
	return 0;
}