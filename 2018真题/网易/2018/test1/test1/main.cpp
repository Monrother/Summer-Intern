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

int function(int n, unordered_map<int, int>& map, vector<int>& mass) {
	vector<int> scores(4, 0);
	for (int i = 0; i < 4; i++) {
		if (map[mass[i]] != 0) {
			int new_n = (n + mass[i]) % 10;
			map[mass[i]]--;
			scores[i] = n * mass[i];
			scores[i] += function(new_n, map, mass);
			map[mass[i]]++;
		}
	}
	int max = 0;
	for (int i = 0; i < 4; i++) {
		if (scores[i] > max)
			max = scores[i];
	}
	return max;
}


int main() {
	vector<int> nums(4, 0);
	vector<int> mass(4, 0);
	unordered_map<int, int> map;
	for (int i = 0; i < 4; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < 4; i++)
		cin >> mass[i];

	for (int i = 0; i < 4; i++) 
		map[mass[i]] = nums[i];
	cout << function(0, map, mass) << endl;
	//int sum = 0;
	//int total_mass = 0;
	//int total_num = 0;
	//for (int i = 0; i < 4; i++) {
	//	map[mass[i]] = nums[i];
	//	total_mass += nums[i] * mass[i];
	//	total_num += nums[i];
	//}
	//vector<int> balls;
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < nums[i]; j++) {
	//		balls.push_back(mass[i]);
	//	}
	//}
	//vector<int> scores(total_num, 0);
	//vector<int> remain_mass(4, total_mass);
	//vector<unordered_map<int, int> > remain_balls(4, map);
	//vector<vector<bool> > used(total_num, vector<bool>(total_num, false));
	//for (int i = 0; i < 4; i++) {
	//	remain_mass[i] -= mass[i];
	//	int last_digit = remain_mass[i] % 10;
	//	scores[i] += last_digit * mass[i];
	//	remain_balls[i][i]--;
	//	// 根据当前剩的球和选择一个使结果最大的放进去。
	//}
	system("pause");
	return 0;
}