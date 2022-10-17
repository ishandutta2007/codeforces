#include <bits/stdc++.h>
const int mod = 998244353;
inline void add(int &a, int b) {
  (a += b) >= mod && (a -= mod);
}
inline int Add(int a, int b) {
  return add(a, b), a;
}
inline void sub(int &a, int b) {
  (a -= b) < 0 && (a += mod);
}
inline int Sub(int a, int b) {
  return sub(a, b), a;
}
inline void mul(int &a, int b) {
  a = 1ll * a * b % mod;
}
inline int Mul(int a, int b) {
  return 1ll * a * b % mod;
}
inline int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      mul(res, a);
    }
    mul(a, a);
    b >>= 1;
  }
  return res;
}
const int N = 300005;
int n, f[N][3];
std::vector<int> g[N];
void dfs(int u, int fa) {
  f[u][0] = f[u][2] = 1;
  for (auto v : g[u]) {
    if (v ^ fa) {
      dfs(v, u);
      mul(f[u][0], Add(f[v][0], f[v][1]));
      mul(f[u][2], Add(f[v][0], Mul(2, f[v][1])));
      add(f[u][1], Mul(power(Add(f[v][0], Mul(2, f[v][1])), mod - 2), f[v][2]));
    }
  }
  mul(f[u][1], f[u][2]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  printf("%d\n", Add(f[1][0], f[1][1]));
  return 0;
}