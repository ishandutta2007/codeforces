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
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;

bool ok(int i, int j, const vs& s) {
  return i >= 0 && j >= 0 && i < n && j < m && s[i][j] != '#';
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> n >> m;
  vs s(n);
  int x0, y0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < m; ++j) if (s[i][j] == 'S') {
      x0 = i; y0 = j;
    }
  }
  string com;
  cin >> com;
  vi ord(4);
  for (int i = 0; i < 4; ++i) ord[i] = i;
  int res = 0;
  do {
    int x = x0, y = y0;
    bool win = 0;
    for (char c : com) {
      int d = ord[c - '0'];
      x += dx[d];
      y += dy[d];
      if (!ok(x, y, s)) {
        break;
      }
      if (s[x][y] == 'E') {
        win = 1;
        break;
      }
    }
    res += win;
  } while (next_permutation(ord.begin(), ord.end()));
  cout << res << endl;
  return 0;
}