#include <bits/stdc++.h>
using namespace std;
const int K = 19, N = 1 << 19 | 5;
int n, k;
struct trie {
  int tot, ch[N * K][2];
  inline void insert(int x, int k) {
    int p = 0;
    for (--k; ~k; --k) {
      int &q = ch[p][x >> k & 1];
      if (!q) q = ++tot;
      p = q;
    }
  }
  int query_min(int x, int k) {
    int res = 0, p = 0;
    for (--k; ~k; --k) {
      int cur = x >> k & 1;
      if (ch[p][cur]) p = ch[p][cur];
      else p = ch[p][cur ^ 1], res |= 1 << k;
    }
    return res;
  }
  int query_max(int x, int k) {
    int res = 0, p = 0;
    for (--k; ~k; --k) {
      int cur = x >> k & 1;
      if (ch[p][cur ^ 1]) p = ch[p][cur ^ 1], res |= 1 << k;
      else p = ch[p][cur];
    }
    return res;
  }
  inline void clear() {
    for (; ~tot; --tot) 
      ch[tot][0] = ch[tot][1] = 0;
    tot = 0;
  }
} t0, t1;
vector<int> solve(vector<int> a, int k) {
  if (a.size() <= 1u) return vector<int>(1 << k, 1e9);
  vector<int> a0, a1;
  for (auto x : a) {
    if (x >> (k - 1) & 1) a1.emplace_back(x ^ (1 << (k - 1)));
    else a0.emplace_back(x);
  }
  auto f0 = solve(a0, k - 1), f1 = solve(a1, k - 1);
  vector<int> f(1 << k);
  for (int i = 0; i < 1 << (k - 1); ++i)
    f[i] = f[i + (1 << (k - 1))] = min(f0[i], f1[i]);
  if (!a0.empty() && !a1.empty()) {
    for (auto x : a0) t0.insert(x, k - 1);
    for (auto x : a1) t1.insert(x, k - 1);
    for (int i = 0; i < 1 << (k - 1); ++i) {
      int mx = t0.query_max(i, k - 1), mn = t1.query_min(i, k - 1);
      f[i] = min(f[i], mn + (1 << (k - 1)) - mx); 
      mx = t1.query_max(i, k - 1), mn = t0.query_min(i, k - 1);
      f[i | (1 << (k - 1))] = min(f[i | (1 << (k - 1))], mn + (1 << (k - 1)) - mx);
    }
    t0.clear(), t1.clear();
  } 
  return f;
}
int main() {
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for (auto &x : a) scanf("%d", &x);
  auto f = solve(a, k);
  for (auto x : f) printf("%d ", x);
  return 0;
}