LinkList Connect(LinkList Ta, LinkList Tb) {
  p = Ta->next;
  Ta->next = Tb->next->next;
  delete Tb->next;
  Tb->next = p;
  return Tb;
}
