#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  const int N = 500;
  vector<int> gr(N);
  for (int i = 0; i < N; ++i) {
    vector<char> can(max(i, 1));
    for (int k = 0; k <= i - 2; ++k) {
      can[gr[k] ^ gr[i - 2 - k]] = true;
    }
    while (can[gr[i]]) {
      ++gr[i];
    }
  }

  auto get = [&](int i) {
    if (i <= 53) {
      return gr[i];
    }
    return gr[53 + (i - 53) % 34];
  };

  for (int i = 0; i < N; ++i) {
    assert(get(i) == gr[i]);
  }

  //for (int start = 0; start < N / 2; ++start) {
    //for (int len = 1; len < N / 2; ++len) {
      //bool ok = true;
      //for (int i = start; i + len < N; ++i) {
        //if (gr[i] != gr[i + len]) {
          //ok = false;
          //break;
        //}
      //}
      //if (!ok) {
        //continue;
      //}
      //cerr << start << ' ' << len << '\n';
      //return 0;
    //}
  //}

  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    string s;
    cin >> n >> s;
    int r = 0, b = 0;
    for (auto c : s) {
      if (c == 'R') {
        ++r;
      } else if (c == 'B') {
        ++b;
      }
    }
    if (r != b) {
      cout << (r > b ? "Alice" : "Bob") << '\n';
      continue;
    }
    int x = 0;
    for (int l = 0; l < n; ) {
      int r = l + 1;
      while (r < n && s[r] != s[r - 1]) {
        ++r;
      }
      x ^= get(r - l);
      l = r;
    }
    cout << (x ? "Alice" : "Bob") << '\n';
  }
}