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

typedef vector<vector<long long> > mat;
typedef vector<long long> vec;

// 输出向量
void printVector(const vector<long long>& vec) {
	long long m = vec.size();
	for (long long i = 0; i < m; i++)
		cout << vec[i] << endl;
	//cout << endl;
}

// 输出一个矩阵
void printMatrix(const vector<vector<long long> >& matrix) {
	long long m = matrix.size();
	if (m == 0)
		return;
	long long n = matrix[0].size();
	for (long long i = 0; i < m; i++) {
		for (long long j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool myfunction(vector<long long> v1, vector<long long> v2)	{
	if (v1[1] < v2[1])
		return true;
	return false;
}

void printSet(unordered_set<int> set) {
	for (auto& x : set) 
		cout << x << " " ;
	cout << endl;
	
}

int main() {

	int N;
	int M;
	cin >> N >> M;

	mat jobs(N, vector<long long>(2, 0));
	vec p(M, 0);
	vector<long long> salary;

	for (long long i = 0; i < N; i++) 
		cin >> jobs[i][0] >> jobs[i][1];

	for (long long i = 0; i < M; i++)
		cin >> p[i];
	
	sort(jobs.begin(), jobs.end(), myfunction);
	
	unordered_set<int> donotchoose;
	// 肯定不会选择的工作
	for (long long i = N-2; i >= 0; i--) {
		if (jobs[i][0] >= jobs[i+1][0]) {
			donotchoose.insert(i);
		}
	}
	// 对每个人进行处理
	for (long long i = 0; i < M; i++) {
		int temp = salary.size();
		for (long long j = N - 1; j >= 0; j--) {
			if (donotchoose.find(j) != donotchoose.end())
				continue;
			if (jobs[j][0] <= p[i]) {
				salary.push_back(jobs[j][1]);
				break;
			}
		}
		if (salary.size() == temp)
			salary.push_back(0);
	}

	printVector(salary);
	//cout << "不会选择的工作";
	//printSet(donotchoose);
	//cout << "按照能力对工作排序："<< endl;
	//printMatrix(jobs);
	system("pause");
	return 0;
}
