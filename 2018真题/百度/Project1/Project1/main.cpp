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
	getline(cin, str);
	int numw = 0, nume = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'W')
			numw++;
	}
	nume = 0;
	int wrong_sum = numw;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'W')
			numw--;
		else
			nume++;
		int sum = numw + nume;
		if (sum < wrong_sum)
			wrong_sum = sum;
	}
	cout << wrong_sum << endl;
	//system("pause");
	return 0;
}