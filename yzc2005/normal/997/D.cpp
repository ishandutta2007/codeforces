#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline void add(int &a, int b) {
  (a += b) >= mod && (a -= mod);
}
inline int Add(int a, int b) {
  return add(a, b), a;
}
inline void sub(int &a, int b) {
  (a -= b) <= 0 && (a += mod);
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
const int N = 4005, K = 80, M = 40;
int k, m, binom[K][K];
struct Tree {
  vector<int> adj[N];
  int n, f[N][M], up[N][M], down[N][M], sum[N][M];
  void dpd(int u, int fa) {
    for (auto v : adj[u]) {
      if (v == fa) {
        continue;
      }
      dpd(v, u);
      for (int i = 1; i <= m; ++i) {
        add(sum[u][i], down[v][i - 1]);
      }
    }
    down[u][0] = 1;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j < i; ++j) {
        add(down[u][i], Mul(down[u][j], sum[u][i - j]));
      } 
    }
  } 
  void dpu(int u, int fa) {
    for (int i = 1; i <= m; ++i) {
      add(sum[u][i], up[u][i - 1]);
    }
    f[u][0] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < i; ++j) {
        add(f[u][i], Mul(f[u][j], sum[u][i - j]));
      }
    }
    for (auto v : adj[u]) {
      if (v == fa) {
        continue;
      }
      for (int i = 1; i <= m; ++i) {
        sub(sum[u][i], down[v][i - 1]);
      }
      up[v][0] = 1;
      for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < i; ++j) {
          add(up[v][i], Mul(up[v][j], sum[u][i - j]));
        }
      }
      dpu(v, u);
      for (int i = 1; i <= m; ++i) {
        add(sum[u][i], down[v][i - 1]);
      }
    }
  }
  inline void init() {
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dpd(1, 0);
    dpu(1, 0); 
  }
} a, b;
int main() {
  scanf("%d%d%d", &a.n, &b.n, &k);
  if (k % 2) {
    puts("0");
    return 0;
  }
  m = k / 2;
  a.init();
  b.init(); 
  for (int i = 0; i <= k; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = Add(binom[i - 1][j], binom[i - 1][j - 1]);
    }
  }
  int ans = 0; 
  for (int i = 0; i <= m; ++i) {
    int x = 0, y = 0;
    for (int u = 1; u <= a.n; ++u) {
      add(x, a.f[u][i]);
    }
    for (int u = 1; u <= b.n; ++u) {
      add(y, b.f[u][m - i]);
    }
    add(ans, Mul(Mul(x, y), binom[k][i * 2]));
  } 
  printf("%d\n", ans);
  return 0;
}