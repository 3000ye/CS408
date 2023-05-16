#include "bits/stdc++.h"
#include <queue>
#include <vector>

using namespace std;

// 二叉树的结点（链式存储）
typedef struct BiTNode {
    int val;  // 数据域
    BiTNode *l, *r;  // 左孩子和右孩子
} BiTNode, *BiTree;

// 初始化二叉树
BiTree InitBiTree(int val) {
    BiTree root = new BiTNode;
    root->l = NULL; root->r = NULL;
    root->val = val;

    return root;
}

// 先序遍历
void PreOrder(BiTree root) {
    if (root != NULL) {
        cout << root->val << " ";  // 访问根结点
        PreOrder(root->l);  // 递归遍历左子树
        PreOrder(root->r);  // 递归遍历右子树
    }
}

// 中序遍历
void InOrder(BiTree root) {
    if (root != NULL) {
        PreOrder(root->l);  // 递归遍历左子树
        cout << root->val << " ";  // 访问根结点
        PreOrder(root->r);  // 递归遍历右子树
    }
}

// 后序遍历
void PostOrder(BiTree root) {
    if (root != NULL) {
        PreOrder(root->l);  // 递归遍历左子树
        PreOrder(root->r);  // 递归遍历右子树
        cout << root->val << " ";  // 访问根结点
    }
}

// 返回树的深度
int TreeDepth(BiTree root) {
    if (root == NULL) return 0;

    int l = TreeDepth(root->l);
    int r = TreeDepth(root->r);

    return l > r ? l + 1 : r + 1;
}

// 层序遍历
void LevelOrder(BiTree root, vector<int> &ls) {
    if (!root) return ;

    queue<BiTree> que;
    que.push(root);  // 根结点入队

    while (!que.empty()) {
        BiTree p = que.front();
        que.pop();  // 队头出队

        ls.push_back(p->val);  // 记录出队结点的值
        
        if (p->l) que.push(p->l);  // 左儿子入队
        if (p->r) que.push(p->r);  // 右儿子入队
    }
}

// 层序遍历，按层记录
void LevelOrderByLevel(BiTree root, vector<vector<int>> &ls) {
    if (!root) return ;

    queue<BiTree> que;
    que.push(root);

    while (!que.empty()) {
        int que_size = que.size();
        vector<int> temp;

        while (que_size -- ) {
            auto node = que.front(); que.pop();

            temp.push_back(node->val);
            if (node->l) que.push(node->l);
            if (node->r) que.push(node->r);
        }

        ls.push_back(temp);
    }
}

// 由前序和中序构造二叉树
BiTree BuildTree_PreIn(vector<int> pre, vector<int> in) {
    if (pre.empty()) return NULL;

    int root_val = pre[0];
    vector<int> lr(in.begin(), find(in.begin(), in.end(), root_val));
    vector<int> ll(pre.begin() + 1, pre.begin() + lr.size() + 1);
    vector<int> rl(pre.begin() + ll.size() + 1, pre.end());
    vector<int> rr(in.begin() + lr.size() + 1, in.end());

    BiTree root = InitBiTree(root_val);
    root->l = BuildTree_PreIn(ll, lr);
    root->r = BuildTree_PreIn(rl, rr);

    return root;
}

int main() {
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};

    BiTree root = BuildTree_PreIn(pre, in);
    vector<vector<int>> ls;
    LevelOrderByLevel(root, ls);

    for (auto i : ls) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }

    return 0;
}