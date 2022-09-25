#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(string s) {
  int n = (int) s.size();
  for (auto& c : s) {
    c = c == '(' ? 1 : -1;
  }
  int bal = 0;
  int l = 0, lbal = 0, r = 0, rbal = 0;
  bool fail = false;
  int m = 0, mbal = 0;
  for (int i = 0; i < n; ++i) {
    bal += s[i];
    if (bal < 0) {
      fail = true;
      rbal = -1;
    }
    if (!fail && bal > lbal) {
      l = i + 1;
      lbal = bal;
    }
    if (bal > rbal) {
      r = i + 1;
      rbal = bal;
    }
    if (bal > mbal) {
      m = i + 1;
      mbal = bal;
    }
  }
  if (!fail) {
    cout << 0 << '\n';
    return;
  }

  auto t = s;
  reverse(t.begin() + l, t.begin() + r);
  fail = false;
  for (auto c : t) {
    bal += c;
    if (bal < 0) {
      fail = true;
    }
  }
  if (!fail) {
    cout << 1 << '\n';
    cout << l + 1 << ' ' << r << '\n';
    return;
  }

  t = s;
  reverse(t.begin(), t.begin() + m);
  reverse(t.begin() + m, t.end());
  fail = false;
  for (auto c : t) {
    bal += c;
    if (bal < 0) {
      fail = true;
    }
  }
  assert(!fail);
  cout << 2 << '\n';
  cout << 1 << ' ' << m << '\n';
  cout << m + 1 << ' ' << n << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  //mt19937 rnd(1337);
  //while (true) {
    //int n = rnd() % 50 + 1;
    //string s;
    //s += string(n, '(');
    //s += string(n, ')');
    //shuffle(s.begin(), s.end(), rnd);
    //cerr << s << '\n';
    //solve(s);
  //}

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    int n;
    string s;
    cin >> n >> s;
    solve(s);
  }
}