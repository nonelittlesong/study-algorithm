// 无向图邻接矩阵深度优先遍历
void DFS(AMGraph G, int v) {
  cout << v;
  visited[v] = true;
  for (w = 0; w < G.vexnum; w++) {
    if (G.arcs[v][w] != 0 && !visited[w]) {
      DFS(G, w);
    }
  }
}
