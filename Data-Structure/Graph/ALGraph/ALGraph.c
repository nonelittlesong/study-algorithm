// 邻接表

typedef struct VNode {
  VerTexType data;
  ArcNode *firstarc;
} VNode, AdjList[MVNum]; // AgjList v; 相当于 VNode v[MNNum];

#define MVNum 100
typedef struct ArcNode {
  int adjvex;
  struct ArcNode *nextarc;
  OtherInfo info;
} ArcNode;

typedef struct {
  AdjList vertices;
  int vexnum, arcnum;
} ALGraph;

// 创建无向网
Status CreateUDG(ALGraph &G) {
  cin >> G.vexnum >> G.arcnum;
  for (i = 0; i < G.vexnum; ++i) {
    cin >> G.vertices[i].data;
    G.vertices[i].firstarc = NULL;
  }
  for (k = 0; k < G.arcnum; ++k) {
    cin >> v1 >> v2;
    i = LocateVex(G, v1);
    j = LocateVex(G, v2);
    p1 = new ArcNode;
    p1->adjvex = j;
    p1->nextarc = G.vertices[i].firstarc; // 头插法
    G.vertices[i].firstarc = p1;
    p2 = new ArcNode;
    p2->adjvex = i;
    p2->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p2;
  }
  return OK;
}
