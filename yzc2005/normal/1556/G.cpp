#include <bits/stdc++.h>
typedef long long ll;
template<typename T> inline void read(T &x) {
  x = 0; char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
using namespace std;
const int N = 55, M = 200005;
struct DSU {
  int par[M];
  inline void init(int n) {
    iota(par + 1, par + n + 1, 1);
  }
  int get(int x) {
    if (x == par[x]) return x;
    return par[x] = get(par[x]);
  } 
  inline bool test(int x, int y) {
    return get(x) == get(y);
  }
  inline void merge(int x, int y) {
    par[get(x)] = get(y);
  }
} dsu;
int n, m, t[M], cnt, tot, tim[M];
ll a[M], b[M], p[M], ptr[M];
vector<int> g[M];
int main() {
  read(n), read(m);
  for (int i = 1; i <= m; ++i) {
    static char s[10];
    scanf("%s", s);
    if (s[0] == 'b') {
      read(a[i]), read(b[i]);
      p[++cnt] = a[i], p[++cnt] = ++b[i];
    } else {
      read(a[i]), read(b[i]);
      t[i] = 1;
    }
  } 
  p[++cnt] = 0, p[++cnt] = 1ll << n;
  sort(p + 1, p + cnt + 1);
  cnt = unique(p + 1, p + cnt + 1) - p - 1;
  ptr[++tot] = 0;
  for (int i = 1; i < cnt; ++i) {
    ll l = p[i], r = p[i + 1] - 1;
    if (l == r) {
      ptr[++tot] = l;
    } else {
      for (int j = n - 1; ~j; --j) {
        if (!((l ^ r) >> j & 1)) continue;
        ptr[++tot] = l;
        r &= ((1ll << (n - j)) - 1) << j;
        ptr[++tot] = r;
        break;
      }
    }
  }
  ptr[++tot] = 1ll << n;
  tot = unique(ptr + 1, ptr + tot + 1) - ptr - 1;
  auto judge = [&](int i, int j, int k) {
    ll l1 = ptr[i], r1 = ptr[i + 1] - 1;
    ll l2 = ptr[j], r2 = ptr[j + 1] - 1;
    return (l2 - r1 <= (1ll << k)) && (r2 - l1 >= (1ll << k));
  };
  auto add_edge = [&](int i, int j, int k) {
    ll l1 = ptr[i], r1 = ptr[i + 1] - 1;
    ll l2 = ptr[j], r2 = ptr[j + 1] - 1;
    if (l1 >> k & 1) l1 += (!k) ? 1 : ((1ll << (k - 1)) - (l1 & ((1ll << k) - 1)));
    if (r1 >> k & 1) r1 -= (!k) ? 1 : ((r1 & ((1ll << k) - 1)) + 1);
    if (l1 > r1) return;
    if (!(l2 >> k & 1)) l2 += (!k) ? 1 : ((1ll << (k - 1)) - (l2 & ((1ll << k) - 1)));
    if (!(r2 >> k & 1)) r2 -= (!k) ? 1 : ((r2 & ((1ll << k) - 1)) + 1);
    if (l2 > r2) return;
    if ((l2 - r1 <= (1ll << k)) && (r2 - l1 >= (1ll << k))) {
      if (tim[i] > tim[j]) swap(i, j);
      g[i].emplace_back(j);
    }
  };
  for (int i = 1; i < tot; ++i) tim[i] = m + 1;
  for (int i = 1; i <= m; ++i) {
    if (t[i]) continue;
    int pos = lower_bound(ptr + 1, ptr + tot + 1, a[i]) - ptr;
    assert(ptr[pos] == a[i]);
    tim[pos] = i;
    if (a[i] + 1 != b[i]) tim[pos + 1] = i;
  } 
  for (int k = 0; k < n; ++k) {
    for (int i = 1, j = 0; i < tot; ++i) {
      while (j && judge(j, i, k)) --j;
      for (; j + 1 < i && judge(j + 1, i, k); add_edge(++j, i, k));
    }
  }
  dsu.init(tot - 1);
  for (int i = 1; i < tot; ++i) if (tim[i] == m + 1)
    for (auto j : g[i]) dsu.merge(i, j); 
  vector<int> ans;
  for (int i = m; i; --i) {
    if (t[i]) {
      int pa = upper_bound(ptr + 1, ptr + tot + 1, a[i]) - ptr - 1;
      int pb = upper_bound(ptr + 1, ptr + tot + 1, b[i]) - ptr - 1;
      ans.emplace_back(dsu.test(pa, pb));
    } else {
      int u = lower_bound(ptr + 1, ptr + tot + 1, a[i]) - ptr;
      for (auto v : g[u]) dsu.merge(u, v);
      if (a[i] + 1 != b[i]) {
        ++u; 
        for (auto v : g[u]) dsu.merge(u, v);
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans) printf("%d\n", x);
  return 0;
}