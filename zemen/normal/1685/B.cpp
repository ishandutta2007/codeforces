#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int a, b, c, d;
  string s;
  cin >> a >> b >> c >> d >> s;
  int cnt_a = 0, cnt_b = 0;
  for (auto c : s) {
    if (c == 'A') {
      ++cnt_a;
    } else {
      ++cnt_b;
    }
  }
  if (cnt_a != a + c + d || cnt_b != b + c + d) {
    cout << "NO\n";
    return;
  }

  vector<pair<int, int>> parts;
  for (int l = 0; l < (int) s.size();) {
    int r = l + 1;
    while (r < (int) s.size() && s[r] != s[r - 1]) {
      ++r;
    }
    if (r - l > 1) {
      int t;
      c -= (r - l) / 2;
      if ((r - l) % 2) {
        t = 1;
      } else if (s[l] == 'A') {
        t = 2;
      } else {
        t = 0;
        ++c;
      }
      parts.emplace_back(t, r - l);
    }
    l = r;
  }
  sort(parts.begin(), parts.end(), [&](pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
      return a.first < b.first;
    }
    if (a.first == 2) {
      return a.second > b.second;
    }
    return a.second < b.second;
  });

  if (c <= 0 && d <= 0) {
    cout << "YES\n";
    return;
  }

  for (auto [t, len] : parts) {
    //cerr << "take " << t << ' ' << len << ' ' << c << ' ' << d << '\n';
    int cur = len / 2;
    if (t == 2) {
      ++c;
      --cur;
    }
    for (int iter = 0; iter < cur; ++iter) {
      ++c;
      --d;
      if (c <= 0 && d <= 0) {
        cout << "YES\n";
        return;
      }
    }
    if (t == 0) {
      --c;
    }

    if (c <= 0 && d <= 0) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}