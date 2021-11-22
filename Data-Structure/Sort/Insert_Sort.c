/**
 * 插入排序
 * 1> 直接插入排序
 * 2> 二分插入排序
 * 3> 希尔排序
 */

/**
 * 直接插入排序 - 稳定
 */
void InsertSort(SqList &L) {
  int i, j;
  for (i = 2; i <= L.length; ++i) {
    if (L.r[i].key < L.r[i-1].key) {
      L.r[0] = L.r[i]; // 哨兵
      for (j = i - 1; L.r[0].key < L.r[j].key; --j) {
        L.r[j + 1] = L.r[j];
      }
      L.r[j + 1] = L.r[0];
    }
  }
}

/**
 * 折半插入排序 - 稳定
 */
void BInsertSort(SqList &L) {
  for (i = 2; i <= L.length; ++i) {
    L.r[0] = L.r[i]; // 哨兵
    low = 1;
    high = i - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (L.r[0].key < L.r[mid].key) high = mid - 1;
      else low = mid + 1;
    }
    for (j = i - 1; j >= high + 1; --j) L.r[j + 1] = L.r[j];
    L.r[high + 1] = L.r[0];
  }
}

/**
 * 希尔排序 - 不稳定
 * 1> 定义增量序列 Dk: Dm > Dm-1 > ... > D1=1
 * 2> 增量应为质数
 */
void ShellSort(SqList &L, int dlta[], int t) {
  // 按增量序列 dlta[0..t-1] 对顺序表 L 作希尔排序
  for (k = 0; k < t; ++k) {
    ShellInsert(L, dlta[k]);
  }
}
void ShellInsert(SqList &L, int dk) {
  for (i = dk + 1; i < = L.length; ++i) {
    if (r[i].key < r[i - dk].key) {
      r[0] = r[i];
      for (j = i - dk; j > 0 && r[0].key < r[j].key; j = j - dk) {
        r[j + dk] = r[j];
      }
      r[j + dk] = r[0];
    }
  }
}
