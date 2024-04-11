#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    vvi g(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      g[a].push_back(b);
    }
    vi a(n), was(n);
    for (int i = 0; i < n; ++i) if (!a[i]) {
      if (was[i]) {
        for (int j : g[i]) a[j] = 1;
      } else {
        for (int j : g[i]) was[j] = 1;
      }
    }
    vi v;
    for (int i = 0; i < a.size(); ++i) if (a[i]) v.push_back(i + 1);
    cout << v.size() << '\n';
    for (int x : v) cout << x << ' ';
    cout << '\n';
/*    for (int i = 0; i < n; ++i) if (!was[i] && !a[i]) {
      for (int j : g[i]) {
        was[j] = 1;
        if (!a[j]) {
          for (int t : g[j]) {
            if (was[t] && a[t] == 0) {
              for (int t1 : g[t]) {
                --a[t1];
              }
            }
            a[t]++;
          }
        }
      } 
    }*/
  }
  return 0;
}