#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
	int N;
	int D;
	cin >> N >> D;
	vector<vector<int> > mat(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}
	int max = -numeric_limits<int>::infinity();
	int dp;
	// 横
	for (int i = 0; i < N; i++) {
		dp = 0;
		for (int j = 0; j < D; j++)	// 每一行的前D个数的和
			dp += mat[i][j];
		if (dp > max)
			max = dp;
		for (int j = D; j < N; j++) {
			dp = dp - mat[i][j - D] + mat[i][j];
			if (dp > max)
				max = dp;
		}
	}


	// 竖
	for (int j = 0; j < N; j++) {
		dp = 0;
		for (int i = 0; i < D; i++)
			dp += mat[i][j];
		if (dp > max)
			max = dp;
		for (int i = D; i < N; i++) {
			dp = dp - mat[i - D][j] + mat[i][j];
			if (dp > max)
				max = dp;
		}
	}

	 //左上右下
	for (int i = 0; i < 2 * (N - D) + 1; i++) {
		int r;
		int c;
		if (i <= N - D) {
			r = N - 1 - i;
			c = D - 1;
		}
		else {
			r = D - 1;
			c = i - N + 2 * D - 1;
		}
		dp = 0;
		for (int j = 0; j < D; j++)
			dp += mat[r - (D - 1) + j][c - (D - 1) + j];
		if (dp > max)
			max = dp;
		r++; 
		c++;
		while (r < N && c < N) {
			dp = dp - mat[r - D][c - D] + mat[r][c];
			if (dp > max)
				max = dp;
			r++;
			c++;
		}
	}
	// 右上左下
	for (int i = 0; i < 2 * (N - D) + 1; i++) {
		int r;
		int c;
		if (i <= N - D) {
			r = D - 1;
			c = i;
		}
		else {
			r = i + 2 * D - 1 - N;
			c = N - D;
		}
		dp = 0;
		for (int j = 0; j < D; j++)
			dp += mat[r - (D - 1) + j][c + (D - 1) - j];
		if (dp > max)
			max = dp;
		r++; 
		c--;
		while (r < N && c > 0) {
			dp = dp - mat[r - D][c + D] + mat[r][c];
			if (dp > max)
				max = dp;
			r++;
			c--;
		}
	}

	cout << max << endl;

	system("pause");
	return 0;
}