#include "bits/stdc++.h"
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct BiTNode {
    char val;
    BiTNode *l, *r;
    BiTNode(): val(0), l(nullptr), r(nullptr) {}
    BiTNode(char s): val(s), l(nullptr), r(nullptr) {}
    BiTNode(char s, BiTNode *l, BiTNode *r): val(s), l(l), r(r) {}
} BiTNode, *BiTree;

typedef struct {
    char s, l, r;
} node;

BiTree creatBiTree(vector<node> &ls, int idx) {
    if (idx >= ls.size()) return nullptr;

    BiTree newNode = new BiTNode(ls[idx].s);

    char l = ls[idx].l, r = ls[idx].r;
    if (l != '-') {
        int l_idx = l - '0';
        newNode->l = creatBiTree(ls, l_idx);
    }
    if (r != '-') {
        int r_idx = r - '0';
        newNode->r = creatBiTree(ls, r_idx);
    }

    return newNode;
}

void PreOrder(BiTree root, vector<char> &ls) {
    if (!root) return ;

    ls.push_back(root->val);
    PreOrder(root->l, ls);
    PreOrder(root->r, ls);
}

void solve() {
    int n; cin >> n;
    vector<node> ls_1;
    for (int i = 0; i < n; i ++) {
        char s, l, r; cin >> s >> l >> r;
        ls_1.push_back(node{s, l, r});
    }
    BiTree root_1 = creatBiTree(ls_1, 0);

    int m; cin >> m;
    vector<node> ls_2;
    for (int i = 0; i < m; i ++) {
        char s, l, r; cin >> s >> l >> r;
        ls_2.push_back(node{s, l, r});
    }
    BiTree root_2 = creatBiTree(ls_2, 0);

    vector<char> nodes_1, nodes_2;
    PreOrder(root_1, nodes_1);
    PreOrder(root_2, nodes_2);

    for (auto i : nodes_1) cout << i << " ";
    cout << endl;
    for (auto i : nodes_2) cout << i << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
