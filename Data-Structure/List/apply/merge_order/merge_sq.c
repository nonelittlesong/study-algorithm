void MergeList_Sq(SqList LA, SqList LB, SqList &LC) {
  pa = LA.elem;
  pb = LB.elem;
  LC.length = LA.length + LB.length;
  LC.elem = new ElemType[LC.length];
  pc = LC.elem;
  pa_last = LA.elem + LA.length - 1;
  pb_last = LB.elem + LB.length - 1;

  while(pa <= pa_last && pb <= pb_last) {
    if (*pa <= *pb) *pc++ = *pa++;
    else *pc++ = *pb++;
  }

  while (pa <= pa_last) *pc++ = *pa++;
  while (pb <= pb_last) *pc++ = *pb++;
}
