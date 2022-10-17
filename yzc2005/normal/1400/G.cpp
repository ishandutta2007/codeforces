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
const int N = 300005;
const int M = 25;
int inv[N], fac[N];
int n, m, l[N], r[N], a[M], b[M];
int cnt[N], sum[N][M * 2];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 2; ++i) {
    fac[i] = inv[i] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    fac[i] = Mul(fac[i - 1], i);
    inv[i] = Mul(inv[mod % i], (mod - mod / i));
  }
  for (int i = 1; i <= n; ++i) {
    mul(inv[i], inv[i - 1]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &l[i], &r[i]);
    ++cnt[l[i]];
    --cnt[r[i] + 1];
  }
  for (int i = 1; i <= n; ++i) {
    cnt[i] += cnt[i - 1];
    for (int j = 0; j <= m * 2; ++j) {
      auto binom = [&](int n, int m) {
        if (n < m || m < 0) {
          return 0;
        } else {
          return Mul(fac[n], Mul(inv[m], inv[n - m]));
        }
      };
      sum[i][j] = Add(sum[i - 1][j], binom(cnt[i] - j, i - j));
    }
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  int ans = 0;
  for (int s = 0; s < 1 << m; ++s) {
    std::set<int> numbers;
    for (int i = 0; i < m; ++i) {
      if (s >> i & 1) {
        numbers.insert(a[i]);
        numbers.insert(b[i]);
      }
    }
    int L = 1, R = n;
    for (auto x : numbers) {
      L = std::max(L, l[x]);
      R = std::min(R, r[x]);
    }
    if (L <= R) {
      int tmp = numbers.size();
      int res = Sub(sum[R][tmp], sum[L - 1][tmp]);
      if (__builtin_popcount(s) & 1) {
        sub(ans, res);
      } else {
        add(ans, res);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}