#include "bits/stdc++.h"

using namespace std;

#define MaxVertexNum 100  // 最大顶点数设为100
#define INFINITY 65535  // 无穷大设为双字节无符号整数的最大值65535
typedef int Vertex, WeightType;  // 顶点下标，边的权值的数据类型为整型
typedef char DataType;  // 顶点存储的数据类型为字符型

// 边的定义
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;  // 有向边 <V1, V2>
    WeightType Weight;  // 权重
};
typedef PtrToENode Edge;

// 图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv, Ne;  // 顶点数，边数
    WeightType G[MaxVertexNum][MaxVertexNum];  // 邻接矩阵

    // 很多情况下，顶点无数据，即Data并不必须
    DataType Data[MaxVertexNum]  // 存顶点的数据
};
typedef PtrToGNode MGraph;  // 以邻接矩阵存储的图类型


MGraph CreateGraph(int VertexNum) {
    // 初始化一个有 VertexNum 个顶点但没有边的图
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));  // 建立图
    Graph -> Nv = VertexNum;
    Graph -> Ne = 0;

    for (V = 0; V < Graph -> Nv; V ++) {
        for (W = 0; W < Graph -> Nv; W ++) {
            Graph -> G[V][W] = INFINITY;
        }
    }

    return Graph;
}

int main() {


    return 0;
}