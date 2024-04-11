#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, p[N], pos[N];
bool banned[N];
struct ST {
  int mx[N << 2], lazy[N << 2];
  inline void tag(int p, int x) {
    mx[p] += x;
    lazy[p] += x;
  }
  inline void pushdown(int p) {
    if (lazy[p]) {
      tag(p << 1, lazy[p]);
      tag(p << 1 | 1, lazy[p]);
      lazy[p] = 0;
    }
  }
  void build(int p, int l, int r) {
    mx[p] = -1e9;
    lazy[p] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
  }
  inline void pushup(int p) {
    mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
  }
  void modify(int p, int l, int r, int pos) {
    if (l == r) {
      mx[p] += 1e9 + n - l + 1;
      return;
    }  
    int mid = (l + r) >> 1;
    pushdown(p);
    if (mid >= pos) modify(p << 1, l, mid, pos);
    else modify(p << 1 | 1, mid + 1, r, pos);
    pushup(p);
  }
  void add(int p, int l, int r, int ll, int rr, int x) {
    if (l >= ll && r <= rr) {
      tag(p, x);
      return;
    }
    int mid = (l + r) >> 1;
    pushdown(p);
    if (mid >= ll) add(p << 1, l, mid, ll, rr, x);
    if (mid < rr) add(p << 1 | 1, mid + 1, r, ll, rr, x);
    pushup(p);
  }
  int query(int p, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) return mx[p];
    int mid = (l + r) >> 1, res = 0;
    pushdown(p);
    if (mid >= ll) res = max(res, query(p << 1, l, mid, ll, rr));
    if (mid < rr) res = max(res, query(p << 1 | 1, mid + 1, r, ll, rr));
    return res;
  }
} t[2];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &p[i]), pos[p[i]] = i;
  t[0].build(1, 1, n), t[1].build(1, 1, n);
  memset(banned + 1, false, n);
  int st = 1e9, ans = 0, rp = n;
  for (int i = n; i; --i) {
    int cur = pos[i];
    banned[cur] = true;
    while (rp >= 1 && banned[rp]) --rp;
    st = min(st, cur);
    bool type = cur & 1;
    t[type].modify(1, 1, n, cur);
    for (int k = 0; k < 2; ++k) {
      if (rp) t[k].add(1, 1, n, 1, min(cur, rp), -1);
      if (cur < n) t[k].add(1, 1, n, cur + 1, n, 1);
      if (st <= rp) {
        int res = t[k].query(1, 1, n, st, rp);
        if (res > 0 && !k) ++res;
        ans = max(ans, res);
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}