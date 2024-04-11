#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 10, MOD = 1e9 + 7;

int dp[MAXN][MAXN][2];
string a, b;
int m, d;

void upd(int &x, int y) {
  x += y; if (x >= MOD) x -= MOD;
}

int gao(string &s) {
  int n = s.size();
  memset(dp, 0, sizeof(dp));
  dp[0][0][1] = 1;
  for (int i = 0; i < n; ++i) {
    for (int r = 0; r < m; ++r) {
      for (int e = 0; e < 2; ++e) if (dp[i][r][e]) {
        int up = e ? s[i] - '0' : 9;
        for (int o = 0; o <= up; ++o) {
          if (o == d && i % 2 == 0) continue;
          if (o != d && i % 2 == 1) continue;
          upd(dp[i + 1][(r * 10 + o) % m][e & (o == s[i] - '0')], dp[i][r][e]);
        }
      }
    }
  }
  return (dp[n][0][0] + dp[n][0][1]) % MOD;
}

bool check(string &s) {
  int r = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    r = (r * 10 + s[i] - '0') % m;
    if (i % 2 == 0 && s[i] - '0' == d) return 0;
    if (i % 2 == 1 && s[i] - '0' != d) return 0;
  }
  return r == 0;
}

int main() {
  cin >> m >> d >> a >> b;
  int ret = gao(b) - gao(a);
  ret += MOD; ret %= MOD;
  if (check(a)) ++ret;
  cout << ret % MOD << endl;
  return 0;
}