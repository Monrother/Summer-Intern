#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

void printMatrix(const vector<vector<int> >& matrix) {
	int m = matrix.size();
	if (m == 0)
		return;
	int n = matrix[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void createMat(const unordered_set<int>& set, vector<vector<int> >& mat) {
	int N = 8 * sizeof(int);
	for (auto it : set) {
		vector<int> vec(N, 0);
		int flag = 1;
		for (int i = 0; i < N; i++) {
			vec[i] = bool(it & flag);
			flag <<= 1;
		} 
		mat.push_back(vec);
	}
}

int getNumOfPaints(vector<vector<int> >& mat) {
	int c;
	int r;
	int m = mat.size();
	int n = mat[0].size();
	for (c = 0, r = 0; r < m, c < n; r++, c++) {
		//cout << c << endl;
		// 找到第一个在c列上不是零的元素
		int i;
		for (i = r; i < m; i++) {
			if (mat[i][c] != 0)
				break;
		} 
		if (i == m)
			r--;
		else {
			swap(mat[i], mat[r]);
			for (int j = r + 1; j < m; j++) {	// 对这一列的每个元素进行判断
				if (mat[j][c] == 1) {
					for (int k = c; k < n; k++) {
						mat[j][k] ^= mat[r][k];
					}
				}
			}
		}
		//printMatrix(mat);
		//cout << endl;
	}
	return r;
}


int main() {
	int n;
	cin >> n;
	unordered_set<int> set;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		set.insert(x);
	}
	vector<vector<int> > mat;
	createMat(set, mat);
	//printMatrix(mat);
	cout << getNumOfPaints(mat) << endl;
	//printMatrix(mat);
	system("pause");
	return 0;
}
