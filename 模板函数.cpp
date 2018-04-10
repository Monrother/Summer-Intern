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

// 求取一个矩阵的积分图
void initSumMatrix(vector<vector<int> > & sum, const vector<vector<int> >& matrix) {
	int m = matrix.size();
	for (int i = 0; i <= m; i++) {
	int n = matrix[0].size();
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				sum[i][j] = 0;
			else
				sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
		}
	}
}

// 获取子矩阵和
	// 获取左上角为x1, y1, 右下角为x2, y2的子矩阵的所有元素的和
int getSubMatrixSum(vector<vector<int> >& matrix, vector<vector<int> >& sum, int x1, int y1, int x2, int y2) {
	x2++;
	y2++;
	return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

// 输出向量
void printVector(const vector<int>& vec) {
	int m = vec.size();
	for (int i = 0; i < m; i++)
		cout << vec[i] << " ";
	cout << endl;
}

// 输出一个矩阵
template<class T>
void printMatrix(const vector<vector<T> >& matrix) {
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


// 整型转字符串
string int2str(int num) {
	string res;
	if (num == 0)
		res = "0";
	while (num != 0) {
		res = char(num % 10 + '0') + res;
		num /= 10;
	}
	return res;
}


// 判断一个字符串是否回文
bool isPalindrome(const string &s, int left = 0, int right = -1){
	// params:
	//	s: 要判断的字符串
	//	left: 子串的最左端字符的索引，如果没有设置为从字符串开头开始
	//	right: 子串的最右端字符的索引，如果没有设置为到字符串结尾
	if (right == -1){
		right = s.length() - 1;
	}
	while(left < right){
		if (s[left++] != s[right--])
			return false;
	}
	return true;
}


// 创建回文字符串矩阵
void Spread(const string &s, vector<vector<int>> &dp, int left, int right) {
	// 根据字符串s设置dp中的元素，执行完毕之后dp[i][j]为1表示s[i]到s[j]为回文字符串，dp[i][j]为0表示不是回文字符串。
	int len= s.length();
    while(left >= 0 && right < len){
        if(s[left]==s[right]){
            dp[left][right] = 1;
            left--;
            right++;
        }
        else
            break;
    }
}


void PalindromeMat(const string& s, vector<vector<int> >& dp) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        Spread(s, dp, i, i);
        Spread(s, dp, i, i + 1);
    }
}


int main() {

	system("pause");
	return 0;
}
