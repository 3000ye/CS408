#include "bits/stdc++.h"
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100;
struct TreeNode {
    char val;
    int l, r;
} T1[N], T2[N];

int buildTree(struct TreeNode T[]) {
    int n; cin >> n;

    int root = -1, check[N];
    for (int i = 0; i < n; i ++) check[i] = 0;

    for (int i = 0; i < n; i ++) {
        char l, r; cin >> T[i].val >> l >> r;

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

    return root;
}

bool isomorphic(int r1, int r2) {
    if (r1 == -1 and r2 == -1) return true;
    if ((r1 == -1 and r2 != -1) or (r1 != -1 and r2 == -1)) return false;
    if (T1[r1].val != T2[r2].val) return false;
    if (T1[r1].l == -1 and T2[r2].l == -1) return isomorphic(T1[r1].r, T2[r2].r);
    
}

void solve() {
    


}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
