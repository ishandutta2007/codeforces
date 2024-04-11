#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int k;
  cin >> k;
  string s = "";
  char c = 'a';
  int cnt = 0;
  while (k) {
    if (cnt <= k) {
      s += c;
      k -= cnt;
      ++cnt;
    } else {
      ++c;
      cnt = 0;
    }
  }
  if (s.empty())
    s += c;
  cout << s << '\n';
}