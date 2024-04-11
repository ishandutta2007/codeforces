#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, p[N], l[N], r[N], pre[N], suf[N]; 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 2; i <= n; ++i) 
    if (p[i] > p[i - 1]) l[i] = l[i - 1] + 1;
  for (int i = n - 1; i; --i)
    if (p[i] > p[i + 1]) r[i] = r[i + 1] + 1;
  int ans = 0;
  for (int i = 1; i <= n; ++i)   
    pre[i] = max(pre[i - 1], max(l[i], r[i]));
  for (int i = n; i; --i)
    suf[i] = max(suf[i + 1], max(l[i], r[i]));
  for (int i = 1; i <= n; ++i) {
    if (!l[i] || !r[i]) continue;
    int opt = max(pre[i - l[i] - 1], suf[i + r[i] + 1]);
    int a, b;
    tie(a, b) = minmax(l[i], r[i]);
    if (opt >= b) continue;
    if (a == b && (a % 2 == 0)) ++ans; 
  }
  printf("%d\n", ans);
  return 0;
}