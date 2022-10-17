#include <bits/stdc++.h>
const int N = 400005;
int n, a[N], b[N], id[N], c[N], p[N], fa[N], sz[N], sum[N];
bool tag[N * 2];
void fail() {puts("-1"), exit(0);}
int get(int x) {
  if (x == fa[x]) return x;
  return fa[x] = get(fa[x]);
}
void merge(int x, int y) {
  x = get(x), y = get(y);
  if (x == y) return;
  if (sz[x] < sz[y]) std::swap(x, y);
  fa[y] = x, sz[x] += sz[y];
}
int rev(int x) {return x <= n ? (x + n) : (x - n);}
std::vector<int> v[N];
void add(int p, int u) {
  for (; p <= n * 2; p += p & -p) v[p].emplace_back(u);
}
void apply(int p, int u) {
  for (; p; p -= p & -p) {
    if (v[p].empty()) continue; 
    for (auto x : v[p]) merge(u, rev(x)), merge(rev(u), x);
    v[p].clear(), v[p] = {rev(u)};
  }
}
int main() {
  scanf("%d", &n);
  std::iota(fa + 1, fa + n * 2 + 1, 1), std::fill(sz + 1, sz + n * 2 + 1, 1);
  int l = 0, r = 1e9;
  for (int i = 1; i <= n; ++i) {
    p[i] = i, scanf("%d%d", &a[i], &b[i]), id[i] = i;
    if (a[i] > b[i]) std::swap(a[i], b[i]), id[i] += n;
    l = std::max(l, a[i]), r = std::min(r, b[i]);
  }
  if (l > r) fail();
  std::sort(p + 1, p + n + 1, [&](int i, int j) {return a[i] < a[j];}); 
  for (int i = 1; i <= n; ++i) apply(b[p[i]], id[p[i]]), add(b[p[i]], id[p[i]]);
  for (int i = 1; i <= n; ++i) {
    if (get(i) == get(i + n)) fail();
    ++sum[get(i)];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x = get(i), y = get(i + n);
    if (tag[x] || tag[y]) continue;
    tag[x] = tag[y] = 1; 
    assert(std::min(sum[x], sz[x] - sum[x]) == std::min(sum[y], sz[y] - sum[y]));
    ans += std::min(sum[x], sz[x] - sum[x]);
  }
  printf("%d\n", ans);
  return 0;
}