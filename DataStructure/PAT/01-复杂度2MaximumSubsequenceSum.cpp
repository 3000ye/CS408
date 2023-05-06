#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    ll res = -1, l = 0, r = n - 1;
    for (int i = 0; i < n; i ++) {
        ll temp = 0;

        for (int j = i; j < n; j ++) {
            temp += ls[j];

            if (res < temp) {
                res = temp, l = i, r = j;
            }
        }
    }

    if (res >= 0) cout << res << " " << ls[l] << " " << ls[r] << endl;
    else cout << "0 " << ls[0] << " " << ls[n - 1] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
