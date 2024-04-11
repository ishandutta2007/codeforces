#include <bits/stdc++.h>
using namespace std;    
const int N = 505, inf = 1e9;
int n, k, dp[N], ans;
bool g[N][N], valid[N];
void find(int u) {
  if (!u) cout << "! " << ans << endl, exit(0); 
  vector<int> a, b;
  for (int i = 1; i <= n; ++i)
    if (valid[i]) b.emplace_back(i);
    else a.emplace_back(i);
  for (int v = 0; v <= n; ++v)
    if (g[v][u] && dp[u] == dp[v] + 1) {
      int i = (u + k - v) / 2;
      vector<int> cur{a.begin(), a.begin() + i};
      cur.insert(cur.end(), b.begin(), b.begin() + k - i);
      cout << "?"; for (auto x : cur) cout << " " << x, valid[x] ^= 1;
      cout << endl;
      int tmp; cin >> tmp; ans ^= tmp;
      find(v);
    }
}
int main() {
  cin >> n >> k;
  memset(dp, 0x3f, sizeof dp), dp[0] = 0;
  for (int i = 1; i <= n; ++i) 
    for (int j = 0; j <= min(i, k); ++j) 
      if (n - i >= k - j) g[i + k - 2 * j][i] = true;      
  for (int i = 1; i <= n; ++i) 
    for (int u = 0; u <= n; ++u)
      for (int v = 0; v <= n; ++v) if (g[u][v])
        dp[v] = std::min(dp[v], dp[u] + 1);
  if (dp[n] >= inf) return cout << "-1" << endl, 0;
  return find(n), 0;
}