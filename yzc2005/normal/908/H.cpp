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
const int M = 48, N = 23;
int n, m, id[M], sz[M], fa[M];
int cnt[1 << N], pwr[1 << N];
char g[M][M];
bool G[M][M], pop[1 << N];
int find(int x) {
  if (x == fa[x]) {
    return x;
  } else {
    return fa[x] = find(fa[x]);
  }
}
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    fa[i] = i;
    scanf("%s", g[i] + 1);
    for (int j = 1; j < i; ++j) {
      if (g[i][j] == 'A') {
        fa[find(i)] = find(j);
      }
    }
  } 
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j < i; ++j) {
      if (g[i][j] == 'X') {
        if (find(i) == find(j)) {
          puts("-1");
          return 0;
        }
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    ++sz[find(i)];
  }
  for (int i = 1; i <= m; ++i) {
    if (fa[i] == i && sz[i] > 1) {
      id[i] = n++;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] == 'X') {
        int u = fa[i], v = fa[j];
        if (sz[u] > 1 && sz[v] > 1) {
          u = id[u];
          v = id[v];
          G[u][v] = 1;
          G[v][u] = 1;
        }
      }
    }
  }
  cnt[0] = 1;
  for (int s = 0; s < 1 << n; ++s) {
    pop[s] = pop[s >> 1] ^ (s & 1);
    for (int u = 0; u < n; ++u) {
      if (s >> u & 1) {
        if (cnt[s ^ (1 << u)]) {
          cnt[s] = 1; 
          for (int v = u + 1; v < n; ++v) {
            if (s >> v & 1 && G[u][v]) {
              cnt[s] = 0;
              break;
            }
          }
        }
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int s = 0; s < 1 << n; ++s) {
      if (s >> i & 1) {
        cnt[s] += cnt[s ^ (1 << i)];
      }
    }
  }
  std::fill(pwr, pwr + (1 << n), 1);
  for (int k = 0; k <= n; ++k) {
    int sum = 0;
    for (int s = 0; s < 1 << n; ++s) {
      if ((n & 1) ^ pop[s]) {
        sub(sum, pwr[s]); 
      } else {
        add(sum, pwr[s]);
      }
      mul(pwr[s], cnt[s]);
    }
    if (sum) {
      printf("%d\n", m - 1 + k);
      return 0;
    }
  }
  return 0;
}