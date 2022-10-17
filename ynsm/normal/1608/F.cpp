#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pint;

const int N = 2010, K = 110, mod = 998244353;

int n, k, a[N], l[N], r[N];
int dp[N][N], nxt[N][N], C[N][N];

void add(int &a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
}
int mult(int a, int b) { return 1ll * a * b % mod; }

void solve() {
  for (int i = 0; i < N; i++)
    C[0][i] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++)
      C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % mod;

  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  l[0] = r[0] = 0;
  l[n + 1] = 0, r[n + 1] = n + 1;

  for (int i = 1; i <= n; i++)
    l[i] = max(l[i - 1], a[i] - k);
  for (int i = n; i >= 0; i--)
    r[i] = min({i, a[i] + k, r[i + 1]});
  for (int i = n; i >= 0; i--) {
    if (l[i] > r[i]) {
      printf("0\n");
      return;
    }
  }

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 0; j--)
      for (int q = l[i]; q <= r[i]; q++)
        nxt[j][q] = 0;
    for (int j = i; j >= 0; j--)
      for (int q = l[i]; q <= r[i]; q++)
        add(nxt[j][q], mult(dp[j][q], j + q));
    for (int j = i; j >= 0; j--)
      for (int q = l[i]; q <= r[i]; q++)
        add(nxt[j + 1][q], dp[j][q]);
    for (int j = i; j > 0; j--)
      for (int q = l[i - 1]; q <= r[i] - 1; q++)
        add(dp[j - 1][q + 1], mult(dp[j][q], j));
    for (int j = i; j >= 0; j--)
      for (int q = max(1, l[i]); q <= r[i]; q++)
        add(nxt[j][q], dp[j][q - 1]);
    for (int j = i; j >= 0; j--)
      for (int q = l[i - 1]; q <= r[i]; q++)
        dp[j][q] = 0;
    for (int j = i; j >= 0; j--)
      for (int q = l[i]; q <= r[i]; q++)
        dp[j][q] = nxt[j][q];
  }

  int ans = 0;
  for (int j = n; j >= 0; j--) {
    for (int q = l[n]; q <= r[n]; q++)
      add(ans, mult(dp[j][q], C[j][n - q]));
    if (j)
      ans = mult(ans, j);
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--)
    solve();
}