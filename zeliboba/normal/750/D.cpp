#include <cstdio>
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

const int N = 30*5 + 5;
char was[2*N + 1][2*N + 1];
char cur[2][8][2*N + 1][2*N + 1];

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
  //  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi L(n);
  for (int i = 0; i < n; ++i) cin >> L[i];
  was[N][N] = cur[0][0][N][N] = 1;
  for (int i = 0; i < n; ++i) {
    int tt = i % 2;
    memset(cur[1-tt], 0, sizeof(cur[1-tt]));
    for (int t = 0; t < 8; ++t) for (int x = 0; x <= 2*N; ++x) for (int y = 0; y <= 2*N; ++y) if (cur[tt][t][x][y]) {
      int nx = x, ny = y;
      for (int l = 0; l < L[i] - 1; ++l) {
        nx += dx[t];
        ny += dy[t];
        was[nx][ny] = 1;
      }
//      cerr << i << ' ' << x << ' ' << y << ' ' << nx << ' ' << ny << endl;
      if (i != n-1) for (int nt = t-1; nt <= t+1; nt += 2) {
        int nnt = (nt + 8) % 8;
        int nnx = nx + dx[nnt], nny = ny + dy[nnt];
        was[nnx][nny] = cur[1-tt][nnt][nnx][nny] = 1;
      }
    }
  }
  int c = 0;
  for (int i = 0; i <= 2*N; ++i) for (int j = 0; j <= 2*N; ++j) if (was[i][j]) ++c;
  cout << c << endl;
  return 0;
}