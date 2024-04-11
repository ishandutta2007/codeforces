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

vii f(vi a) {
  vii x(1, pii(a[0], 1));
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] == a[i - 1]) x.back().second++;
    else x.emplace_back(a[i], 1);
  }
  return x;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vi w(n, 1), pr(n, -1);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      if (mp.count(a[i])) pr[i] = mp[a[i]];
      mp[a[i]] = i;
    }
    bool ok = 1;
    int it = n - 1;
    for (int i = n - 1; i >= 0; --i) {
      while (it >= 0 && a[it] != b[i] && w[it] <= 0) {
        if (pr[it] >= 0) w[pr[it]] += w[it];
//        cout << test << ' ' << i << ' ' << it << ' ' << pr[it] << ' ' << w[it] << endl;
//        assert(pr[it] >= 0 || w[it] == 0);
        --it; 
      }
      if (it < 0 || a[it] != b[i]) {
        ok = 0;
        break;
      }
      w[it]--;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}