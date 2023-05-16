#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct BiTNode {
    char val;
    BiTNode* l;
    BiTNode* r;
    BiTNode() : val(0), l(nullptr), r(nullptr) {}
    BiTNode(char s) : val(s), l(nullptr), r(nullptr) {}
    BiTNode(char s, BiTNode* l, BiTNode* r) : val(s), l(l), r(r) {}
};

BiTNode* createBinaryTree(vector<pair<char, pair<char, char>>>& nodes, int index) {
    if (index >= nodes.size() || nodes[index].first == '-')
        return nullptr;

    BiTNode* newNode = new BiTNode(nodes[index].first);

    char leftChild = nodes[index].second.first;
    if (leftChild != '-') {
        int leftChildIndex = leftChild - '0';
        newNode->l = createBinaryTree(nodes, leftChildIndex);
    }

    char rightChild = nodes[index].second.second;
    if (rightChild != '-') {
        int rightChildIndex = rightChild - '0';
        newNode->r = createBinaryTree(nodes, rightChildIndex);
    }

    return newNode;
}

BiTNode* buildBinaryTree(int nodeCount, vector<pair<char, pair<char, char>>>& nodes) {
    return createBinaryTree(nodes, 0);
}

int main() {
    int nodeCount;
    cin >> nodeCount;

    vector<pair<char, pair<char, char>>> nodes(nodeCount);
    map<char, bool> charMap;

    for (int i = 0; i < nodeCount; i++) {
        char value;
        char leftChild, rightChild;
        cin >> value >> leftChild >> rightChild;

        nodes[i] = make_pair(value, make_pair(leftChild, rightChild));
        charMap[value] = true;
    }

    BiTNode* root = buildBinaryTree(nodeCount, nodes);

    // 使用生成的二叉树进行操作

    return 0;
}
