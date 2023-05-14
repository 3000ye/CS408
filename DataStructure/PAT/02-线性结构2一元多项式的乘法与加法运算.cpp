#include "bits/stdc++.h"
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
    return a.first > b.first;
}

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
            
            mul[e] += k;
        }
    }
    // 删除 0 项，按指数排序
    vector<pii> temp_mul(mul.begin(), mul.end()), res_mul;
    for (auto i : temp_mul) {
        if (i.second != 0) res_mul.push_back(i);
    }
    sort(res_mul.begin(), res_mul.end(), cmp);

    if (res_mul.size() == 0) cout << "0 0" << endl;
    else {
        for (int i = 0, l = res_mul.size(); i < l - 1; i ++) {
            cout << res_mul[i].second << " " << res_mul[i].first << " ";
        }
        cout << res_mul[res_mul.size() - 1].second << " " << res_mul[res_mul.size() - 1].first << endl;
    }

    // 加法，直接计算
    map<int, int> add;
    for (auto [e, k] : ls_a) add[e] += k;
    for (auto [e, k] : ls_b) add[e] += k;
    // 删除 0 项，按指数排序
    vector<pii> temp_add(add.begin(), add.end()), res_add;
    for (auto i : temp_add) {
        if (i.second != 0) res_add.push_back(i);
    }
    sort(res_add.begin(), res_add.end(), cmp);
    
    if (res_add.size() == 0) cout << "0 0" << endl;
    else {
        for (int i = 0, l = res_add.size(); i < l - 1; i ++) {
            cout << res_add[i].second << " " << res_add[i].first << " ";
        }
        cout << res_add[res_add.size() - 1].second << " " << res_add[res_add.size() - 1].first << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
