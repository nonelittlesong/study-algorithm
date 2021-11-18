// 无向图邻接表 BFS
void BFS(Graph G, int v) {
  cout << v;
  visited[v] = true;
  InitQueue(Q, v);
  EnQueue(Q, v);
  while (!QueueEmpty(Q)) {
    DeQueue(Q, u);
    for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
      if (!visited[w]) {
        cout << w;
        visited[w] = true;
        EnQueue(Q, w);
      }
    }
  }
}
