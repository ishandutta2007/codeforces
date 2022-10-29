#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100;

string a[MAXN], b[MAXN];
int dp[100][26];
int n, q;

int dfs(int n, int s) {
  if (dp[n][s] != -1) return dp[n][s];
  if (n == 1) return dp[n][s] = 1;
  dp[n][s] = 0;
  for (int i = 0; i < q; ++i) {
    if (b[i][0] == s + 'a') dp[n][s] += dfs(n - 1, a[i][0] - 'a');
  }
  return dp[n][s];
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < q; ++i) cin >> a[i] >> b[i];
  memset(dp, -1, sizeof(dp));
  cout << dfs(n, 0) << endl;
  return 0;
}