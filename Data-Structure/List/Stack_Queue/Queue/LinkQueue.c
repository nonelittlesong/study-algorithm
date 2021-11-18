#define MAXQSIZE 100;
typedef struct Qnode {
  QElemType data;
  struct Qnode *next;
} QNode, *QuenePtr;

typedef struct {
  QuenePtr front;
  QuenePtr rear;
} LinkQueue;

// 初始化
Status InitQueue(LinkQueue &Q) {
  Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
  if(!Q.front) exit(OVERFLOW);
  Q.front->next = NULL;
  return OK;
}

// 销毁
Status DestroyQueue(LinkQueue &Q) {
  while (Q.front) {
    // Q.rear = Q.front->next; free(Q.front); Q.front = Q.rear;
    p = Q.front->next;
    free(Q.front);
    Q.front = p;
  }
  return OK;
}

// 入队
Status EnQueue(LinkQueue &Q, QElemType e) {
  p = (QueuePtr)malloc(sizeof(QNode));
  if (!p) exit(OVERFLOW);
  p->data = e;
  p->next = NULL;
  Q.rear->next = p;
  Q.rear = p;
  return OK;
}

// 出队
Status DeQueue(LinkQueue &Q, QElemType &e) {
  if (Q.front == Q.rear) return ERROR;
  p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;
  // 注意，为空时，头尾指针都指向头结点
  if (Q.rear == p) Q.rear = Q.front;
  delete p;
  return OK;
}

// 返回队首元素
Status GetHead(LinkQueue Q, QElemType &e) {
  if (Q.front == Q.rear) return ERROR;
  e = Q.front->next->data;
  return OK;
}
