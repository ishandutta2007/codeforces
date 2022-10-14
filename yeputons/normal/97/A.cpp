#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXH = 30;
const int MAXW = 30;
const int MAXV = 6;

const int DX[] = { 0, 1, 0, -1 };
const int DY[] = { 1, 0, -1, 0 };

char f[MAXH][MAXW];
int ids[MAXH][MAXW];
int sx[MAXH], sy[MAXH];

int h, w;
int n;
vvi es;
vi vals;
int was[MAXV + 1][MAXV + 1];

bool print;
int go(int i, int maxv) {
  if (i >= n) return 1;

  int ans = 0;
  for (vals[i] = 0; vals[i] <= maxv; vals[i]++) {
    bool g = true;
    for (int i2 = 0; i2 < sz(es[i]); i2++) {
      int v1 = vals[i], v2 = vals[es[i][i2]];
      if (v2 < 0) continue;
      if (v1 > v2) swap(v1, v2);
      if (was[v1][v2]) g = false;
      was[v1][v2]++;
    }

    if (g)
      ans += go(i + 1, min(MAXV, max(maxv, vals[i] + 1)));
    if (ans && print) return ans;

    for (int i2 = 0; i2 < sz(es[i]); i2++) {
      int v1 = vals[i], v2 = vals[es[i][i2]];
      if (v2 < 0) continue;
      if (v1 > v2) swap(v1, v2);
      was[v1][v2]--;
    }
  }
  vals[i] = -1;
  return ans;
}

const int dx[] = { 0, 0, 1, 1 };
const int dy[] = { 0, 1, 0, 1 };

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d", &h, &w) >= 1) {
    for (int y = 0; y < h; y++)
      scanf("%s", f[y]);

    memset(ids, -1, sizeof ids);
    n = 0;
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++) if (f[y][x] != '.' && ids[y][x] < 0) {
        sx[n] = x;
        sy[n] = y;
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d], ny = y + dy[d];
          assert(nx < w && ny < h);
          assert(f[ny][nx] != '.');
          ids[ny][nx] = n;
        }
        n++;
      }

    es = vvi(n);
    for (int a = 0; a < n; a++)
      for (int b = a; b < n; b++) {
        bool g = false;
        for (int d1 = 0; d1 < 4; d1++)
          for (int d2 = 0; d2 < 4; d2++) {
            if (abs(sx[a] + dx[d1] - sx[b] - dx[d2]) + abs(sy[a] + dy[d1] - sy[b] - dy[d2]) != 1) continue;
            if (f[sy[a] + dy[d1]][sx[a] + dx[d1]] != f[sy[b] + dy[d2]][sx[b] + dx[d2]]) continue;
            g = true;
          }
        if (g) {
          es[a].pb(b);
          if (a != b)
            es[b].pb(a);
        }
      }

    vals = vi(n, -1);
    memset(was, 0, sizeof was);
    print = false;
    int ans = go(0, 0) * 5040;
    printf("%d\n", ans);

    print = true;
    go(0, 0);
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        if (f[y][x] == '.') printf(".");
        else printf("%d", vals[ids[y][x]]);
      }
      printf("\n");
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}