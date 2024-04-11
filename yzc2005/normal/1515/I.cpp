#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5, K = 19;
int n, q, w[N], v[N], id[N], rev[N];
i64 a[N], s1[N << 2][K], w1[N << 2][K], s2[N << 2][K];
inline void pushup(int p) {
  int ls = p << 1, rs = p << 1 | 1;
  for (int k = 1; k < K; ++k) {
    s1[p][k] = s1[ls][k] + s1[rs][k], w1[p][k] = w1[ls][k] + w1[rs][k];
    s2[p][k] = std::min(s2[ls][k], s1[ls][k] + s2[rs][k]);
  }  
}
inline void update(int p, int i) {
  for (int k = 1; k < K; ++k) {
    s1[p][k] = w1[p][k] = 0, s2[p][k] = 2e18;
    if (v[i] < 1 << k - 1) s1[p][k] = a[i] * v[i], w1[p][k] = a[i] * w[i];
    else if (v[i] >= (1 << (k - 1)) && v[i] < (1 << k) && a[i]) s2[p][k] = v[i];  
  }
}
void build(int p, int l, int r) {
  if (l == r) return update(p, id[l]);
  int mid = l + r >> 1, ls = p << 1, rs = p << 1 | 1;
  build(ls, l, mid), build(rs, mid + 1, r), pushup(p);
}
void modify(int p, int l, int r, int pos) {
  if (l == r) return update(p, id[l]);
  int mid = l + r >> 1, ls = p << 1, rs = p << 1 | 1;
  if (mid >= pos) modify(ls, l, mid, pos);
  else modify(rs, mid + 1, r, pos);
  pushup(p);
}
int k; i64 c;
inline void update() {while (k && c < 1 << (k - 1)) --k;}
i64 query(int p, int l, int r) {
  if (l == r) {
    i64 tmp = min(a[id[l]], c / v[id[l]]);
    c -= tmp * v[id[l]], update();
    return tmp * w[id[l]];
  }
  if (s1[p][k + 1] <= c) {
    i64 tmp = w1[p][k + 1];
    c -= s1[p][k + 1], update();
    return tmp;
  } 
  if (s2[p][k] > c && s1[p][k] <= c) {
    i64 tmp = w1[p][k];
    c -= s1[p][k], update();
    return tmp;
  }
  int mid = l + r >> 1;
  return query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
} 
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) id[i] = i, scanf("%lld%d%d", &a[i], &v[i], &w[i]);
  sort(id + 1, id + n + 1, [&](int i, int j) {return w[i] != w[j]? w[i] > w[j] : v[i] < v[j];});
  for (int i = 1; i <= n; ++i) rev[id[i]] = i;
  for (build(1, 1, n); q; --q) {
    int t; scanf("%d", &t);
    if (t <= 2) {
      int k, d; scanf("%d%d", &k, &d);
      a[d] += (t == 1 ? k : -k), modify(1, 1, n, rev[d]);
    } else {
      scanf("%lld", &c), k = 17, update();
      printf("%lld\n", query(1, 1, n));
    }
  } 
  return 0;
}