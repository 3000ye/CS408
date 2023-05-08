#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N];

ll MaxSubseqSum1(int ls[], int n) {
    ll res = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            ll temp = 0;
            
            // k 循环中每次循环都要重复一次 [i, j - 1] 的加法
            // 因此，我们可以直接在 j 循环中取较大值
            for (int k = i; k <= j; k ++) temp += ls[k];
            res = max(res, temp);
        }
    }

    return res;
}

ll MaxSubseqSum2(int ls[], int n) {
    ll res = 0;
    for (int i = 1; i <= n; i ++) {
        ll temp = 0;
        for (int j = i; j <= n; j ++) {
            temp += ls[j];
            
            // 直接在 j 循环中取较大值
            res = max(res, temp);
        }
    }

    return res;
}

ll MaxSubseqSum3(int ls[], int l, int r) {
    ll MaxLeftSum, MaxRightSum;  // 存放左右子问题的解
    ll MaxLeftBorderSum = 0, MaxRightBorderSum = 0;  // 存放中间跨分界线的解

    if (l == r) {  // 终止条件
        if (ls[l] > 0) return ls[l];
        else return 0;
    }

    int mid = (l + r) >> 1;
    MaxLeftSum = MaxSubseqSum3(ls, l, mid);
    MaxRightSum = MaxSubseqSum3(ls, mid + 1, r);

    ll x = 0, y = 0;
    for (int i = mid; i >= l; i --) {
        x += ls[i];
        MaxLeftBorderSum = max(MaxLeftBorderSum, x);
    }

    for (int i = mid + 1; i <= r; i ++) {
        y += ls[i];
        MaxRightBorderSum = max(MaxRightBorderSum, y);
    }

    return max({MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum});
}

ll MaxSubseqSum4(int ls[], int n) {
    ll res  = 0, temp = 0;

    for (int i = 1; i <= n; i ++) {
        temp += ls[i];

        // 有点贪心的思想
        // 找每段不为零的子列和的最大值
        if (res < temp) res = temp;
        else if (temp < 0) temp = 0;
    }

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> ls[i];

    // 暴力做法
    ll res_1 = MaxSubseqSum1(ls, n);
    // 二维优化
    ll res_2 = MaxSubseqSum2(ls, n);
    // 分治优化
    ll res_3 = MaxSubseqSum3(ls, 1, n);
    // 贪心思想
    ll res_4 = MaxSubseqSum4(ls, n);

    cout << res_1 << endl << res_2 << endl << res_3 << endl << res_4 << endl;

    return 0;
}
