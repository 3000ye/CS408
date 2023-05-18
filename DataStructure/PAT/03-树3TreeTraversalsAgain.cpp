#include "bits/stdc++.h"
#include <memory>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *l, *r;
} TreeNode, *BiTree;

BiTree buildTree_pre_in(vector<int> pre, vector<int> in) {
    if (pre.empty()) return NULL;

    int root_val = pre[0];
    vector<int> l_in(in.begin(), find(in.begin(), in.end(), root_val));
    vector<int> l_pre(pre.begin() + 1, pre.begin() + 1 + l_in.size());
    vector<int> r_in(in.begin() + 1 + l_in.size(), in.end());
    vector<int> r_pre(pre.begin() + 1 + l_pre.size(), pre.end());

    BiTree root = new TreeNode;
    root->val = root_val;
    root->l = buildTree_pre_in(l_pre, l_in);
    root->r = buildTree_pre_in(r_pre, r_in);

    return root;
}

void GetPost(BiTree root, vector<int> &post) {
    if (!root) return;

    GetPost(root->l, post);
    GetPost(root->r, post);
    post.push_back(root->val);
}

// 可以从输入得到先根序和中根序
// 然后由这两个序列得到后根序
void solve() {
    int n; cin >> n;
    stack<int> stk;
    queue<int> que;

    // 得到先根序和中根序
    vector<int> pre, in;
    for (int i = 0; i < n * 2; i ++) {
        string op; cin >> op;
        if (op == "Push") {
            int k; cin >> k;
            stk.push(k);
            que.push(k);
        }
        else {
            in.push_back(stk.top());
            pre.push_back(que.front());
            
            stk.pop();
            que.pop();
        }
    }

    BiTree root = buildTree_pre_in(pre, in);
    vector<int> post;

    GetPost(root, post);
    for (int i = 0, k = post.size(); i < k - 1; i ++) cout << post[i] << " ";
    cout << post[post.size() - 1] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}