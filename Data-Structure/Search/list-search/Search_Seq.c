/**
 * 顺序查找
 */

typedef struct {
  KeyType key; // 关键字域
  ...          // 其他域
}

typedef struct {
  ElemType *R;
  int length;
} SSTable;

SSTable ST;

// 顺序查找
int Search_Seq(SSTable ST, KeyType key) {
  for (i = ST.length; i >= 1; --i) {
    if (ST.R[i].key == key) return i;
  }
  return 0;
}
// 顺序查找 v2
int Search_Seq2(SSTable ST, KeyType key) {
  for (i = ST.length; ST.R[i].key != key; --i) {
    if (i <= 0) break;
  }
  if (i > 0) return i;
  else return 0;
}
// 顺序查找 v3
int Search_Seq3(SSTable ST, KeyType key) {
  for (i = ST.length; ST.R[i].key != key && i > 0; --i);
  if (i > 0) return i;
  else return 0;
}
// 顺序查找 v4 - 添加哨兵
int Search_Seq4(SSTable ST, KeyType key) {
  ST.R[0].key = key;
  for (i = ST.length; ST.R[i].key != key; --i);
  return i;
}
