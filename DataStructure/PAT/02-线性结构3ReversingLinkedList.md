# 02-线性结构3 Reversing Linked List

Given a constant $K$ and a singly linked list $L$, you are supposed to reverse the links of every $K$ elements on $L$.  For example, given $L$ being 1→2→3→4→5→6, if $K = 3$, then you must output 3→2→1→6→5→4; if $K = 4$, you must output 4→3→2→1→5→6.

## Input Specification:

Each input file contains one test case.  For each case, the first line contains the address of the first node, a positive $N$ ($\le 10^5$) which is the total number of nodes, and a positive $K$ ($\le N$) which is the length of the sublist to be reversed.  The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then $N$ lines follow, each describes a node in the format:
```ini
Address Data Next
```
where `Address` is the position of the node, `Data` is an integer, and `Next` is the position of the next node.

## Output Specification:

For each case, output the resulting ordered linked list.  Each node occupies a line, and is printed in the same format as in the input.

## Sample Input:
```in
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
```

## Sample Output:
```out
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
```

# 题解（`vector`模拟链表）

定义一个结构体，存储`Address Data Next`信息：

```cpp
typedef struct node{
    string add, next;
    int val;
} node;
```

使用`map`读入数据：

```cpp
// 读入数据
map<string, node> dic;
for (int i = 0; i < n; i ++) {
    string add, next; int val;
    cin >> add >> val >> next;

    dic[add] = node{add, next, val};
}
```

然后将数据按照链式顺序存入`vector`：

```cpp
// 存入 vector
vector<node> ls;
while (dic.count(head)) {
    node temp = dic[head];
    ls.push_back(temp);

    head = temp.next;
    if (head == "-1") break;
}
```

翻转`vector`，这里是最重要的部分。

我们按照`k`来分段，每一段都使用`reverse(ls.begin() + k * i, ls.begin() + k * (i + 1))`单独翻转。

翻转完成后，再逐个更新`next`，最后一个的`next`为`-1`：

```cpp
// 翻转数组
int x = ls.size() / k;
for (int i = 0; i < x; i ++) {
	reverse(ls.begin()+ k * i, ls.begin() + k * (i + 1));
}
// 更新 next 指针
for (int i = 0, l = ls.size(); i < l - 1; i ++) {
	ls[i].next = ls[i + 1].add;
}

ls[ls.size() - 1].next = "-1";
```

最后遍历输出即可，给出完整代码：

```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, string> pii;

typedef struct node{
    string add, next;
    int val;
} node;

void solve() {
    string head; int n, k; cin >> head >> n >> k;

    // 读入数据
    map<string, node> dic;
    for (int i = 0; i < n; i ++) {
        string add, next; int val;
        cin >> add >> val >> next;

        dic[add] = node{add, next, val};
    }

    // 存入 vector
    vector<node> ls;
    while (dic.count(head)) {
        node temp = dic[head];
        ls.push_back(temp);

        head = temp.next;
        if (head == "-1") break;
    }

    // 翻转数组
    int x = ls.size() / k;
    for (int i = 0; i < x; i ++) {
        reverse(ls.begin()+ k * i, ls.begin() + k * (i + 1));
    }
    // 更新 next 指针
    for (int i = 0, l = ls.size(); i < l - 1; i ++) {
        ls[i].next = ls[i + 1].add;
    }

    ls[ls.size() - 1].next = "-1";

    // 遍历输出
    for (auto i : ls) {
        cout << i.add << " " << i.val << " " << i.next << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

```

