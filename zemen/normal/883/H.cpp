#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("h.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  map<char, int> cnt;
  for (auto c : s)
    cnt[c]++;
  int res = 0;
  vector<int> sos;
  for (auto& p : cnt) {
    if (p.second % 2) {
      ++res, sos.push_back(p.first);
      --p.second;
    }
  }
  if (res == 0) {
    string s;
    for (auto p : cnt) {
      s += string(p.second / 2, p.first);
    }
    string t = s;
    reverse(t.begin(), t.end());
    s += t;
    cout << 1 << '\n' << s << '\n';
    return 0;
  }
  while (n % res != 0 || (n / res) % 2 == 0)
    ++res;
  cout << res << '\n';
  for (int iter = 0; iter < res; ++iter) {
    char c;
    if (!sos.empty()) {
      c = sos.back();
      sos.pop_back();
    } else {
      for (auto& p : cnt) {
        if (p.second > 0) {
          --p.second;
          c = p.first;
          break;
        }
      }
    }
    string s;
    int len = (n / res - 1) / 2;
    while (len > 0) {
      for (auto& p : cnt) {
        int cur = min(len, p.second / 2);
        p.second -= cur * 2;
        len -= cur;
        s += string(cur, p.first);
        if (len == 0)
          break;
      }
    }
    string t = s;
    reverse(t.begin(), t.end());
    s += c;
    s += t;
    cout << s << ' ';
  }
  cout << '\n';
}