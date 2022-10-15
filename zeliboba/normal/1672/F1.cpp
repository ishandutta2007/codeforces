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
    vi a(n), b(n);
    vii ts(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      b[i] = a[i];
      ts[i] = pii(a[i], i);
    }
    sort(ts.begin(), ts.end());
    vi w;
    for (int i = 0; i < ts.size(); ++i) if (i == 0 || ts[i].first != ts[i-1].first) w.push_back(i);
    while (!w.empty()) {
      vi v, nw;
      for (int i : w) {
        v.push_back(i);
        if (i != n - 1 && ts[i].first == ts[i + 1].first) nw.push_back(i + 1);
      }
      for (int i = 0; i < v.size(); ++i) {
        int cur = ts[v[i]].second;
        int nx = ts[v[(i+1)%v.size()]].second;
        b[cur] = a[nx];
      }
      w.swap(nw);
    }
    for (int i = 0; i < n; ++i) cout << b[i] << ' ';
    cout << '\n';
  }
  return 0;
}