// 伪代码
typedef struct Lnode {
  ElemType data;
  struct Lnode *next;
} Lnode, *LinkList;

// 初始化
Status InitList_L(LinkList &L) {
  L = new LNode;
  // L = (LinkList) malloc(sizeof(LNode));
  L->next = NULL;
  return OK;
}

// 判空
int ListEmpty(LinkList L) {
  if (L->next) return 0;
  else return 1;
}

// 销毁
Status DestroyList_L(LinkList &L) {
  Lnode *p;
  while (L) {
    p = L;
    L = L->next;
    delete p;
  }
  return OK;
}

// 清空
Status ClearList(LinkList &L) {
  Lnode *p, *q;
  p = L-> next;
  while (p) {
    q = p->next;
    delete p;
    p = q;
  }
  L->next = NULL;
  return OK;
}

// 表长
int ListLength_L(LinkList L) {
  LinkList p;
  p = L->next;
  i = 0;
  while (p) {
    i++;
    p = p->next;
  }
  return i;
}

// 取值
Status GetElem_L(LinkList L, int i, ElemType &e) {
  p = L->next;
  j = 1;
  while (p && j < i) {
    p = p->next;
    ++j;
  }
  if (!p || j > i) return ERROR;
  e = p->data;
  return OK;
}

// 查找
Lnode* LocateElem_L(LinkList L, ElemType e) {
  p = L->next;
  while (p && p->data != e) {
    p = p->next;
  }
  return p;
}

int LocateElem_L(LinkList L, ElemType e) {
  p = L->next;
  j = 1;
  while (p && p->data != e) {
    p = p->next;
    j++;
  }
  if (p) return j;
  else return 0;
}

// 插入
Status ListInsert_L(LinkList &L, int i, ElemType e) {
  p = L;
  j = 0;
  while (p && j < i - 1) {
    p = p->next;
    ++j;
  }
  if (!p || j > i - 1) return ERROR;
  s = new LNode;
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

// 删除
Status ListDelete_L(LinkList &L, int i, ElemType &e) {
  p = L;
  j = 0;
  while (p->next && j < i - 1) {
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i - 1) return ERROR;
  q = p->next;
  p->next = q->next;
  e = q->data;
  delete q;
  return OK;
}

// 建立 - 头插法
void CreateList_H(LinkList &L, int n) {
  L = new LNode;
  L->next = NULL;
  for (i = n; i > 0; --i) {
    p = new LNode;
    cin >> p->data; // scanf(&p->data);
    p->next = L->next;
    L->next = p;
  }
}

// 建立 - 尾插法
void CreateList_R(LinkList &L, int n) {
  L = new LNode;
  L->next = NULL;
  r = L;
  for (i = 0; i < n; ++i) {
    p = new LNode;
    cin >> p->data;
    p->next = NULL;
    r->next = p;
    r = p;
  }
}