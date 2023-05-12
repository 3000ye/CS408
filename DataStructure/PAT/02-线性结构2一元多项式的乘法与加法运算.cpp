#include "bits/stdc++.h"
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    map<int, int> ls_a;
    for (int i = 0; i < n; i ++) {
        int k, e; cin >> k >> e;
        ls_a[e] = k;
    }
    int m; cin >> m;
    map<int, int> ls_b;
    for (int i = 0; i < m; i ++) {
        int k, e; cin >> k >> e;
        ls_b[e] = k;
    }

    // 乘法，使用双重循环计算
    map<int, int> mul;
    for (auto [e_a, k_a] : ls_a) {
        for (auto [e_b, k_b] : ls_b) {
            int e = e_a + e_b;
            int k = k_a * k_b;
            
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
