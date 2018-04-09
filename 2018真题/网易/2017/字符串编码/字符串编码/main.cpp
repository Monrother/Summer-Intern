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
	string str;
	string res;
	getline(cin, str);
	if (str.length() == 0) {
		cout << res << endl;
	}
	else {
		char last = str[0];
		int count = 1;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] == last) {
				count++;
			}
			else {
				res += to_string(count) + last;
				last = str[i];
				count = 1;
			}
		}
		res += to_string(count) + last;
		cout << res << endl;
	}
	system("pause");
	return 0;
}