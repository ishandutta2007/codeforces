# include <bits/stdc++.h>
int s (int k) {
  return k * (k + 1) / 2;
}
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int n = a - b;
  if (n < 0)
    n = -n;
  int x = n / 2;
  printf("%d\n", s(x) + s(n - x));
}