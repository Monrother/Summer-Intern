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

typedef unsigned long long ull;

int main() {
	/*ull temp = 0xffffffffffffffff;*/
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		ull num;
		cin >> num;
		bool flag = false;
		if (num % 2 == 1)
			cout << "No" << endl;
		else {
			ull base = 1;
			while (((num&1) == 0) &&(num >> 1) != 0) {
				base <<= 1;
				num >>= 1;
			}
			cout << num << " " << base << endl;
		}
	}
	//system("pause");
	return 0;
}