#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

bool check(vl w, const vl& f) {
  sort(w.begin(), w.end());
  bool ok = w.size() <= f.size();
  for (int i = 0; i < min(f.size(), w.size()); ++i) if (w[i] != f[i]) ok = 0;
  return ok;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  vl f(2, 1);
  while (f.back() < 1.1e9) {
    f.push_back(f.back() + f[f.size() - 2]);
  }
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vl c(n);
    vii ts;
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
      for (int j = f.size() - 1; j >= 0; --j) if (c[i] >= f[j]) {
        ts.emplace_back(f[j], c[i] == f[j]);
        c[i] -= f[j];
      }
      assert(c[i] == 0);
    }
    sort(ts.begin(), ts.end());
    vl w(ts.size());
    for (int i = 0; i < w.size(); ++i) w[i] = ts[i].first;
    bool ok = check(w, f);
    if (!binary_search(w.begin(), w.end(), 2)) {
      for (int i = 0; i < w.size(); ++i) if (w[i] > 2 && ts[i].second) {
        auto j = lower_bound(f.begin(), f.end(), w[i]) - f.begin();
        if (j % 2 == 1) {
          auto x = w;
          x.erase(x.begin() + i);
          ll s = 0;
          for (int t = 0; t < j; t += 2) {
            x.push_back(f[t]);
            s += f[t];
          }
          assert(s == w[i]);
          if (check(x, f)) ok = 1;
        }
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}