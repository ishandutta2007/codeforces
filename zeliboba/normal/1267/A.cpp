#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vl a(n), b(n), t(n);
  vii ts;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> t[i];
    ts.emplace_back(a[i] + t[i], i);
  }
  sort(ts.begin(), ts.end());
  int it = 0;
  ll last = -1e18;
  set<pii> q;
  ll res = 0;
  while (!q.empty() || it < ts.size()) {
    while (!q.empty()) {
      auto i = q.begin()->second;
      if (last + t[i] > b[i]) q.erase(q.begin());
      else break;
    }
    if (q.empty()) {
      if (it == ts.size()) break;
      last = max(last, a[ts[it].second]);
      q.insert(pii(t[ts[it].second], ts[it].second));
      ++it;
    } else {
      while (it < ts.size() && last >= a[ts[it].second]) {
        if (last + t[ts[it].second] <= b[ts[it].second]) q.insert(pii(t[ts[it].second], ts[it].second));
        ++it;
      }
//      cerr << "res: " << res << " last: " << last << endl;
//      cerr << "ts: " <<endl;
//      for (int i = it; i < ts.size(); ++i) cerr << ts[i].first << ' ' << ts[i].second << endl;
//      cerr << "q: " << endl;
//      for (auto p : q) cerr << p.first << ' ' << p.second << endl;
      if (it < ts.size() && ts[it].first <= last + q.begin()->first) {
//        cerr << "c1 " << ts[it].first << endl;
        last = ts[it].first;
        ++res;
      } else {
//        cerr << "c2" << endl;
        int i = q.begin()->second;
        ll c = (b[i] - last) / t[i];
        if (it < ts.size()) c = min(c, (ts[it].first - last) / t[i]);
        res += c;
        last += c * t[i];
      }
    }
  }
  cout << res << endl;
  return 0;
}