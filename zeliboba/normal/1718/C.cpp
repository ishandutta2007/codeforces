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

ll f(const vector<multiset<ll>>& w, int n) {
  ll res = 0;
  for (int i = 0; i < w.size(); ++i) {
    auto it = w[i].end(); --it;
    res = max(res, (ll)w[i].size() * (*it));
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, q;
    cin >> n >> q;
    int t = n;
    vi p;
    for (int i = 2; i <= t; ++i) if (t % i == 0) {
      p.push_back(i);
      while (t % i == 0) t /= i;
    }
    assert(t == 1);
    vi a(n);
    vector<multiset<ll>> w(p.size());
    vvl s(p.size());
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < p.size(); ++i) {
      s[i].assign(n / p[i], 0);
      for (int j = 0; j < n; ++j) s[i][j % (n / p[i])] += a[j];
      for (ll x : s[i]) w[i].insert(x);
//      cerr << p[i] << ' ' << n / p[i] << endl;
    }
    cout << f(w, n) << '\n';
    for (int t = 0; t < q; ++t) {
      int pos, x;
      cin >> pos >> x;
      --pos;
      for (int i = 0; i < p.size(); ++i) {
        int j = pos % (n / p[i]);
        w[i].erase(w[i].find(s[i][j]));
        s[i][j] += x - a[pos];
        w[i].insert(s[i][j]);
      }
      a[pos] = x;
      cout << f(w, n) << '\n';
    }
  }
  return 0;
}