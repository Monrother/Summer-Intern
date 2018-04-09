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

int getans(long long h) {
	long long low = 0;
	long long high = h / 2;
	if (high > 10e9)
		high = 10e9;
	long long res;
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (mid * (mid + 1) == h)
			return mid;
		else if (mid * (mid + 1) < h) {//有可能是正确的
			low = mid + 1;
			res = mid;
		}
		else if (mid * (mid + 1) > h)
			high = mid - 1;
	}
	return res;
}

int main() {
	long long h;
	cin >> h;
	cout << getans(h) << endl;
	system("pause");
	return 0;
}