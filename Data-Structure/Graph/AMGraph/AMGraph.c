// Adjacency Matrix Graph
#define MaxInt 32767     // 表示极大值
#define MVNum 100
typedef char VerTexType; // 顶点数据类型
typedef int ArcType;     // 边的权值类型

typedef struct {
  VerTexType vexs[MVNum];     // 顶点表
  ArcType arcs[MVNum][MVNum]; // 邻接矩阵
  int vexnum, arcnum; 
} AMGraph;

// 构造无向网
Status CreateUDN(AMGraph &G) {
  // 输入顶点和边的个数
  cin >> G.vexnum >> G.arcnum;
  // 输入顶点数据
  for (i = 0; i < G.vexnum; ++i) {
    cin >> G.vexs[i];
  }
  // 初始化邻接矩阵
  for (i = 0; i < G.vexnum; ++i) {
    for (j = 0; j < G.vexnum; ++j) {
      G.arcs[i][j] = MaxInt;
    }
  }
  // 构造
  for (k = 0; k < G.arcnum; ++k) {
    cin >> v1 >> v2 >> w;
    i = LocateVex(G, v1);
    j = LocateVex(G, v2);
    G.arcs[i][j] = w;
    G.arcs[j][i] = G.arcs[i][j];
  }
  return OK;
}

int LocateVex(AMGraph G, VerTexType u) {
  int i;
  for (i = 0; i < G.vexnum; ++i) {
    if (u == G.vexs[i]) return i;
  }
  return -1;
}
