#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int n;
int Q = 0;
const int DEBUG = 0;
vvi hidden, v;

int ask(int x1, int y1, int x2, int y2) {
  ++x1; ++y1; ++x2; ++y2;
  ++Q;
  assert(1 <= x1 && x1 <= n && 1 <= x2 && x2 <= n && 1 <= y1 && y1 <= n && 1 <= y2 && y2 <= n);
  assert(x1 <= x2 && y1 <= y2 && x1 + y1 + 2 <= x2 + y2);
  assert(Q <= n * n);
  assert(x1 + y1 + 3 >= x2 + y2);
  cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  fflush(stdout);
  int x;
  if (!DEBUG) cin >> x;
  else {
    --x1; --y1; --x2; --y2;
    x = hidden[x1][y1] == hidden[x2][y2];
    if (x1 + y1 + 3 == x2 + y2) {
      if (x1 == x2 && hidden[x1][y1 + 1] != hidden[x1][y1 + 2]) {
        x = 0;
      }
      if (y1 == y2 && hidden[x1 + 1][y1] != hidden[x1 + 2][y1]) {
        x = 0;
      }
      if (x1 + 1 == x2 && hidden[x1][y1 + 1] != hidden[x1][y1 + 2] && hidden[x1 + 1][y1] != hidden[x1 + 1][y1 + 1] && hidden[x1][y1 + 1] != hidden[x1 + 1][y1 + 1]) {
        x = 0;
      }
      if (y1 + 1 == y2 && hidden[x1 + 1][y1] != hidden[x1 + 2][y1] && hidden[x1][y1 + 1] != hidden[x1 + 1][y1 + 1] && hidden[x1 + 1][y1] != hidden[x1 + 1][y1 + 1]) {
        x = 0;
      }
    }
  }
  return x;
}

void putv(int x1, int y1, int x2, int y2) {
  if (v[x2][y2] >= 0) return;
  assert(v[x1][y1] >= 0);
  assert(x1 <= x2 && y1 <= y2 && x1 + y1 + 2 == x2 + y2);
  v[x2][y2] = v[x1][y1] ^ 1 ^ ask(x1, y1, x2, y2); 
}

void solve() {
  if (DEBUG) {
    hidden.assign(n, vi(n, -1));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) hidden[i][j] = rand() % 2;
    hidden[0][0] = 1;
    hidden[n-1][n-1] = 0;
  }
  Q = 0;
  v.assign(n, vi(n, -1));
  v[0][0] = 1;
  v[0][1] = v[n-1][n-1] = 0;
  for (int i = 0; i < n; ++i) for (int j = 1; j < n; ++j) if (v[i][j] == -1) {
    if (i >= 2) putv(i - 2, j, i, j);
    else if (i >= 1 && j >= 1) putv(i - 1, j - 1, i, j);
    else {
      assert(j >= 2);
      putv(i, j - 2, i, j);
    }
  }
  v[1][0] = v[1][2] ^ 1 ^ ask(1, 0, 1, 2);
  for (int i = 2; i < n; ++i) {
    putv(i - 2, 0, i, 0);
  }
  vii a;
  for (int j = 0; j < n; ++j) a.emplace_back(0, j);
  for (int i = 1; i < n; ++i) a.emplace_back(i, n - 1);
  bool found = 0;
  int xr = 0;
  for (int i = 0; i + 4 < (int)a.size(); i += 2) {
    bool eq1 = v[a[i].first][a[i].second] == v[a[i + 2].first][a[i + 2].second]; 
    bool eq3 = v[a[i + 2].first][a[i + 2].second] == v[a[i + 4].first][a[i + 4].second];
    if (eq1 != eq3) {
      bool eq2 = v[a[i + 1].first][a[i + 1].second] == v[a[i + 3].first][a[i + 3].second];
      if (eq1 == eq2) {
        int res = ask(a[i].first, a[i].second, a[i + 3].first, a[i + 3].second);
        xr = 1 ^ res ^ v[a[i].first][a[i].second] ^ v[a[i + 3].first][a[i + 3].second];
      } else {
        int res = ask(a[i + 1].first, a[i + 1].second, a[i + 4].first, a[i + 4].second);
        xr = 1 ^ res ^ v[a[i + 1].first][a[i + 1].second] ^ v[a[i + 4].first][a[i + 4].second];
      }
      found = 1;
      break;
    }
  }
  assert(found);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if ((i + j) % 2) v[i][j] ^= xr;
  cout << "!\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << v[i][j];
    cout << endl;
  }
  if (DEBUG && v != hidden) {
    cout << "hidden\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << hidden[i][j];
      cout << endl;
    }
    assert(v == hidden);
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (DEBUG) for (n = 3; n <= 50; n += 2) for (int T = 0; T < 10000; ++T) solve();
  cin >> n;
  solve();
  return 0;
}