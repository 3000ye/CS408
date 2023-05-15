# 02-线性结构4 Pop Sequence

Given a stack which can keep $M$ numbers at most.  Push $N$ numbers in the order of 1, 2, 3, ..., $N$ and pop randomly.  You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.  For example, if $M$ is 5 and $N$ is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

## Input Specification:

Each input file contains one test case.  For each case, the first line contains 3 numbers (all no more than 1000): $M$ (the maximum capacity of the stack), $N$ (the length of push sequence), and $K$ (the number of pop sequences to be checked).  Then $K$ lines follow, each contains a pop sequence of $N$ numbers.  All the numbers in a line are separated by a space.

## Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

## Sample Input:
```in
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
```

## Sample Output:
```out
YES
NO
NO
YES
NO
```

# 题解（栈的思想）

## 题目翻译

栈中最大可以存储`M`个数，有`N`个数需要进栈和出栈。其中，入栈顺序必定为：`1, 2, ..., N`。

入栈和出栈操作可以交叉进行，现在给你一个序列，请你判断该序列是否可能为出栈序列。

## 题解思路

一个数`i`要出栈，则所有的`1, 2, ..., i - 1, i`都需要先入栈，即出栈的元素一定大于当前的栈顶元素。

所以我们可以逆向思维，维护一个栈`stk`来模拟入栈的元素，第一个入栈的元素为`1`。

令读入的序列为`ls`，遍历`ls`。当遍历到`ls[idx]`时，如果`ls[idx]`小于栈顶，则说明这个序列不可能为出栈序列。

如果`ls[idx]`小于栈顶，则一直入栈直到`ls[idx]`等于栈顶。**注意： **此时需要判断栈的长度是否已经超过`M`，如果是则也不可能。

如果`ls[idx]`等于栈顶，则栈将栈顶弹出。如果一直弹出到空栈，则栈自动入栈一个后继元素。

## 代码实现

```cpp
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

```



