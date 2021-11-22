/**
 * 二叉排序树
 */

typedef struct {
  KeyType key;
  InfoType otherinfo;
} ElemType;

typedef struct BSTNode {
  ElemType data;
  struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTree T;

// 二叉排序树的递归算法
BSTree SearchBST(BSTree T, KeyType key) {
  if (!T || key == T->data.key) return T;
  else if (key < T->data.key) return SearchBST(T->lchild, key);
  else return SearchBST(T->rchild, key);
}

// 插入

// 生成


/**
 * 删除
 * 1> 叶子结点，直接删除
 * 2> 只有左/右子树，直接用左/右子树替换
 * 3> 有两个子树，用前驱结点替换，再删除前驱结点（后继亦然）
 */
