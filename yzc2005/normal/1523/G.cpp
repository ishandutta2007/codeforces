#include <bits/stdc++.h>
const int N = 100005, M = 2e7 + 5;
using pr = std::pair<int, int>;
int n, m, rt[N << 2], tot, min[M], ls[M], rs[M], ans[N];
std::vector<std::pair<pr, int>> segs[N];
pr tmp[N];
void insert(int &p, int l, int r, int pos, int val) {
  if (!p) min[p = ++tot] = val;
  else min[p] = std::min(min[p], val);
  if (l == r) return;
  int mid = l + r >> 1;
  if (mid >= pos) insert(ls[p], l, mid, pos, val);
  else insert(rs[p], mid + 1, r, pos, val);
}
void modify(int p, int l, int r, int pos, int x, int y) {
  insert(rt[p], 1, n, x, y);
  if (l == r) return; int mid = l + r >> 1;
  if (mid >= pos) modify(p << 1, l, mid, pos, x, y);
  else modify(p << 1 | 1, mid + 1, r, pos, x, y); 
}
int Query(int p, int l, int r, int ll, int rr) {
  if (!p) return int(1e9);
  if (l >= ll && r <= rr) return min[p];
  int mid = l + r >> 1;
  if (mid >= ll && mid < rr) return std::min(Query(ls[p], l, mid, ll, rr), Query(rs[p], mid + 1, r, ll, rr));
  if (mid >= ll) return Query(ls[p], l, mid, ll, rr);
  return Query(rs[p], mid + 1, r, ll, rr);
}
int query(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return Query(rt[p], 1, n, ll, rr);
  int mid = l + r >> 1;
  if (mid >= ll && mid < rr) return std::min(query(p << 1, l, mid, ll, rr), query(p << 1 | 1, mid + 1, r, ll, rr));
  if (mid >= ll) return query(p << 1, l, mid, ll, rr);
  return query(p << 1 | 1, mid + 1, r, ll, rr);
}
int solve(int l, int r) {
  int id = query(1, 1, n, l, r);
  if (id > m) return 0;
  int ll, rr; std::tie(ll, rr) = tmp[id];
  int ans = rr - ll + 1;
  if (ll > l) ans += solve(l, ll - 1);
  if (rr < r) ans += solve(rr + 1, r);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, l, r; i <= m; ++i) {
    scanf("%d%d", &l, &r), tmp[i] = {l, r};
    segs[r - l + 1].push_back({{l, r}, i});
  }
  for (int i = n; i; --i) {
    for (auto p : segs[i]) modify(1, 1, n, p.first.first, p.first.second, p.second);
    ans[i] = solve(1, n);
  }
  for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
  return 0;
}