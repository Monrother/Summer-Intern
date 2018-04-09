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

bool testSubstr(const string& str1, const string& str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	if (len2 > len1)
		return false;
	int i1 = 0;
	int i2 = 0;
	while (i1 < len1 && i2 < len2) {
		if (str1[i1] == str2[i2])
			i2++;
		i1++;
	}
	if (i2 == len2)
		return true;
	return false;
}

int main() {
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	if (testSubstr(str1, str2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	system("pause");
	return 0;
}