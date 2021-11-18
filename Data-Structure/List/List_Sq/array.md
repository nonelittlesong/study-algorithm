# 顺序表

- Array.java — Java 泛型线性表实现
- SeqList.hpp — C++ 模板类线性表实现
- ts — typescript 顺序表实现

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

## Tips

- `malloc(m)` — 开辟 m 字节长度的地址空间，并返回这段空间的首地址
  - new — cpp 动态存储分配
- `sizeof(x)` — 计算变量 x 的长度
- `free(p)` — stdlib.h, 释放指针 p 所指变量的存储空间，即彻底删除一个变量
  - delete — cpp 删除指针

