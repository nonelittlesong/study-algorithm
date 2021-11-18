void get_nextval(SString T, int &nextval[]) {
  i = 1;
  nextval[1] = 0;
  j = 0;
  while (i < T.length) {
    if (j == 0 || T.ch[i] == T.ch[j]) {
      ++i;
      ++j;
      if (T.ch[i] != T.ch[j]) nextval[i] = j;
      else nextval[i] = nextval[j];
    }
    else j = nextval[j];
  }
}
