#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

string int2str(int num) {
	string res;
	if (num == 0)
		res = "0";
	while (num != 0) {
		res = char((num % 10) + '0') + res;
		num /= 10;
	}
	return res;
}

//
//bool isNum(char c) {
//	return c >= '0' && c <= '9';
//}
//
//bool isAlpha(char c) {
//	return c >= 'A' && c <= 'Z';
//}
//
//string solve1(string s) {
//	int c = to_int
//	string res;
//
//	return res;
//}
//
//string solve2(string s){
//	int sum = 0;
//	int i;
//	for (i = 0; !isNum(s[i]); i++) {
//		sum = sum * 26 + s[i] - 'A' + 1;
//	}
//
//	string res = "R" + to_string(sum) + "C" + s.substr(i);
//	return res;
//}
//



int main() {
	while (true) {
		int a;
		cin >> a;
		cout << int2str(a) << endl;
	}
	system("pause");
	return 0;
}
