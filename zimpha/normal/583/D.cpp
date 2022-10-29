#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 200 + 10, inf = 1e9;

int a[MAXN], f[MAXN], n, T;

int A[MAXN][MAXN], ret[MAXN][MAXN];

void mul(int A[][MAXN], int B[][MAXN]) {
  int C[MAXN][MAXN];
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      C[i][j] = -inf;
    }
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      for (int k = 0; k < n; ++ k) {
        C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
      }
    }
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      A[i][j] = C[i][j];
    }
  }
}

int main() {
  cin >> n >> T;
  for (int i = 0; i < n; ++ i) cin >> a[i];
  if (T == 1) {
    int mx(0);
    for (int i = 0; i < n; ++ i) {
      f[i] = 1;
      for (int j = 0; j < i; ++ j) {
        if (a[j] <= a[i]) f[i] = max(f[i], f[j] + 1);
      }
      mx = max(mx, f[i]);
    }
    cout << mx << endl;
    return 0;
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      A[i][j] = -inf;
      ret[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++ i) a[i + n] = a[i];
  for (int s = 0; s < n; ++ s) {
    for (int i = 0; i < MAXN; ++ i) f[i] = -1e9;
    for (int i = s; i < n * 2; ++ i) if (a[i] >= a[s]) {
      f[i] = 1;
      for (int j = s; j < i; ++ j) if (a[j] >= a[s]) {
        if (a[j] <= a[i]) f[i] = max(f[i], f[j] + 1);
      }
      if (i >= n) A[s][i % n] = f[i] - 1;
    }
  }
  T --;
  for (; T; T >>= 1) {
    if (T & 1) mul(ret, A);
    mul(A, A);
  }
  int ans(0);
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      ans = max(ans, ret[i][j]);
    }
  }
  cout << ans + 1 << endl;
  return 0;
}