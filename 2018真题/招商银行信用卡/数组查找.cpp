#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 100000007;

typedef vector<int> vec;
typedef vector<vector<int>> mat;

template <class T> void printVector(const vector<T> &vec) {
    int m = vec.size();
    for (int i = 0; i < m; i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main() {
    // int temp = 7;
    vector<ll> vec;
    ll num;
    // for (int i = 0; i < temp; i++) cin >> vec[i];
    while (cin >> num) {
        vec.push_back(num);
    }
    int len = vec.size() - 2;
    int x = vec[len];
    int k = vec[len + 1];
    vec.pop_back();
    vec.pop_back();
    vector<ll> vec2(len, 0);
    int min_diff = 1001;
    int index = -1;
    for (int i = 0; i < len; i++) {
        vec2[i] = vec[i] - x;
        if (vec2[i] < 0)
            vec2[i] = -vec2[i];
        if (vec2[i] < min_diff) {
            min_diff = vec2[i];
            index = i;
        }
    }

    int left = index;
    int right = index;

    while (right - left + 1 < k) {
        if (left > 0 && right < len - 1) {
            if (vec2[left] <= vec2[right])
                left--;
            else
                right++;
        } else if (left == 0 && right < len - 1)
            right++;
        else if (right == len - 1 && left > 0)
            left--;
        else
            break;
    }

    cout << vec[left];
    for (int i = left + 1; i <= right; i++) {
        cout << " " << vec[i];
    }
    cout << endl;
    system("pause");
    return 0;
}
