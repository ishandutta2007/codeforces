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

ll S = 2000 * 2000;
const int DEBUG = 0;
vi hidden;
int hiddenmax;
int C = 0;

void out(vi v) {
  for (int x : v) cerr << x << ' ';
  cerr << endl;
}

int calch(int w) {
  int h = 1;
  int cur = hidden[0];
  for (int i = 1; i < hidden.size(); ++i) {
    int l = hidden[i];
    if (cur + 1 + l <= w) cur += 1 + l;
    else {
      ++h;
      cur = l;
    }
  }
  return h;
}

int ask(int w) {
  ++C;
  cout << "? " << w << endl;
  int h = 0;
  if (!DEBUG) cin >> h;
  else {
    if (hiddenmax <= w) h = calch(w);
    cerr << h << endl;
  }
  if (h) S = min(S, w * (ll)h);
  return h;
}

void solve(int n) {
  if (DEBUG) {
    hidden.resize(n);
    hiddenmax = 0;
    for (int i = 0; i < n; ++i) {
      hidden[i] = 2000;
      hiddenmax = max(hiddenmax, hidden[i]);
    }
  }
  C = 0;
  int l = 2 * n - 2, r = n + 2000 * n;
  S = r;
  while (r - l > 1) {
    int x = (l + r) / 2;
    if (ask(x) == 1) r = x;
    else l = x;
  }
  int sum = r - n + 1;
  for (int h = 2; h <= n; ++h) {
    for (int w = (sum + n - 1) / h; w * h < S; ++w) {
      if (ask(w) == h) break;
    }
  }
  cout << "! " << S << endl;
  if (DEBUG) {
    int s = 0;
    for (int i : hidden) s += i;
    int res = s + n - 1;;
    for (int w = hiddenmax; w <= s + n - 1; ++w) res = min(res, w * calch(w));
    if (res != S) {
      out(hidden);
      cerr << res << ' ' << S << endl;
    }
    assert(res == S);
  }
  assert(C <= n + 30);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (DEBUG) for (int n = 1; n <= 1; ++n) for (int t = 0; t < 10; ++t) solve(n);
  int n;
  if (!DEBUG) {
    cin >> n;
    solve(n);
  }
  return 0;
}