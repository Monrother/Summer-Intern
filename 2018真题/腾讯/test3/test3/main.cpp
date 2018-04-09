#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& vec) {
	int n = vec.size();
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i-1; j++) {
			if (vec[j] > vec[j + 1]) {
				int temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
				count++;
			}
		}
	}
	cout << count << endl;
}

int main() {
	vector<int> vec{ 5,4,7,1,6,2 };
	bubbleSort(vec);
	for (int i = 0; i < 6; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
