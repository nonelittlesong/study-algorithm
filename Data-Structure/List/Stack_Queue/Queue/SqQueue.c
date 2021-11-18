#define MAXQSIZE 100
typedef struct {
  QElemType *base;
  int front;
  int rear;
} SqQueue;

// 初始化
Status InitQueue(SqQueue &Q) {
  Q.base = new QElemType[MAXQSIZE];
  // Q.base = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
  if (!Q.base) exit(OVERFLOW);
  Q.front = Q.rear = 0;
  return OK;
}

// 长度
int QueueLength(SqQueue Q) {
  return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

// 入队
Status EnQueue(SqQueue &Q, QElemType e) {
  if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;
  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MAXQSIZE;
  return OK;
}

// 出队
Status DeQueue(SqQueue &Q, QElemType &e) {
  if (Q.front == Q.rear) return ERROR;
  e = Q.base[Q.front];
  Q.front = (Q.front + 1) % MAXQSIZE;
  return OK;
}

// 获取队首元素
QElemType GetHead(SqQueue Q) {
  if (Q.front != Q.rear) return Q.base[Q.front];
}
