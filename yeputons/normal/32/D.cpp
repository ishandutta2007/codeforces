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

const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, -1, 1, 0, 0 };

int h, w;
char f[300][301];
bool check(int x, int y) {
  if (x < 0 || y < 0 || x >= w || y >= h) return false;
  return f[y][x] == '*';
}

bool check(int x, int y, int r) {
  for (int d = 0; d < 5; d++)
    if (!check(x + dx[d] * r, y + dy[d] * r)) return false;
  return true;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int k;
  while (scanf("%d%d%d", &h, &w, &k) >= 3) {
    k--;
    for (int y = 0; y < h; y++)
      scanf("%s", f[y]);

    for (int r = 1; r <= min(h, w); r++) {
      for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++) if (check(x, y, r)) {
          if (!k) {
            for (int d = 0; d < 5; d++)
              printf("%d %d\n", y + dy[d] * r + 1, x + dx[d] * r + 1);
            goto end;
          } else
            k--;
        }
    }
    printf("-1\n");
    end:;

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}