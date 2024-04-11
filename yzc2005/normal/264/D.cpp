#include <bits/stdc++.h>
const int N = 1e6 + 5;
int n, m, c[3][3];
char s[N], t[N];
long long ans;
int id(char x) {return x == 'R' ? 0 : (x == 'G' ? 1 : 2);}
int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1), m = strlen(t + 1);
  for (int i = 1, l = 1, r = 1; i <= n; ++i) {
    auto upd = [&](int x, int v) {if (x <= m) c[id(t[x - 1])][id(t[x])] += v;};
    while (r < m && t[r] != s[i]) upd(++r, 1);
    ans += r - l + 1;
    if (i > 1 && s[i] != s[i - 1]) ans -= c[id(s[i])][id(s[i - 1])];
    if (l <= m && t[l] == s[i]) upd(++l, -1);
    if (r < m) upd(++r, 1);
  } 
  printf("%lld\n", ans);
  return 0;
}