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

const int HOR = 1;
const int VER = 2;
// 1 - horizontal
// 2 - vertical

int parse(vector<string> p) {
  int cnt = 0;
  for (int y = 0; y < 3; y++)
    for (int x = 0; x < 3; x++)
      cnt += p[y][x] == 'O';
  switch (cnt) {
  case 0:
  case 1:
  case 4:
  case 5:
    return HOR | VER;

  case 2:
  case 3:
    return p[0][0] == 'O' ? HOR : VER;
  case 6:
    return p[0][1] == 'O' ? HOR : VER;
  default:
    assert(false);
  }
}

const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int mul(ll a, ll b) {
  return (a * b) % MOD;
}

const int MAXW = 250;
char buf[3][MAXW * 4 + 100];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 2) {
    vvi f(h, vi(w, 0));
    for (int y = 0; y < h; y++) {
      scanf("%s", buf[0]);
      scanf("%s%s%s", buf[0], buf[1], buf[2]);
      for (int x = 0; x < w; x++) {
        vector<string> piece(3);
        for (int dy = 0; dy < 3; dy++)
          for (int dx = 0; dx < 3; dx++)
            piece[dy].pb(buf[dy][x * 4 + 1 + dx]);
        f[y][x] = parse(piece);
      }
    }
    scanf("%s", buf[0]);

    vi cntw(w + 1, 0);
    cntw[0] = 1;
    for (int x = 0; x < w; x++) {
      if (!(h & 1)) {
        bool g = true;
        for (int y = 0; y < h; y++)
          if (!(f[y][x] & VER))
            g = false;
        if (g)
          add(cntw[x + 1], cntw[x]);
      }
      if (x + 2 > w) continue;

      vi cnt(h + 1);
      cnt[0] = 1;
      for (int y = 0; y < h; y++) {
        if ((f[y][x] & HOR) && (f[y][x + 1] & HOR))
          add(cnt[y + 1], cnt[y]);
        if (y + 1 >= h) continue;

        if ((f[y][x] & VER) && (f[y + 1][x] & VER) && (f[y][x + 1] & VER) && (f[y + 1][x + 1] & VER))
          add(cnt[y + 2], cnt[y]);
      }
      bool g = !(h & 1);
      for (int y = 0; y < h; y++)
        g = g && (f[y][x] & VER) && (f[y][x + 1] & VER);
      add(cntw[x + 2], mul(cnt[h] - g, cntw[x]));
    }

    printf("%d\n", cntw[w]);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}