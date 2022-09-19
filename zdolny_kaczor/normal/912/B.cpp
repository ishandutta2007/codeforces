# include <bits/stdc++.h>
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  if (k == 1)
    printf("%lld\n", n);
  else
    printf("%lld\n", ~(~0ll << (64 - __builtin_clzll(n))));
}