/**
 * 二分查找
 */

int Search_Bin(SSTable ST, KeyType key) {
  low = 1;
  high = ST.length;
  while (low <= high) {
    mid = (low + high) / 2;
    if (ST.R[mid].key == key) return mid;
    else if (key < ST.R[mid].key) high = mid - 1;
    else low = mid + 1;
  }
  return 0;
}

// 二分查找 - 递归
int Search_Bin2(SSTable ST, KeyType key, int low, int high) {
  if (low > high) return 0;
  mid = (low + high) / 2;
  if (key == ST.R[mid].key) return mid;
  else if (key < ST.R[mid].key) Search_Bin2(ST, key, low, mid - 1);
  else Search_Bin2(ST, key, mid + 1, high);
}
