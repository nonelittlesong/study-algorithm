// 对称矩阵 - 一维数组存储

// 三角矩阵 - 一维数组存储

// 对角矩阵 - 二维数组存储

// 稀疏矩阵（t / m * n <= 0.05）- 十字链表
typedef struct {
  int row;
  int col;
  ElemType data;
  struct Node *right;
  struct Node *down;
} Node, *NodeP;

typedef struct {
  

} M_4_2;
