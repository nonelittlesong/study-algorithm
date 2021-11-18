// 双向链表
typedef struct DuLNode {
  Elemtype data;
  struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

// 插入
void ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
  if (!(p = GetElemP_DuL(L, i))) return ERROR;
  s = new DuLNode;
  s->data = e;
  s->prior = p->prior;
  p->prior->next = s;
  s->next = p;
  p->prior = s;
  return OK;
}

// 删除
void ListDelete_DuL(DuLinkList &L, int i, ElemType &e) {
  if (!(p = GetElemP_DuL(L, i))) return ERROR;
  e = p->data;
  p->prior->next = p->next;
  p->next->prior = p->prior;
  free(p);
  return OK;
}

