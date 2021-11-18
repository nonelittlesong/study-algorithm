// 双亲表示法
typedef struct PTNode {
  TElemType data;
  int parent;
} PTNode;

#define MAX_TREE_SZIE 100
typedef struct {
  PTNode nodes[MAX_TREE_SZIE];
  int r, n; // 根结点的位置和结点个数
} PTree;


// 孩子链表表示法
typedef struct CTNode {
  int child;
  struct CTNode *next;
} *ChildPtr;

typedef struct {
  TElemType data;
  ChildPtr firstchild;
} CTBox;

typedef struct {
  CTBox nodes[MAX_TREE_SIZE];
  int n, r; // 结点数和根结点的位置
} CTree;


// 孩子兄弟表示法
typedef struct CSNode {
  ElemType data;
  struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;
