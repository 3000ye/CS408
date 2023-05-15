#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1010;
int ls[N];

typedef struct {
    int ls[N];
    int top;
} Stack;

// 栈中最大存储 M 个数，有 N 个数需要进栈和出栈
// 进栈和出栈操作可以交叉，判断出栈序列是否可能出现
void solve() {
    int m, n, k; cin >> m >> n >> k;
    while (k -- ) {
        for (int i = 0; i < n; i ++) cin >> ls[i];

        // 初始化栈
        Stack stk; int x = 1;
        stk.top = 0;
        stk.ls[stk.top] = x;

        int flag = 1;
        for (int i = 0; i < n; i ++) {
            // 如果 ls[i] 小于栈顶元素，则说明不可能
            if (ls[i] < stk.ls[stk.top]) {
                flag = 0;
                break;
            }
            // 如果 ls[i] 大于栈顶元素，则一直进栈到和 ls[i] 相等
            while (ls[i] > stk.ls[stk.top]) {
                stk.ls[++ stk.top] = ++ x;
            }
            // 如果栈的长度超过 M 了，则也不可能
            if (stk.top >= m) {flag = 0; break;}
            // 如果 ls[i] 和栈顶元素相等，则弹出栈顶
            if (ls[i] == stk.ls[stk.top]) {
                stk.top --;
            }
            // 如果栈为空了，则自动入栈一个
            if (stk.top < 0) stk.ls[++stk.top] = ++ x;
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
