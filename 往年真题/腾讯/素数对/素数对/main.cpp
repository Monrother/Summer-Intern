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

int getPrimes(int n, vector<pair<int,int> >& res ) {
	vector<bool> isPrime(n+1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i] == true) {
			for (int j = 2; i * j <= n; j++) {
				if (isPrime[i*j] == true)
					isPrime[i*j] = false;
			}
		}
	}
	unordered_set<int> primes;
	int count = 0;
	for (int i = 0; i <= n; i++) {
		if (isPrime[i] == true) {
			if (primes.find(n - i) != primes.end() || i * 2 == n) {
				count++;
				res.push_back(pair<int, int>{i, n-i});
			}
			else
				primes.insert(i);
		}
		
	}
	return count;
 }
 
void printVector(const vector<int>& vec) {
	int m = vec.size();
	for (int i = 0; i < m; i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main() {
	string str;	
	getline(cin, str);
	int pre = str.length() - 1;
	int post = str.length() - 1;
	for (pre = str.length() - 1; pre >= 0; pre--) {
		if (str[pre] >= 'A' && str[pre] <= 'Z') {
			char temp = str[pre];
			for (int i = pre; i < post; i++) {
				str[i] = str[i + 1];
			}
			//cout << str << endl;
			str[post--] = temp;
		}
	}
	cout << str << endl;
	system("pause");
	return 0;
}