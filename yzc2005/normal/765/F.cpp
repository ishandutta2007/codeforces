#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5, M = N << 5;

int n, m, a[N], ans[N * 3];
vector<pr> q1[N], q2[N];

int tot, rt[N], ls[M], rs[M], val[M];
void modify(int &p, int q, int l, int r, int pos, int val) {
  p = ++tot;
  ::val[p] = max(::val[q], val);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (mid >= pos) {
    rs[p] = rs[q];
    modify(ls[p], ls[q], l, mid, pos, val);
  } else {
    ls[p] = ls[q];
    modify(rs[p], rs[q], mid + 1, r, pos, val);
  }
}
int query(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return val[p];
  int mid = (l + r) >> 1, res = 0;
  if (mid >= ll && ls[p]) res = max(res, query(ls[p], l, mid, ll, rr));
  if (mid < rr) res = max(res, query(rs[p], mid + 1, r, ll, rr));
  return res;
}
inline void clear() {
  for (; tot; --tot)
    val[tot] = ls[tot] = rs[tot] = 0;
}

int c[N];
inline void modify(int p, int x) {
  for (; p <= n; p += p & -p) c[p] = min(c[p], x);
}
inline int query(int p) {
  int res = inf;
  for (; p; p -= p & -p) res = min(res, c[p]);
  return res;
}

void solve(vector<pr> *qry) {
  memset(c + 1, 0x3f, n * 4);  
  clear();
  for (int i = 1; i <= n; ++i) {
    modify(rt[i], rt[i - 1], 0, 1e9, a[i], i);
    int lef = 0, cur = i - 1;
    while (cur) {
      int pos = query(rt[cur], 0, 1e9, lef, a[i]);
      if (!pos) break;
      int val = a[pos];
      modify(n - pos + 1, a[i] - val);
      cur = pos - 1;
      if (lef == a[i]) break;
      lef = (lef + a[i] + 1) / 2;
    }
    for (auto p : qry[i]) {
      int l = p.first, it = p.second;
      ans[it] = min(ans[it], query(n - l + 1));
    }
  } 
}

int main() {
  scanf("%d", &n);
  memset(ans, 0x3f, sizeof ans);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int l, r; scanf("%d%d", &l, &r);
    q1[r].emplace_back(l, i);
    q2[n - l + 1].emplace_back(n - r + 1, i);
  }
  solve(q1);
  reverse(a + 1, a + n + 1);
  solve(q2);
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}