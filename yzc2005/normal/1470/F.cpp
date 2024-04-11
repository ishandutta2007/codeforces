#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<typename T> inline void down(T &x, T y) {x > y ? x = y : 0;}
template<typename T> inline void up(T &x, T y) {x < y ? x = y : 0;}

const int N = 2e5 + 5, K = 18;
const int inf = 1e9 + 5; 
const ll INF = 4e18;
int n, lg[N], lb, rb, db, ub;
ll ans;

struct pt {
  int x, y;
  pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  inline void set() {x = y = -1;}
} p[N];
inline bool cmpx(const pt &x, const pt &y) {
  if (x.x != y.x) return x.x < y.x;
  return x.y < y.y;
}
inline bool cmpy(const pt &x, const pt &y) {
  if (x.y != y.y) return x.y < y.y;
  return x.x < y.x;
}

struct line {
  int l, r;
  line(int _l = 0, int _r = 0) : l(_l), r(_r) {}
  inline void set() {l = inf, r = -inf;}
  inline line operator | (const line &rhs) const {
    return line(min(l, rhs.l), max(r, rhs.r));
  }
  inline int len() {return r - l;}
} pre[N], suf[N];

inline void solve1() { // Non-intersecting -- swap x and y
  pre[0].set(), suf[n + 1].set();
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] | line(p[i].y, p[i].y);
  }
  for (int i = n; i > 1; --i) {
    suf[i] = suf[i + 1] | line(p[i].y, p[i].y);
    down(ans, 1ll * (p[i - 1].x - p[1].x) * (pre[i - 1].r - pre[i - 1].l) + 1ll * (p[n].x - p[i].x) * (suf[i].r - suf[i].l));
  }
}

ll mn[N];
struct ST {
  ll st[K][N];
  inline void init(int s) {
    for (int k = 1; k < K; ++k)
      for (int i = s; i + (1 << k) - 1 < n; ++i)
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
  }
  inline ll query(int l, int r) {
    if (l > r) return INF; int t = lg[r - l + 1];
    return min(st[t][l], st[t][r - (1 << t) + 1]);
  }
} st1, st2;
inline void solve2() { // cross -- once is alright
  int k1 = rb - lb, k2 = ub - db;
  int u, d; tie(d, u) = minmax(p[1].y, p[n].y);
  sort(p + 1, p + n + 1, cmpy);
  int s1 = 0, s2 = n + 1;
  for (int i = 1; i <= n; ++i) {
    if (p[i].y <= d) up(s1, i);
    if (p[i].y >= u) down(s2, i);
  } 
  suf[n + 1].set();
  for (int i = n; i >= s2; --i) {
    suf[i] = suf[i + 1] | line(p[i].x, p[i].x);
    mn[i] = 1ll * k1 * p[i].y + 1ll * k2 * (i == n ? 0 : suf[i + 1].len());
    st1.st[0][i] = 1ll * k1 * p[i].y - 1ll * k2 * suf[i + 1].l;
    st2.st[0][i] = 1ll * k1 * p[i].y + 1ll * k2 * suf[i + 1].r;
  }
  st1.init(s2), st2.init(s2), mn[s2 - 1] = INF; 
  for (int i = s2 + 1; i <= n; ++i) down(mn[i], mn[i - 1]);
  line c; c.set();
  for (int i = 1; i <= s1; ++i) {
    int pl = s2 - 1, pr = s2 - 1, cl = c.l, cr = c.r;
    for (int l = s2, r = n - 1; l <= r; ) {
      int mid = l + r >> 1; 
      if (suf[mid + 1].l <= cl) pl = mid, l = mid + 1;
      else r = mid - 1;
    } // rightmost f(i) <= c
    for (int l = s2, r = n - 1; l <= r; ) {
      int mid = l + r >> 1;
      if (suf[mid + 1].r >= cr) pr = mid, l = mid + 1;
      else r = mid - 1;
    }
    ll val = mn[min(pl, pr)];
    down(val, min(st1.query(pr + 1, pl) + 1ll * k2 * cr, st2.query(pl + 1, pr) - 1ll * k2 * cl)); // k1 * y_i + k2 * (cr - l_i), if pr < p 
    down(val, 1ll * k1 * p[max(pl, pr) + 1].y + 1ll * k2 * (i == 1 ? 0 : c.len()));
    down(ans, val - 1ll * k1 * p[i].y); // k1 * (down - up)
    c = c | line(p[i].x, p[i].x);
  }
}

int px[N], py[N], qx[N], qy[N], c1, c2;
int pool[N << 5], *P = pool;

inline bool judge(int x1, int x2, int x3) {
  return 1ll * (py[x2] - py[x1]) * (px[x3] - px[x2]) < 1ll * (py[x3] - py[x2]) * (px[x2] - px[x1]);
} 

struct node {
  int *q, l, r;
  inline void set(int *s) {q = s, l = 0, r = -1;}
  inline void push(int i) {
    while (l < r && !judge(q[r - 1], q[r], i)) --r;
    q[++r] = i;    
  }
  inline ll query(int i) {
    while (l < r && 1ll * (py[q[l + 1]] - py[q[l]]) * qx[i] < -1ll * qy[i] * (px[q[l + 1]] - px[q[l]])) ++l;
    return 1ll * qy[i] * px[q[l]] + 1ll * qx[i] * py[q[l]];
  }
} t[N << 2];

void build(int p, int l, int r) {
  t[p].set(P), P += r - l + 1;
  for (int i = l; i <= r; ++i) t[p].push(i);
  if (l == r) return;
  int mid = l + r >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}

void query(int p, int l, int r, int ll, int rr, int i) {
  if (l >= ll && r <= rr) return down(ans, t[p].query(i));
  int mid = l + r >> 1;
  if (mid >= ll) query(p << 1, l, mid, ll, rr, i);
  if (mid < rr) query(p << 1 | 1, mid + 1, r, ll, rr, i);
}

struct qry {
  int l, r, i;
  inline bool operator < (const qry &q) const {
    return 1ll * qy[i] * qx[q.i] > 1ll * qy[q.i] * qx[i];
  }
} q[N];

inline void solve3() { // ??? Whatever it is -- reverse on one axis -- must intersect
  sort(p + 1, p + n + 1, cmpx), c1 = c2 = 0;
  pre[0].set(), suf[n + 1].set();
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] | line(p[i].y, p[i].y);
  for (int i = n; i > 1; --i) suf[i] = suf[i + 1] | line(p[i].y, p[i].y);
  for (int i = 1, last = -1; i <= n; ++i) 
    if (pre[i].l != pre[i - 1].l) {
      if (~last) qy[++c1] = last, qx[c1] = p[i].x;
      last = p[i].y;
    } // adjacent pairs
  for (int i = n, last = -1; i; --i)
    if (suf[i].r != suf[i + 1].r) {
      if (~last) px[++c2] = p[i].x, py[c2] = last;
      last = p[i].y;
    }
  if (!c1 || !c2) return;
  reverse(px + 1, px + c2 + 1), reverse(py + 1, py + c2 + 1);
  for (int i = 1; i <= c1; ++i) {
    int xb = qx[i], yb = qy[i]; // x >= xb, y >= yb
    int lp = c2 + 1, rp = 0;
    for (int l = 1, r = c2; l <= r; ) {
      int mid = l + r >> 1;
      if (py[mid] >= yb) rp = mid, l = mid + 1;
      else r = mid - 1;
    }
    for (int l = 1, r = c2; l <= r; ) {
      int mid = l + r >> 1;
      if (px[mid] >= xb) lp = mid, r = mid - 1;
      else l = mid + 1;
    }
    q[i] = (qry) {lp, rp, i};
  }
  for (int i = 1; i <= c1; ++i) qy[i] = ub - qy[i], qx[i] = rb - qx[i];
  for (int i = 1; i <= c2; ++i) px[i] -= lb, py[i] -= db;
  P = pool, build(1, 1, c2), sort(q + 1, q + c1 + 1);
  for (int i = 1; i <= c1; ++i) 
    if (q[i].l <= q[i].r) query(1, 1, c2, q[i].l, q[i].r, q[i].i);
}

inline void getbound() {
  ub = rb = -inf, lb = db = inf;
  for (int i = 1; i <= n; ++i) {
    up(ub, p[i].y), down(db, p[i].y);
    up(rb, p[i].x), down(lb, p[i].x);
  }
}

inline void solve() {
  scanf("%d", &n), ans = INF;
  for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
  sort(p + 1, p + n + 1, cmpx);
  getbound(), solve1(), solve2();
  for (int i = 1; i <= n; ++i) swap(p[i].x, p[i].y);  
  sort(p + 1, p + n + 1, cmpx);
  getbound(), solve1(), solve3();
  for (int i = 1; i <= n; ++i) p[i].y *= -1;
  getbound(), solve3();
  printf("%lld\n", ans);
}

int main() {
  for (int i = 2; i < N; ++i) lg[i] = lg[i >> 1] + 1;
  int tt; scanf("%d", &tt); while(tt--) solve();
  return 0;
}