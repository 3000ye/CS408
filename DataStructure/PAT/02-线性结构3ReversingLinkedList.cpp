#include "bits/stdc++.h"
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, string> pii;

typedef struct node{
    string add, next;
    int val;
} node;

void solve() {
    string head; int n, k; cin >> head >> n >> k;

    // 读入数据
    map<string, node> dic;
    for (int i = 0; i < n; i ++) {
        string add, next; int val;
        cin >> add >> val >> next;

        dic[add] = node{add, next, val};
    }

    // 存入 vector
    vector<node> ls;
    while (dic.count(head)) {
        node temp = dic[head];
        ls.push_back(temp);

        head = temp.next;
        if (head == "-1") break;
    }

    // 翻转数组
    int x = ls.size() / k;
    for (int i = 0; i < x; i ++) {
        reverse(ls.begin()+ k * i, ls.begin() + k * (i + 1));
    }
    // 更新 next 指针
    for (int i = 0, l = ls.size(); i < l - 1; i ++) {
        ls[i].next = ls[i + 1].add;
    }

    ls[ls.size() - 1].next = "-1";

    // 遍历输出
    for (auto i : ls) {
        cout << i.add << " " << i.val << " " << i.next << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
