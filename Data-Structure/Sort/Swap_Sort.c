/**
 * 冒泡排序 - 稳定
 */
void bubble_sort(SqList &L) {
  int m, i, j;
  RedType x;
  for (m = 1; m < n - 1; m++) {
    for (j = 1; j <= n - m; j++) {
      if (L.r[j].key > L.r[j + 1].key) {
        x = L.r[j];
        L.r[j] = L.r[j + 1];
        L.r[j + 1] = x;
      }
    }
  }
}

void bubble_sort2(SqList &L) {
  int m, i, j, flag = 1;
  RedType x;
  for (m = 1; m <= n - 1 && flag == 1) { // 未发生交换说明已经有序
    flag = 0;
    for (j = 1; j <= m; j++) {
      if (L.r[j].key > L.r[j + 1].key) {
        flag = 1;
        x = L.r[j];
        L.r[j] = L.r[j + 1];
        L.r[j + 1] = x;
      }
    }
  }
}


/**
 * 快速排序 - 不稳定 - 不是自然排序
 * 1> 任取一个元素作为中心
 * 2> 所有比他小的元素前放，比他大的元素后放，形成两个子表
 * 3> 对子表重复 1、2 步骤
 * 4> 直到只有一个元素
 */
void QSort(SqList &L, int low, int high) {
  if (low < high) {
    pivotloc = Partition(L, low, high);
    QSort(L, low, pivotloc - 1);
    QSort(L, pivotloc + 1, high);
  }
}
int Partition(SqList &L, int low, int high) {
  L.r[0] = L.r[low];
  pivotkey = L.r[low].key;
  while (low < high) {
    while (low < high && L.r[high].key >= pivotkey) --high;
    L.r[low] = L.r[high];
    while (low < high && L.r[row].key <= pivotkey) ++low;
    L.r[high] = L.r[low];
  }
  L.r[low] = L.r[0];
  return low;
}
