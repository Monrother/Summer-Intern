#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int check(string s, int a, int b, char c, char d, int x) {
	int sum = 0;
	if (a > 80 && x > 0)
		sum += 8000;
	if (a > 85 && b > 80)
		sum += 4000;
	if (a > 90)
		sum += 2000;
	if (a > 85 && d == 'Y')
		sum += 1000;
	if (b > 80 && c == 'Y')
		sum += 850;
	return sum;
}

int main() {
	int N;
	cin >> N;
	int max = 0;
	string name;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		string s;
		int a, b,x;
		char c, d;
		cin >> s >> a >> b >> c >> d >> x;
		int reward = check(s, a, b, c, d, x);
		if (reward > max) {
			max = reward;
			name = s;
		}
		sum += reward;
		//cout << s << " " << a << " " << b << " " << c << " " << d << " " << x << endl;
	}
	cout << name << endl << max << endl << sum << endl;
	//system("pause");
	return 0;
}
