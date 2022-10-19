#include <bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 5;
int n, q, v[N], c[N];
long long dp[N], val[N];
bool exist[N];
void solve(int a, int b) {
  memset(val, 0xcf, sizeof val);
  memset(exist, 0, sizeof exist);
  long long v1 = 0, v2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (exist[c[i]]) {
      dp[i] = val[c[i]] + 1ll * a * v[i];
    } else {
      dp[i] = -1e18;
    }
    exist[c[i]] = true;
    dp[i] = max(dp[i], (v1 == val[c[i]] ? v2 : v1) + 1ll * b * v[i]);
    if (val[c[i]] < dp[i]) {
      long long prv = val[c[i]];
      long long cur = dp[i];
      val[c[i]] = dp[i];
      if (v1 == prv) {
        v1 = cur;
      } else if (v1 < cur) {
        v2 = v1;
        v1 = cur;
      } else if (v2 < cur) {
        v2 = cur;
      }
    }
  } 
  cout << v1 << endl;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    solve(a, b);
  }
  return 0;
}