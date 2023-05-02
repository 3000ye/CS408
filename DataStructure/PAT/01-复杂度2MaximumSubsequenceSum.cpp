#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> ls[i];

    ll res = 0;
    int l, r;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            ll temp = 0;
            for (int k = i; k <= j; k ++) temp += ls[k];

            if (temp > res) {
                l = i, r = j;
                res = temp;
            }
        }
    }

    for (int i = l; i <= r; i ++) cout << ls[i] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
