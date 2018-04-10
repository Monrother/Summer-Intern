#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vec;
typedef vector<vector<int>> mat;

#define INT_MAX 2147483647

void Spread(const string& s, vector<vector<int> >& dp, int left, int right) {
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

void printVector(const vector<int>& vec) {
	int m = vec.size();
	for (int i = 0; i < m; i++)
		cout << vec[i] << " ";
	cout << endl;
}

class Solution {
private:
    void PalindromeMat(string& s, vector<vector<int>>& dp, int left, int right) {
        while(left >= 1 && right <= s.length()) {
            if (s[left-1] == s[right-1]){
                dp[left--][right++] = 1;
            }
            else
                break;
        }
    }
public:
    int minCut(string s) {
        int len = s.length();
        vector<vector<int>> mat(len+1, vector<int>(len+1, 0));
        for (int i = 1; i <= len; i++) {
            PalindromeMat(s, mat, i, i);
            PalindromeMat(s, mat, i, i+1);
        }
        // printMatrix(mat);
        // cout << endl;

        vector<int> min_segs(len+1, 0);
        for (int j = 1; j <= len; j++){
            int min_seg = INT_MAX;
            for (int i = 1; i <= j; i++) {
                if (mat[i][j] == 1){
                    int temp = min_segs[i-1] + 1;
                    if (temp < min_seg)
                        min_seg = temp;
                }
            }
            min_segs[j] = min_seg;
        }
        // printMatrix(mat);
        // cout << endl;
        int mincut = INT_MAX;
        for (int i = 1; i <=len;i++){
            if (mat[i][len] != 0 && mat[i][len] < mincut)
                mincut = mat[i][len];
        }
        // printVector(min_segs);
        return min_segs[len]-1;
    }
};

int main() {
    // // string s1 = "ABBA";
    // // string s2 = s1;
    // // cout << &s1 << endl;
    // // cout << &s2 << endl;
    // vector<int> v1{1,2,3,4};
    // vector<int> v2{1,2,3};

    // cout << &v1 << endl;
    // cout << &v2 << endl;
    // v1 = v2;
    // cout << &v1 << endl;
    string s = "aabbaacc";
    Solution solve;
    cout << solve.minCut(s) << endl;
    system("pause");
    return 0;
}
