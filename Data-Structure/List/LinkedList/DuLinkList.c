// 双向链表
typedef struct DuLNode {
  Elemtype data;
  struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

