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

__int128 read() {
  __int128 x = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    x = x * 10 + s[i] - '0';
  }
  return x;
}

void print(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  cout << (char)(x % 10 + '0');
}

__int128 nok(__int128 a, __int128 b) {
  if (a == 0 || b == 0) return 0;
  __int128 g = __gcd(a, b);
  return a / g * b;
}

__int128 tra[1000][1 << 11];
__int128 trb[1000][1 << 11];

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    vector<__int128> a(n), b(m);
    vi x(n, 1), y(m, 1);
    for (int i = 0; i < n; ++i) {
      a[i] = read();
    }
    for (int i = 0; i < m; ++i) {
      b[i] = read();
    }
    int N = 1, M = 1;
    while (N < n) N *= 2;
    while (M < m) M *= 2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) tra[i][M + j] = __gcd(b[j], a[i]) % a[i];
      for (int j = m; j < M; ++j) tra[i][M + j] = 1;
      for (int j = M - 1; j >= 0; --j) tra[i][j] = nok(tra[i][2 * j], tra[i][2 * j + 1]) % a[i];
    }
    for (int i = 0; i < m; ++i) {
      memset(trb[i], 0, sizeof(trb[i]));
      for (int j = 0; j < n; ++j) trb[i][N + j] = __gcd(a[j], b[i]) % b[i];
      for (int j = n; j < N; ++j) trb[i][N + j] = 1;
      for (int j = N - 1; j >= 0; --j) trb[i][j] = nok(trb[i][2 * j], trb[i][2 * j + 1]) % b[i];
    }
    while (!x.empty() && !y.empty()) {
      bool ok = 1;
      for (int i = 0; i < n; ++i) if (x[i] && tra[i][1] != 0) {
//        cerr << (int)a[i] << ' ' << (int)tra[i][1] << endl;
        ok = 0;
        x[i] = 0;
        for (int j = 0; j < m; ++j) if (y[j]) {
          int ind = i + N;
          trb[j][ind] = 1;
          while (ind > 1) {
            ind /= 2;
            trb[j][ind] = nok(trb[j][2 * ind], trb[j][2 * ind + 1]) % b[j];
          }
        }
      }
      for (int i = 0; i < m; ++i) if (y[i] && trb[i][1] != 0) {
//        cerr << (int)b[i] << ' ' << (int)trb[i][1] << endl;
        ok = 0;
        y[i] = 0;
        for (int j = 0; j < n; ++j) if (x[j]) {
          int ind = i + M;
          tra[j][ind] = 1;
          while (ind > 1) {
            ind /= 2;
            tra[j][ind] = nok(tra[j][2 * ind], tra[j][2 * ind + 1]) % a[j];
          }
        }
      }
      if (ok) break;
    }
    if (x == vi(n, 0) || y == vi(m, 0)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      vi x1, y1;
      for (int i = 0; i < n; ++i) if (x[i]) x1.push_back(i);
      for (int i = 0; i < m; ++i) if (y[i]) y1.push_back(i);
      cout << x1.size() << ' ' << y1.size() << '\n';
      for (int i : x1) {
        print(a[i]);
        cout << ' ';
      }
      cout << '\n';
      for (int i : y1) {
        print(b[i]);
        cout << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}