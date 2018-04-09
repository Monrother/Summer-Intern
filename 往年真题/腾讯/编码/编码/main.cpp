#include<iostream>
#include<string>
using namespace std;



int main() {
	string str;
	getline(cin, str);
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		
		num *= 27;
		if (i == 0) {
			num += (str[i] - 'a');
		}
		else
			num += (str[i] - 'a' + 1);

	}
	cout << num << endl;
	system("pause");
	return 0;
}
