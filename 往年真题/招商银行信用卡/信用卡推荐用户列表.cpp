#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const ll mod = 100000007;

typedef vector<int> vec;
typedef vector<vector<int>> mat;

struct user {
    char name;
    user *parent = NULL;
    int recommend = 0;
    user(char c, user *p = NULL, int r = 0) {
        name = c;
        parent = p;
        recommend = r;
    }
};

bool flag = false;

int main() {
    int m, n;
    cin >> m >> n;
    unordered_map<char, user *> map;
    for (int i = 0; i < m; i++) {
        char parent;
        char child1, child2;
        cin >> parent >> child1 >> child2;
        user *up;
        user *uc1;
        user *uc2;
        if (map.find(parent) != map.end())
            up = map[parent];
        else {
            up = new user(parent);
            map[parent] = up;
        }
        if (map.find(child1) != map.end())
            uc1 = map[child1];
        else {
            uc1 = new user(child1, up);
            map[child1] = uc1;
        }

        user *temp = up;
        while (temp) {
            temp->recommend++;
            temp = temp->parent;
        }

        map[child1] = uc1;

        if (child2 != '*') {
            if (map.find(child2) != map.end())
                uc2 = map[child2];
            else {
                uc2 = new user(child2, up);
                user *temp = up;
                while (temp) {
                    temp->parent->recommend++;
                    temp = temp->parent;
                }
                map[child2] = uc2;
            }
        }
    }
    bool flag2 = false;
    for (auto &it : map) {  // 遍历unordered_map的方法

        user *temp = it.second;
        // cout << temp->name << " ";
        // if (temp->parent){
        //     cout << temp->parent->name << " ";
        // }
        // cout << temp->recommend << endl;
        if (temp->recommend >= n) {
            flag = true;
            if (flag2) {
                cout << " ";
            }
            flag2 = true;
            cout << temp->name;
        }
    }
    if (flag == false) cout << "None";
    cout << endl;
    system("pause");
    return 0;
}
