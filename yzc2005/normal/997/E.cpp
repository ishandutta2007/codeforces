#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
const int N = 120005;
struct SegmentTree {
  int l[N << 2], r[N << 2];
  int val[N << 2], cnt[N << 2], lzy[N << 2], tim[N << 2];
  long long ans[N << 2]; 
  #define mid (l[p] + r[p] >> 1)
  #define ls p << 1
  #define rs p << 1 | 1
  void build(int p, int L, int R) {
    l[p] = L;
    r[p] = R;
    val[p] = L;
    cnt[p] = 1;
    if (L == R) {
      return;
    }
    build(ls, L, mid);
    build(rs, mid + 1, R);
  }
  inline void pushup(int p) {
    val[p] = min(val[ls], val[rs]);
    cnt[p] = (val[p] == val[ls]) * cnt[ls] + (val[p] == val[rs]) * cnt[rs];
    ans[p] = ans[ls] + ans[rs];
  }
  inline void tagval(int p, int v) {
    val[p] += v;
    lzy[p] += v;
  }
  inline void tagtim(int p, int delta) {
    tim[p] += delta;
    ans[p] += 1ll * cnt[p] * delta;
  }
  inline void pushdown(int p) {
    if (lzy[p]) {
      tagval(ls, lzy[p]);
      tagval(rs, lzy[p]);
      lzy[p] = 0;
    }
    if (tim[p]) {
      if (val[p] == val[ls]) {
        tagtim(ls, tim[p]);
      }
      if (val[p] == val[rs]) {
        tagtim(rs, tim[p]);
      }
      tim[p] = 0;
    }
  }
  void modify(int p, int L, int R, int v) {
    if (L <= l[p] && r[p] <= R) {
      return tagval(p, v);
    }
    pushdown(p);
    if (mid >= L) {
      modify(ls, L, R, v);
    } 
    if (mid < R) {
      modify(rs, L, R, v);
    }
    pushup(p);
  }
  long long query(int p, int L, int R) {
    if (L <= l[p] && r[p] <= R) {
      return ans[p];
    }
    pushdown(p);
    long long res = 0;
    if (mid >= L) {
      res += query(ls, L, R);
    }
    if (mid < R) {
      res += query(rs, L, R);
    }
    return res;
  }
} smt;
int n, q, a[N];
vector<pair<int, int>> queries[N];
long long ans[N]; 
int s1[N], t1, s2[N], t2;
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
  }
  smt.build(1, 1, n);
  read(q);
  for (int i = 1, l, r; i <= q; ++i) {
    read(l), read(r);
    queries[r].push_back(make_pair(i, l));
  }
  for (int i = 1; i <= n; ++i) {
    smt.tagval(1, -1);
    while (t1 && a[s1[t1]] > a[i]) {
      smt.modify(1, s1[t1 - 1] + 1, s1[t1], a[s1[t1]] - a[i]);
      --t1;
    } 
    s1[++t1] = i;
    while (t2 && a[s2[t2]] < a[i]) {
      smt.modify(1, s2[t2 - 1] + 1, s2[t2], a[i] - a[s2[t2]]);
      --t2;
    }
    s2[++t2] = i;
    smt.tagtim(1, 1);
    for (auto q : queries[i]) {
      ans[q.first] = smt.query(1, q.second, i);
    }
  }
  for (int i = 1; i <= q; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}