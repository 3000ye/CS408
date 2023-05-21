#include "bits/stdc++.h"

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *l, *r;
} TreeNode, *BiTree;

// 插入元素
BiTree Insert(int x, BiTree root) {
    if (!root) {
        root = new TreeNode;
        root->val = x;
        root->l = NULL,  root->r = NULL;
    }
    else {
        if (x < root->val) root->l = Insert(x, root->l);
        else if (x > root->val) root->r = Insert(x, root->r);
    }

    return root;
}

// 返回先根序
void PreOrder(BiTree root, vector<int> &ls) {
    if (!root) return ;

    ls.push_back(root->val);
    PreOrder(root->l, ls);
    PreOrder(root->r, ls);
}

void solve() {
    int n;
    while (cin >> n and n != 0) {
        int l; cin >> l;
        BiTree root = NULL;
        for (int i = 0; i < n; i ++) {
            int k; cin >> k;
            root = Insert(k, root);
        }

        vector<int> ls;
        PreOrder(root, ls);

        while (l -- ) {
            BiTree temp = NULL;
            for (int i = 0; i < n; i ++) {
                int k; cin >> k;
                temp = Insert(k, temp);
            }

            vector<int> res;
            PreOrder(temp, res);

            int flag = 1;
            for (int i = 0; i < n; i ++) {
                if (ls[i] != res[i]) {flag = 0; break;}
            }

            flag ? cout << "Yes" << endl : cout << "No" << endl;
        }
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}