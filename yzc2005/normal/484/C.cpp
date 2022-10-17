#include <bits/stdc++.h>
const int N = 1e6 + 5;
int n, m, to[N], dif[N], tmp[N], cyc[N], res[N];
char s[N], t[N];
void mul(int *p, int *q) {
  for (int i = 0; i < n; ++i) tmp[i] = p[i];
  for (int i = 0; i < n; ++i) p[i] = tmp[q[i]];
}
int main() {
  scanf("%s", s), n = strlen(s), t[n] = '\0';
  for (int i = 0; i < n; ++i) cyc[i] = (i + 1) % n;
  for (scanf("%d", &m); m; --m) {
    int k, d; scanf("%d%d", &k, &d); 
    for (int i = 0, t = 0; i < d; ++i)
      for (int j = i; j < k; j += d) to[t++] = j;
    std::iota(to + k, to + n, k), std::iota(res, res + n, 0), mul(to, cyc);
    int o = n - k + 1;
    for (int b = o; b; b >>= 1, mul(to, to)) 
      if (b & 1) mul(res, to);    
    for (int i = 0; i < n; ++i) t[i] = s[res[i < o ? i + n - o : i - o]];
    printf("%s\n", t), memcpy(s, t, n * sizeof(char));
  }
  return 0;
}