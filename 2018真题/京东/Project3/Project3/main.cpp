#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;

typedef long long ll;
typedef vector<vector<long long> > matrix;
typedef set<pair<int, int> > pp;


vector<pair<int, int> > moves{ { 2,1 },{ 1,2 },{ 2,-1 },{ 1,-2 },{ -2,1 },{ -1,2 },{ -2,-1 },{ -1,-2 } };

bool checkValid(int X, int Y) {
	if (X >= 0 && X <= 9 && Y >= 0 && Y <= 9)
		return true;
	return false;
}


void update(matrix& mat, matrix& mat2, pp& cords, pp& cords2) {
	// 更新cords的8个点的值。
	for (auto it = cords.begin(); it != cords.end(); it++) {
		int X = it->first;
		int Y = it->second;

		for (int j = 0; j < 8; j++) {
			int newX = X + moves[j].first;
			int newY = Y + moves[j].second;
			if (checkValid(newX, newY)) {
				mat2[newX][newY] += mat[X][Y];
				cords2.insert(pair<int, int>{newX, newY});
			}
		}
	}
}

// 输出一个矩阵
void printMatrix(const vector<vector<long long> >& matrix) {
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

int main() {
	int K;
	cin >> K;
	int X, Y;
	cin >> X >> Y;
	vector<vector<long long> > mat = vector<vector<long long> >(10, vector<long long>(10, 0));
	mat[0][0] = 1;
	pp cords, cords2;
	cords.insert(pair<int, int>{0, 0});
	for (int i = 1; i <= K; i++) {
		vector<vector<long long> > mat2 = vector<vector<long long> >(10, vector<long long>(10, 0));
		pp cords2;
		update(mat, mat2, cords, cords2);
		mat = mat2;
		cords = cords2;
		cords2.clear();
		printMatrix(mat);
		cout << endl;
	}

	cout << mat[X][Y] << endl;
	system("pause");
	return 0;
}
