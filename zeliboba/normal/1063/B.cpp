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
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char s[2005][2005];
pii d[2005][2005];
int n, m;

bool ok(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m && s[i][j] != '*';
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int r, c, L, R;
  scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &L, &R);
  --r; --c;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    d[i][j] = pii(L + 1, R + 1);
  }
  d[r][c] = pii(0, 0);
  vector<vii> q(n * m + 5);
  q[0].assign(1, pii(r, c));
  for (int t = 0; t < q.size(); ++t) {
    int it = 0;
    while (it < q[t].size()) {
      int x = q[t][it].first, y = q[t][it].second;
      ++it;
      for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir], ny = y + dy[dir];
        pii nd = d[x][y];
        if (dir == 0) ++nd.second;
        if (dir == 1) ++nd.first;
        if (ok(nx, ny) && nd.first + nd.second < d[nx][ny].first + d[nx][ny].second) {
          q[nd.first + nd.second].emplace_back(nx, ny);
          d[nx][ny] = nd;
        }
      } 
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (d[i][j].first <= L && d[i][j].second <= R) {
    ++cnt;
  }
  printf("%d\n", cnt);
  return 0;
}