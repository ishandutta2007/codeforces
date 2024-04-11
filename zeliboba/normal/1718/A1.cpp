#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vi a(n), s(n + 1), d(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s[i + 1] = s[i] ^ a[i];
    }
    map<int, int> w;
    w[0] = 0;
    for (int i = 0; i < n; ++i) {
      d[i + 1] = d[i] + 1;
      if (w.count(s[i + 1])) {
//        cerr << i + 1 << ' ' << s[i + 1] << ' ' << w[s[i + 1]]
        d[i + 1] = min(d[i + 1], d[w[s[i + 1]]] + i - w[s[i + 1]]);
      }
      w[s[i + 1]] = i + 1;
    }
    cout << d[n] << '\n';
  }
  return 0;
}