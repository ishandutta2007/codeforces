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

const int MAXH = 55;
const int MAXW = 55;

char f[MAXH][MAXW + 1];
bool was[MAXH][MAXW];
int h, w;

void dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= w || y >= h) return;
  if (f[y][x] != '#') return;
  if (was[y][x]) return;
  was[y][x] = true;
  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}

bool check() {
  memset(was, 0, sizeof was);

  bool wasd = false;
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++)
    if (f[y][x] == '#' && !was[y][x]) {
      if (wasd) return false;
      dfs(x, y);
      wasd = true;
    }
  return true;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d", &h, &w) >= 1) {
    int cnt = 0;
    for (int y = 0; y < h; y++) {
      scanf("%s", f[y]);
      for (int x = 0; x < w; x++)
        cnt += f[y][x] == '#';
    }

    if (cnt <= 2) printf("-1\n");
    else {
      int ans = 2;
      for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        if (f[y][x] == '#') {
          f[y][x] = '.';
          if (!check()) ans = 1;
          f[y][x] = '#';
        }
      printf("%d\n", ans);
    }
  }
  return 0;
}