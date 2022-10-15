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

vi fen;
const int MIN = -1e9;

void remax(int i, int v) {
  for (; i < fen.size(); i |= i + 1)
    fen[i] = max(fen[i], v);
}

int getma(int i) {
  int res = MIN;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res = max(res, fen[i]);
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vl a(n), s(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s[i + 1] = s[i] + a[i];
    }
    vl ts = s;
    sort(ts.begin(), ts.end());
    for (int i = 0; i < s.size(); ++i) s[i] = lower_bound(ts.begin(), ts.end(), s[i]) - ts.begin();
    vi d(n + 1, MIN);
    d[0] = 0;
    fen.assign(ts.size(), MIN);
    vi maxd(ts.size(), MIN);
    for (int i = 0; i <= n; ++i) {
      if (i) {
        if (a[i - 1] < 0) d[i] = max(d[i], d[i - 1] - 1);
        if (a[i - 1] == 0) d[i] = max(d[i], d[i - 1]);
        d[i] = max(d[i], i + getma(s[i] - 1));
        d[i] = max(d[i], maxd[s[i]]);
//        cerr << i << ' ' << s[i] << ' ' << ts[s[i]] << ' ' << getma(s[i] - 1) << endl;
      }
      remax(s[i], d[i] - i);
      maxd[s[i]] = max(maxd[s[i]], d[i]);
    }
    cout << d[n] << '\n';
  }
  return 0;
}