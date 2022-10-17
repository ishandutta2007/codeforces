#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ll * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ll * x * y % mod;}
inline int power(int a, int b, int c = 1) {
  for (; b; b >>= 1, mul(a, a))
    if (b & 1) mul(c, a);
  return c;
}
const int N = 555555;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int inv[N], fac[N], ifac[N];
int ch[N][2], siz[N], lazy[N], val[N], pri[N], root, tot;
inline void tag(int p, int val) {
  ::val[p] += val;
  lazy[p] += val;
}
inline void pushdown(int p) {
  if (lazy[p]) {
    if (ch[p][0]) tag(ch[p][0], lazy[p]);
    if (ch[p][1]) tag(ch[p][1], lazy[p]);
    lazy[p] = 0; 
  }
}
inline void pushup(int p) {
  siz[p] = 1 + siz[ch[p][0]] + siz[ch[p][1]];
}
void split(int p, int v, int &x, int &y) {
  if (!p) x = y = 0;
  else {
    pushdown(p);
    if (val[p] <= v) x = p, split(ch[p][1], v, ch[p][1], y);
    else y = p, split(ch[p][0], v, x, ch[p][0]);
    pushup(p);
  }
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  pushdown(x), pushdown(y);
  if (pri[x] > pri[y]) {
    ch[x][1] = merge(ch[x][1], y);
    pushup(x); return x;
  } else {
    ch[y][0] = merge(x, ch[y][0]);
    pushup(y); return y;
  }
}
inline void insert(int v) {
  int x, y; split(root, v, x, y);
  siz[++tot] = 1, val[tot] = v;
  pri[tot] = rng();
  ch[tot][0] = ch[tot][1] = lazy[tot] = 0;
  root = merge(merge(x, tot), y);
} 
inline void erase(int v) {
  int x, y; split(root, v, x, y);
  int a, b; split(x, v - 1, a, b);
  b = merge(ch[b][0], ch[b][1]);
  root = merge(merge(a, b), y);
}
inline int rnk(int v) {
  int x, y; split(root, v - 1, x, y);
  int res = siz[x] + 1;
  root = merge(x, y);
  return res;
}
inline void add(int pos) {
  int x, y;
  split(root, pos - 1, x, y);
  tag(y, 1);
  root = merge(x, y);
}
inline void init(int n) {
  for (int i = 0; i < 2; ++i) inv[i] = fac[i] = ifac[i] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = Mul(mod - mod / i, inv[mod % i]);
    fac[i] = Mul(fac[i - 1], i);
    ifac[i] = Mul(ifac[i - 1], inv[i]);
  }
}
inline int binom(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return Mul(fac[n], Mul(ifac[m], ifac[n - m]));
}
inline int calc(int n, int m, int k) {
  k = n + 1 - k;
  return binom(m - 2 + k, n);
}
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  tot = root = 0;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(y);
    erase(y - 1);
    erase(y);
    insert(y);
  }
  printf("%d\n", calc(n, n, siz[root]));
}
int main() {
  
  init(N - 1);
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}