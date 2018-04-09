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

long long func(long long a, long long b, long long c) {
	return a * b + c;
}

int main() {
	vector<double> xy(2, 0);
	//for (int i = 0; i < 2; i++) {
		int n;
		cin >> n;
		vector<int> vec(n + 1, 0);
		for (int j = 0; j <= n; j++)
			cin >> vec[j];
		long long res = vec[n];
		long long temp = 1;
		cout << vec[n - 1] << res << temp;

		for (int j = n - 1; j >= 0; j--) {
			temp = res;
			res = func(vec[n-1], res, temp);
		}
		cout << res << " " << temp << endl;
	//}
	//cout << func(0, 3, 2) << endl;
	system("pause");
	return 0;
}