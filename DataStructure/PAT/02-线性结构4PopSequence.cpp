#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1010;
int ls[N];

// 栈中最大存储 M 个数，有 N 个数需要进栈和出栈
// 进栈和出栈操作可以交叉，判断出栈序列是否可能出现
void solve() {
    int m, n, k; cin >> m >> n >> k;
    while (k -- ) {
        for (int i = 0; i < n; i ++) cin >> ls[i];

        int idx = m, flag = 1;
        for (auto i : ls) {
            if (i > idx) {flag = 0; break;}

            idx = max(idx, i + 1);
        }

        flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
