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

const int DEBUG = 0;

void solve(int n) {
  if (n == 1) {
    cout << 1 << '\n' << "1 1" << '\n';
    return;
  }
  int k = (2 * n - 1 + 2) / 3;
  int r = n - k;
  assert(2 * r - 1 <= k);
  vii v;
  for (int i = 0; i < r; ++i) {
    v.emplace_back(r + i, 2 * r - i - 1);
  }
  for (int i = 0; i < r - 1; ++i) {
    v.emplace_back(2 * r + i, 3 * r - i - 2);
  }
  int t = r + r + r - 1;
  while (t < n) {
    v.emplace_back(t, t);
    ++t;
  }
  assert(v.size() == k);
  cout << k << '\n';
  for (pii p : v) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  if (DEBUG) {
    vvi a(n, vi(n));
    for (pii p : v) {
      assert(p.first >= 0 && p.second >= 0 && p.first < n && p.second < n);
      for (int i = 0; i < n; ++i) {
        a[p.first][i] = 1;
        a[i][p.second] = 1;
        int j = p.second - p.first + i;
        if (j >= 0 && j < n) a[i][j] = 1;
      }
    }
    assert(a == vvi(n, vi(n, 1)));
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (DEBUG) for (int test = 1; test <= 100; ++test) {
    solve(test);
  }
  int n;
  cin >> n;
  solve(n);
  return 0;
}