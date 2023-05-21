#include "bits/stdc++.h"

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *l, *r;
} TreeNode, *BiTree;

// 递归实现：二叉搜索树中查找函数
BiTree PositionFind(int x, BiTree root) {
    if (!root) return NULL;
    if (x > root->val) return PositionFind(x, root->r);
    else if (x < root->val) return PositionFind(x, root->l);
    else return root;
}

// 迭代实现：二叉搜索树中查找函数
BiTree PositionFind2(int x, BiTree root) {
    while (root) {
        if (x > root->val) root = root->r;
        else if (x < root->val) root = root->l;
        else return root;
    }

    return root;
}

// 查找最小值
BiTree FindMin(BiTree root) {
    if (!root) return NULL;
    else if (!root->l) return root;
    else return FindMin(root->l);
}

// 查找最大值
BiTree FindMax(BiTree root) {
    if (!root) return NULL;
    else if (!root->r) return root;
    else return FindMax(root->r);
}

// 插入元素
BiTree Insert(int x, BiTree root) {
    if (!root) {
        root = new TreeNode;
        root->val = x;
        root->l = root->r = NULL;
    }
    else {
        if (x < root->val) root->l = Insert(x, root->l);
        else if (x > root->val) root->r = Insert(x, root->r);

        // 如果相等的话则什么都不做
    }

    return root;
}

// 删除元素
BiTree Delete(int x, BiTree root) {
    if (!root) cout << "要删除的元素未找到" << endl;
    else if (x < root->val) root->l = Delete(x, root->l);
    else if (x > root->val) root->r = Delete(x, root->r);
    else { // 找到了
        BiTree temp;

        if (root->l and root->r) {
            temp = FindMin(root->r);
            root->val = temp->val;
            root->r = Delete(root->val, root->r);
        }
        else {
            temp = root;
            if (!root->l) root = root->r;
            else if (!root->r) root = root->l;
            
            free(temp);
        }
    }

    return root;
}

int main() {


    return 0;
}