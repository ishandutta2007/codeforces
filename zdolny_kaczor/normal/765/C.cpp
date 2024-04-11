# include <bits/stdc++.h>
int main() {
  int a, b, k;
  scanf("%d%d%d", &k, &a, &b);
  if (a < k && b < k || (a < k && b % k) || (b < k && a % k))
    printf("-1\n");
  else
    printf("%d\n", a / k + b / k);
}