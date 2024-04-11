#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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

const int w = 8;
const int h = 8;
char f[h][w + 1];

const int dc = 9;
const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1, 0 };

const int MAXT = 40;
int mem[h][w][MAXT + 1];
vector<pii> ss;

bool go(int x, int y, int t) {
  if (x < 0 || y < 0 || x >= w || y >= h) return false;
  if (t > MAXT) return false;

  if (x == w - 1 && y == h - 1) return true;
  if (mem[y][x][t] >= 0) return mem[y][x][t];

  int &res = mem[y][x][t];

  for (int i = 0; i < sz(ss); i++)
    if (ss[i].first == x && ss[i].second - t == y)
      return (res = false);

  for (int i = 0; i < dc; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    bool g = true;
    for (int i2 = 0; i2 < sz(ss); i2++)
      if (ss[i2].first == nx && ss[i2].second - t == ny)
        g = false;

    if (!g) continue;
    if (go(nx, ny, t + 1)) {
      return (res = true);
    }
  }
  return (res = false);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  while (scanf("%s", f[h - 1]) >= 1) {
    for (int y = h - 2; y >= 0; y--)
      scanf("%s", f[y]);

    ss.clear();
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        if (f[y][x] == 'S') {
          ss.pb(mp(x, y));
        }

    memset(mem, -1, sizeof mem);
    bool res = go(0, 0, 0);
    printf(res ? "WIN\n" : "LOSE\n");
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}