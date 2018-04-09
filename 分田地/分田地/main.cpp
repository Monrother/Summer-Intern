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

typedef vector<vector<int> > mat;
typedef vector<int> vec;

int n;
int m;

// 求取一个矩阵的积分图
void initSumMatrix(vector<vector<int> > & sum, const vector<vector<int> >& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				sum[i][j] = 0;
			else
				sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
		}
	}
}

// 获取子矩阵和
int getSubMatrixSum(vector<vector<int> >& sum, int x1, int y1, int x2, int y2) {
	// 获取左上角为x1, y1, 右下角为x2, y2的子矩阵的所有元素的和
	x2++;
	y2++;
	return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

bool judge(mat& sum, int mid) {
	// 枚举竖切的三刀
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {
				int pre = -1;	// 横切的一种
				int count = 0;
				for (int p = 0; p < n; p++) {
					int area1 = getSubMatrixSum(sum, pre + 1, 0, p, i);
					int area2 = getSubMatrixSum(sum, pre + 1, i + 1, p, j);
					int area3 = getSubMatrixSum(sum, pre + 1, j + 1, p, k);
					int area4 = getSubMatrixSum(sum, pre + 1, k + 1, p, m - 1);
					if (area1 >= mid && area2 >= mid && area3 >= mid && area4 >= mid) {
						pre = p;
						count++;
						if (count == 4)
							return true;
					}
				}
			}
		}
	}
	return false;
}

//// 输出一个矩阵
//void printMatrix(const vector<vector<int> >& matrix) {
//	int m = matrix.size();
//	if (m == 0)
//		return;
//	int n = matrix[0].size();
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << matrix[i][j] << " ";
//		}
//		cout << endl;
//	}
//}


int divideLand(mat& sum) {
	int res = -1;
	int low = 0;
	int high = sum[n][m];
	while (low <= high) {
		int mid = (low + high) / 2;
		if (judge(sum, mid)) {
			low = mid + 1;
			res = mid;
		}
		else
			high = mid - 1;
	}
	return res;
}

int main() {
	cin >> n >> m;
	mat land(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++)
			land[i][j] = row[j] - '0';
	}
	mat sum(n + 1, vector<int>(m + 1, 0));
	initSumMatrix(sum, land);

	//printMatrix(sum);
	int res = divideLand(sum);
	cout << res << endl;
	system("pause");
	return 0;
}
