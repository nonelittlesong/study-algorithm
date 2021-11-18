#define MAXSIZE 100
typedef struct {
  SElemType *base;
  SelemType *top;
  int stacksize;
} SqStack;

// 初始化
Status InitStack(SqStack &S) {
  S.base = new SElemType[MAXSIZE];
  // S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
  if (!S.base) exit(OVERFLOW);
  S.top = S.base;
  S.stacksize = MAXSIZE;
  return OK;
}

// 判空
Status StackEmpty(SqStack S) {
  if (S.top == S.base) return TRUE;
  else return FALSE;
}

// 长度
int StackLength(SqStack S) {
  return S.top - S.base;
}

// 清空
Status ClearStack(SqStack S) {
  if (S.base) S.top = S.base;
  return OK;
}

// 销毁
Status DestroyStack(SqStack &S) {
  if (S.base) {
    delete S.base;
    S.stacksize = 0;
    S.base = S.top = NULL;
  }
  return OK;
}

// 入栈
Status Push(SqStack &S, SElemType e) {
  if (S.top - S.base == S.stacksize) retrun ERROR;
  *S.top++ = e;
  return OK;
}

// 出栈
Status Pop(SqStack &S, SElemType &e) {
  if (S.top == S.base) return ERROR;
  e = *--S.toop;
  return OK;
}
