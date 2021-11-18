typedef struct StackNode {
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStack;

LinkStack S;

// 初始化
void InitStack(LinkStack &S) {
  S = NULL;
  return OK;
}

// 判空
Status StackEmpty(LinkStack S) {
  if (S == NULL) return TRUE;
  else return FALSE;
}

// 入栈
Status Push(LinkStack &S, SElemType e) {
  p = new StackNode;
  p->data = e;
  p->next = S;
  S = p;
  return OK;
}

// 出栈
Status Pop(LinkStack &S, SElemType &e) {
  if (S == NULL) return ERROR;
  e = S->data;
  p = S;
  S = S->next;
  delete p;
  return OK;
}

// 取栈顶元素
SElemType GetTop(LinkStack) {
  if (S != NULL) return S->data;
}

