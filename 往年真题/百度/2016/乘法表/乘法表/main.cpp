#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

long long  solve(long long  n, long long  m, long long  k) {
	long long  l = 1;
	long long  r = k;
	while (l < r) {
		long long  mid = (l + r) / 2;
		long long  sum = 0;
		for (long long  i = 1; mid / i > 0 && i <= n; i++) {
			long long  temp = mid / i;
			if (temp > m)
				temp = m;
			sum += temp;
		}
		if (sum == k)
			return mid;
		else if (sum > k && mid > 1) {
			long long  mid2 = mid - 1;
			for (long long  i = 1; mid2 / i > 0 && i <= n; i++) {
				long long  temp = mid2 / i;
				if (temp > m)
					temp = m;
				sum += temp;
			}
			if (sum < k)
				return mid2;
			else
				r = mid2;
		}
		else if (sum < k) {
			l = mid + 1;
		}
	}
	
	return l;
}

int main() {
	long long  n, m, k;
	cin >> n >> m >> k;

	cout << solve(n, m, k) << endl;
	system("pause");
	return 0;
}
