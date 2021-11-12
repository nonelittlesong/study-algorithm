# 线性表

```
ADT List {
  D = {ai | ai 属于 Elemset, (i = 1, 2, ..., n, n >= 0)}
  R = {<ai-1, a1> | ai-1, ai 属于 D, (i = 2, 3, ..., n)}
  InitList(&L);
    操作结果: 构造一个空线性表 L
  DestroyList(&L);
    初始条件: 线性表 L 已存在
    操作结果: 将线性表 L 删除
  ClearList(&L)
    初始条件: 线性表 L 已存在
    操作结果: 将线性表 L 重置为空表
  ListEmpty(L)
    初始条件: 线性表 L 已存在
    操作结果: 若线性表 L 为空，则返回 ture，否则返回 false
  ListLength(L)
  GetElem(L, i, &e)
    初始条件: 1 <= i <= ListLength(L)
  LocateElem(L, e, compare())
  ListInsert(&L, i, e);
  ListDelete(&L, i, &e);
  ListTraverse(&L, visited())
  ...
} ADT List
```
