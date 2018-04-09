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

int getnum(int l, int r) {
	int n1 = (l-1 )%3;
	int n2 = (r - 1) % 3;
	l = l - (l - 1) % 3;
	r = r + (3 - (r - 1) % 3);
	int count = (r - l+1) / 3*2;
	if (n1 == 2)
		count--;
	if (n2 == 1)
		count--;
	return count;
}

int main() {
	int l;
	int r;
	cin >> l >> r;
	cout << getnum(l, r) << endl;
	system("pause");
	return 0;
}