# include <bits/stdc++.h>
int main()  {
  int n;
  scanf("%d\n", &n);
  n++;
  printf("%lld\n", (1ll << n) - 2);
}