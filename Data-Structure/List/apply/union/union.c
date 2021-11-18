void union(List &La, List Lb) {
  La_len = ListLength(La);
  Lb_len = ListLength(Lb);
  for (i = 1; i < Lb_Len; i++) {
    GetElem(Lb, i, e);
    if (!LocateElem(La, e)) ListInsert(&La, ++La_Len, e);
  }
}