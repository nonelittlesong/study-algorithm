/**
 * 选择排序 - 不稳定
 */
void SelectSort(SqList &L) {
  for (i = 1;  i < L.length; ++i) {
    k = i;
    for (j = i + 1; j <= L.length; j++) {
      if (L.r[j].key < L.r[k].key) k = j;
    }
    if (k != i) {
      x = L.r[i];
      L.r[i] = L.r[k];
      L.r[k] = x;
    }
  }
}

/**
 * 堆排序 - 不稳定
 * 堆：完全二叉树中任一非叶子结点均小于（大于）他的孩子结点、
 * 1> 如何将一个无序序列建成一个堆
 * 2> 如何在输出堆顶元素后，调整剩余元素为一个新的堆
 */
void HeapAdjust(elem R[], int s, int m) {
  // 已知 R[s..m] 中记录的关键字除 R[s] 之外均满足堆的定义，
  // 本函数调整 R[s] 的关键字，使 R[s..m] 成为一个大根堆
  rc = R[s];
  for (j = 2 * s; j <= m; j *= 2) {
    if (j < m && R[j] < R[j + 1]) ++j;
    if (rc >= R[j]) break;
    R[s] = R[j];
    s = j;
  }
  R[s] = rc;
}

void HeapSort(elem R[]) {
  int i;
  for (1 = n / 2; i >= 1; i--) HeapAdjust(R, i, n);
  for (i = n; i > 1; i--) {
    Swap(R[1], R[i]);
    HeapAdjust(R, 1, i - 1);
  }
}
