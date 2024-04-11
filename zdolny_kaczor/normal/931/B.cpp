# include <bits/stdc++.h>
int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  a--;
  b--;
  int round = 0;
  while (a != b) {
    round++;
    a /= 2;
    b /= 2;
  }
  if ((1 << round) == n)
    printf("Final!\n");
  else
    printf("%d\n", round);
}