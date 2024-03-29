void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
  pa = La->next;
  pb = Lb->next;
  pc = Lc = La;
  while (pa && pb) {
    if (pa->data <= pb->data) {
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    } else {
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }
  pc=>next = pa ? pa : pb;
  delete Lb;
}
