typedef struct PNode {
  float coef;
  int expn;
  struct PNode *next;
}PNode, *Polynomial;

// 多项式创建
void CreatePolyn(Polynomial &P, int n) {
  P = new PNode;
  p->next = NULL;
  for (i = 1; i <= n; ++i) {
    s = new PNode;
    cin >> s->coef >> s->expn;
    pre = P;
    q = P->next;
    while (q && q->expn < s->expn) {
      pre = q;
      q = q-next;
    }
    s->next = q;
    pre->next = s;
  }
}
