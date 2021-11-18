// Brute-Force 字符串匹配算法

int Index_BF(SString S, SString T) {
  int i = 1, j = 1;
  while (i <= S.length && j <= T.length) {
    if (s.ch[i] == t.ch[j]) {
      ++i;
      ++j;
    } else {
      i = i - j + 2;
      j = 1;
    }
  }
  if (j > T.length) return i - T.length;
  else return 0;
}
