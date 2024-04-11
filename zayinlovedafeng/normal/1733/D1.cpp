#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    LL x, y;
    cin >> n >> x >> y;
    string s, t;
    cin >> s >> t;
    vector<int> diff_pos;
    for (int i = 0; i < n; ++i)
      if (s[i] != t[i]) diff_pos.push_back(i);

    if (diff_pos.size() & 1) {
      cout << -1 << endl;
      continue;
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
  return 0;
}