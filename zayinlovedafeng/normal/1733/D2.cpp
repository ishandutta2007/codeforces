#include <bits/stdc++.h>
#define maxn 5050
using namespace std;
typedef long long LL;

int n;
LL x, y;
string s, t;

void solve1() {
  vector<int> diff_pos;
  for (int i = 0; i < n; ++i)
    if (s[i] != t[i]) diff_pos.push_back(i);

  if (diff_pos.size() & 1) {
    cout << -1 << endl;
    return;
  }

  LL ans = 0;
  if (diff_pos.size() != 2) {
    ans = diff_pos.size() / 2 * y;
  } else {
    ans = diff_pos[0] == diff_pos[1] - 1 ? x : y;
    if (diff_pos[0] > 1 || diff_pos[1] < n - 2) ans = min(ans, 2 * y);
    if (diff_pos[0] > 0 && diff_pos[1] < n - 1) ans = min(ans, 3 * y);
  }
  cout << ans << endl;
}

LL dp[2][maxn][2];

void chkmin(LL& a, LL b) { a = min(a, b); }

void solve2() {
  vector<int> diff_pos;
  for (int i = 0; i < n; ++i)
    if (s[i] != t[i]) diff_pos.push_back(i);

  if (diff_pos.size() & 1) {
    cout << -1 << endl;
    return;
  }

  memset(dp, 0x3f, sizeof(dp));
  for (char& c : s) c -= '0';
  for (char& c : t) c -= '0';
  int now = 0;
  dp[now][0][s[0]] = 0;
  for (int i = 1; i < n; ++i) {
    now ^= 1;

    memset(dp[now], 0x3f, sizeof(dp[now]));
    for (int j = 0; j < i; ++j)
      for (int c = 0; c <= 1; ++c) {
        for (int flip = 0; flip <= 1; ++flip) {
          int c0 = c ^ flip, c1 = s[i] ^ flip;
          chkmin(dp[now][j + (c0 != t[i - 1])][c1], dp[now ^ 1][j][c] + flip * x);
        }
      }
    // for (int j = 0; j <= n; ++j)
    //   for (int c = 0; c <= 1; ++c) {
    //     cout << i << " " << j << " " << c << ": " << dp[now][j][c] << endl;
    //   }
  }

  LL ans = 1e18;
  for (int j = 0; j <= n; ++j)
    for (int c = 0; c <= 1; ++c) {
      int diff_cnt = j + (c != t[n - 1]);
      if (diff_cnt & 1) continue;
      chkmin(ans, diff_cnt / 2 * y + dp[now][j][c]);
    }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> x >> y;
    cin >> s >> t;

    if (x >= y)
      solve1();
    else
      solve2();
  }
  return 0;
}