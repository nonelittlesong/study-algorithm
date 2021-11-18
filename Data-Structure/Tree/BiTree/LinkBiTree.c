// 二叉链表存储结构
typedef struct BiNode {
  TElemType data;
  struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

// 三叉链表存储结构
typedef struct TriTNode {
  TElemType data;
  struct TriTNode *lchild, *parent, *rchild;
} TriTNode, *TriTree;

// 先序遍历
Status PreOrderTraverse(BiTree T) {
  if (T == NULL) return OK;
  else {
    visit(T);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
  }
}

// 中序遍历
Status InOrderTraverse(BiTree T) {
  if (T == NULL) return OK;
  else {
    InOrderTraverse(T->lchild);
    visit(T);
    InOrderTraverse(T->rchild);
  }
}
// 中序遍历非递归
Status InOrderTraverse2(BiTree) {
  BiTree T;
  InitStack(S);
  p = T;
  while (p || !StackEmpty(S)) {
    if (p) {
      Push(S, p);
      p = p->lchild;
    }
    else {
      Pop(S, q);
      printf("%c", q->data);
      p = q->rchild;
    }
  }
  return OK;
}

// 后序遍历
Status InOrderTraverse(BiTree T) {
  if (T == NULL) return OK;
  else {
    InOrderTraverse(T->lchild);
    InOrderTraverse(T->rchild);
    visit(T);
  }
}

// 层次遍历
typedef struct {
  BTNode data[MAXSIZE];
  int front, rear;
} SqQueue;

void LevelOrder(BTNode *b) {
  BTNode *p;
  SqQueue *qu;
  InitQueue(qu);
  enQueue(qu, b);
  while (!QueueEmpty(qu)) {
    deQueue(qu, p);
    printf("%c", p->data);
    if (p->lchild != NULL) enQueue(qu, p->lchild);
    if (p->rchild != NULL) enQueue(qu, p->rchild);
  }
}

// 创建 - 先序
Status CreateBiTree(BiTree &T) {
  scanf(&ch); // cin >> ch;
  if (ch == "#") T = NULL;
  else {
    if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) {
      exit(OVERFLOW);
    }
    T->data = ch;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
  }
  return OK;
}

// 复制 - 先序
int Copy(BiTree T, BiTree &NewT) {
  if (T == NULL) {
    NewT = NULL;
    return 0;
  } else {
    NewT = new BiTNode;
    NewT->data = T->data;
    Copy(T->lchild, NewT->lchild);
    Copy(T->rchild, NewT->rchild);
  }
}

// 深度
int Depth(BiTree T) {
  if (T == NULL) return 0;
  else {
    m = Depth(T->lchild);
    n = Depth(T->rchild);
    if (m > n) return m + 1;
    else return n + 1;
  }
}

// 结点数
int NodeCount(BiTree T) {
  if (T == NULL) return 0;
  else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

// 叶子节点数
int LeafCount(BiTree T) {
  if (T == NULL) return 0;
  if (T->lchild == NULL && T->rchild == NULL) return 1;
  else return LeafCount(T->lchild) + LeafCount(T->rchild);
}
