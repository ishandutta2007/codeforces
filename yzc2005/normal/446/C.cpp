#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9, inv2 = (mod + 1) / 2;
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
const int SQ = 383008016, invSQ = power(SQ, mod - 2);
const int x1 = Mul(Add(1, SQ), inv2), x2 = Mul(Sub(1, SQ), inv2);

const int N = 3e5 + 15;

struct lazy {
  int v1, v2;
  inline void reset() {v1 = v2 = 0;}
  inline void operator = (const lazy &rhs) {v1 = rhs.v1, v2 = rhs.v2;}
  inline lazy operator * (const lazy &rhs) {return (lazy) {Mul(v1, rhs.v1), Mul(v2, rhs.v2)};}
  inline int calc(const lazy &rhs) {return Sub(Mul(v1, rhs.v1), Mul(v2, rhs.v2));}
  inline void operator += (const lazy &rhs) {add(v1, rhs.v1), add(v2, rhs.v2);}
} F[N], S[N];

int rt[N], cur, cnt, ti[N], tot;

const int M = 7e6;
struct node {
  int len, val, ls, rs;
  lazy lzy[2];
  inline void operator = (const node &rhs) {
    len = rhs.len, val = rhs.val, ls = rhs.ls, rs = rhs.rs;
    lzy[0] = rhs.lzy[0], lzy[1] = rhs.lzy[1];
  }
} t[M];

inline void tag(int &p, lazy lzy, bool rev) {
  t[p].lzy[rev] += lzy;
//  printf("%d %d %d\n", t[p].len, lzy.v1, lzy.v2);
  add(t[p].val, S[t[p].len].calc(lzy));
//  assert(t[p].val);
}

inline void New(int &p, int len) {int q = p; p = ++tot, t[p] = t[q], t[p].len = len;}

inline void pushdown(int p) {
  tag(t[p].ls, t[p].lzy[0], 0), tag(t[p].ls, F[t[t[p].ls].len] * t[p].lzy[1], 1);
  tag(t[p].rs, F[t[t[p].ls].len] * t[p].lzy[0], 0), tag(t[p].rs, t[p].lzy[1], 1);
  t[p].lzy[0].reset(), t[p].lzy[1].reset();
}

void modify(int &p, int q, int l, int r, int ll, int rr, int len, bool rev) { // len + 1, len + 2, ...
//  printf("ll = %d, rr = %d, len = %d, rev = %d\n", ll, rr, len, rev);
  if (!p) New(p = q, r - l + 1);
  if (l >= ll && r <= rr) return tag(p, F[len + (rev ? (rr - r) : (l - ll))], rev);
  int mid = l + r >> 1; 
  if (t[p].lzy[0].v1 || t[p].lzy[1].v1) New(t[p].ls, mid - l + 1), New(t[p].rs, r - mid), pushdown(p);
  if (mid >= ll) modify(t[p].ls, t[q].ls, l, mid, ll, rr, len, rev);
  if (mid < rr) modify(t[p].rs, t[q].rs, mid + 1, r, ll, rr, len, rev);
  t[p].val = Add(t[t[p].ls].val, t[t[p].rs].val);
}

int query(int p, int l, int r, int ll, int rr) {
//  printf("ll = %d, rr = %d\n", ll, rr);
  if (l >= ll && r <= rr) return t[p].val;
  int mid = l + r >> 1, res = 0; 
  if (t[p].lzy[0].v1 || t[p].lzy[1].v1) New(t[p].ls, mid - l + 1), New(t[p].rs, r - mid), pushdown(p);
  if (mid >= ll) add(res, query(t[p].ls, l, mid, ll, rr)); 
  if (mid < rr) add(res, query(t[p].rs, mid + 1, r, ll, rr));
  return res;
}

int n, m, s[N];
int p1[N], p2[N], s1[N], s2[N];

int main() {
  cin >> n >> m;
  p1[0] = p2[0] = 1;
  for (int i = 0; i <= n; ++i) {
    if (i) p1[i] = Mul(p1[i - 1], x1), p2[i] = Mul(p2[i - 1], x2);
    if (i) s1[i] = Add(s1[i - 1], p1[i]), s2[i] = Add(s2[i - 1], p2[i]);
    F[i] = (lazy) {p1[i], p2[i]}, S[i] = (lazy) {s1[i], s2[i]};
  }
  for (int i = 1; i <= n; ++i) cin >> s[i], add(s[i], s[i - 1]);
  for (int i = 1; i <= m; ++i) {
    int op, l, r; cin >> op >> l >> r;
    if (op == 1) modify(rt[0], rt[0], 1, n, l, r, 0, 0);
    else cout << Add(Sub(s[r], s[l - 1]), Mul(invSQ, query(1, 1, n, l, r))) << endl;
  } 
  return 0;
}