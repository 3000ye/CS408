#include "bits/stdc++.h"
#include <vector>

using namespace std;

const int N = 20;
typedef struct {
    int idx, l, r;
} BiTree;

void solve() {
    BiTree T[N];
    int n; cin >> n;

    int root = -1, check[N] = {0};
    for (int i = 0; i < n; i ++) {
        char l, r; cin >> l >> r;

        T[i].idx = i;
        if (l != '-') {
            T[i].l = l - '0';
            check[T[i].l] = 1;
        }
        else T[i].l = -1;

        if (r != '-') {
            T[i].r = r - '0';
            check[T[i].r] = 1;
        }
        else T[i].r = -1;
    }

    for (int i = 0; i < n; i ++) {
        if (!check[i]) {root = i; break;}
    }

    queue<int> que;
    que.push(root);

    vector<int> res;
    while (!que.empty()) {
        int stk_size = que.size();

        while (stk_size -- ) {
            auto node = que.front(); que.pop();

            if (T[node].l != -1) que.push(T[node].l);
            if (T[node].r != -1) que.push(T[node].r);

            if (T[node].l == -1 and T[node].r == -1) res.push_back(T[node].idx);
        }
    }

    for (int i = 0, k = res.size(); i < k - 1; i ++) cout << res[i] << " ";
    cout << res[res.size() - 1] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}