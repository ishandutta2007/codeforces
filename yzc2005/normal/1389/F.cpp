#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = N * 2, inf = 0x3f3f3f3f;
int n, p[M], cnt, dp[M][2];
struct SegmentTree {
    int l[M << 2], r[M << 2], val[M << 2], lzy[M << 2];
    #define mid (l[p] + r[p] >> 1)
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    inline void pushup(int p) {
        val[p] = max(val[ls], val[rs]);
    } 
    inline void tag(int p, int v) {
        val[p] += v;
        lzy[p] += v;
    }
    inline void pushdown(int p) {
        if(lzy[p]) {
            tag(ls, lzy[p]);
            tag(rs, lzy[p]);
            lzy[p] = 0;
        }
    }
    void build(int p, int L, int R) {
        l[p] = L, r[p] = R;
        if(l[p] == r[p]) return val[p] = 0, void();
        build(ls, L, mid), build(rs, mid + 1, R);
        pushup(p);
    }
    void modify(int p, int L, int R, int v) {
        if(l[p] >= L && r[p] <= R) return tag(p, v);
        pushdown(p);
        if(mid >= L) modify(ls, L, R, v);
        if(mid < R) modify(rs, L, R, v);
        pushup(p);
    }
} tr[2];
struct node {
  int l, r, t;
} a[N];
vector<int> b[M][2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
    p[++cnt] = a[i].l, p[++cnt] = a[i].r;
    --a[i].t;
  }
  sort(p + 1, p + cnt + 1);
  cnt = unique(p + 1, p + cnt + 1) - p - 1;
  for (int i = 1; i <= n; ++i) {
    a[i].l = lower_bound(p + 1, p + cnt + 1, a[i].l) - p;
    a[i].r = lower_bound(p + 1, p + cnt + 1, a[i].r) - p;
    b[a[i].r][a[i].t].push_back(a[i].l);
  } 
  for (int i = 0; i < 2; ++i)
    tr[i].build(1, 0, cnt);
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 0; j < 2; ++j)
      for (auto l : b[i][j]) 
        tr[j].modify(1, 0, l - 1, 1);
    for (int j = 0; j < 2; ++j) 
      dp[i][j] = tr[j].val[1];
    for (int j = 0; j < 2; ++j)
      tr[j].modify(1, i, i, dp[i][j ^ 1]);
  }
  printf("%d\n", max(dp[cnt][0], dp[cnt][1]));
  return 0;
}