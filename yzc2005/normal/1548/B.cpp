#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005, K = 18;
int n, lg[N];
ll a[N], b[N], st[K][N];

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll aabs(ll x) {return x < 0 ? -x : x;}

inline ll query(int l, int r) {
  int t = lg[r - l + 1];
  return gcd(st[t][l], st[t][r - (1 << t) + 1]);
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i < n; ++i) b[i] = a[i] - a[i + 1], st[0][i] = b[i];
  for (int k = 1; k < K; ++k)
    for (int i = 1; i + (1 << k) - 1 < n; ++i)
      st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    int l = i, r = n - 1, cur = i - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (aabs(query(i, mid)) > 1) cur = mid, l = mid + 1;
      else r = mid - 1;
    }
    ans = max(cur - i + 2, ans);
  }  
  printf("%d\n", ans);
}

int main() {
  for (int i = 2; i < N; ++i) lg[i] = lg[i / 2] + 1;
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}