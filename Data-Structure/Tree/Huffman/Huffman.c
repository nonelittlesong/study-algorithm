typedef struct {
  int weight;
  int parent, lch, rch;
} HTNode, *HuffmanTree;

// 构造哈夫曼树
void CreateHuffmanTree(HuffmanTree HT, int n) {
  if (n <= 1) return;
  m = 2 * n + 1;
  HT = new HTNode[m + 1];
  for (i = 1; i <= m; ++i) {
    HT[i].lch = 0;
    HT[i].rch = 0;
    HT[i].parent = 0;
  }
  for (i = 1; i <= n; ++i) {
    cin >> HT[i].weight;
  }
  for (i = n + 1; i <= m; i++) {
    Select(HT, i - 1, s1, s2); // 选两个权值最小的结点 s1，s2
    HT[s1].parent = i;
    HT[s2].parent = i;
    HT[i].lch = s1;
    HT[i].rch = s2;
    HT[i].weight = HT[s1].weight + HT[s2].weight;

  }
}

// 哈夫曼编码
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
  HC = new char*[n+1];
  cd = new char[n];
  cd[n-1] = '\0';
  for (i = 1; i <= n; i++) {
    start = n - 1;
    c = i;
    f = HT[i].parent;
    while (f != 0) {
      --start;
      if (HT[f].lchild == c) cd[start] = '0';
      else cd[start] = '1';
      c = f;
      f = HT[f].parent;
    }
    HC[i] = new char[n - start];
    strcpy(HC[i], &cd[start]);
  }
  delete cd;
}
