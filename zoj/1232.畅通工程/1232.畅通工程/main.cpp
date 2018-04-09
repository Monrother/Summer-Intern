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

int pre[1002];

int find(int x) {
	int r = x;
	// 先找到根节点
	while (pre[r] != r) {
		r = pre[r];
	}
	// 路径压缩
	int temp;
	while (pre[x] != r) {
		temp = pre[x];
		pre[x] = r;
	}
	return r;
}

void join(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
		pre[fy] = fx;
}

int main() {
	int N;
	int M;
	memset(pre, 0, 1002);
	while ((cin >> N >> M) && N != 0) {
		for (int i = 1; i <= N; i++) {
			pre[i] = i;
		}
		for (int i = 0; i < M; i++) {
			int s, d;
			cin >> s >> d;
			join(s, d);
		}
		for (int i = 1; i <= N; i++)
			cout << i << ": " << pre[i] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}