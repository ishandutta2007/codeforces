#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

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

const int MAXH = 1010;
const int MAXW = 1010;

int cs[MAXH][MAXW];
int h, w;

inline ll calc(int sx, int sy) {
  ll ans = 0;
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++) {
    int dx = abs(4 * (x - sx) + 2);
    int dy = abs(4 * (y - sy) + 2);
    ans += cs[y][x] * ll(dx * dx + dy * dy);
  }
  return ans;
}
int ansx;
inline ll find1(int y) {
  int l = 0, r = w;
  while (l + 2 < r) {
    int m1 = (l + r) / 2;
    int m2 = m1 + 1;

    ll v1 = calc(m1, y);
    ll v2 = calc(m2, y);
    if (v1 <= v2) r = m1;
    else l = m2;
  }
  pair<ll, int> res(9e18, 1e9);
  for (int i = l; i <= r; i++)
    res = min(res, mp(calc(i, y), i));
  ansx = res.second;
  return res.first;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d", &h, &w) >= 1) {
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      scanf("%d", &cs[y][x]);

/*    h = w = 1000;
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      int v = (rand() << 16) | rand();
      v %= int(1e5 + 1);
      cs[y][x] = abs(v);
    }*/

    int l = 0, r = h;
    while (l + 2 < r) {
      int m1 = (l + r) / 2;
      int m2 = m1 + 1;

      ll v1 = find1(m1);
      ll v2 = find1(m2);
      if (v1 <= v2) r = m1;
      else l = m2;
    }

    pair<ll, int> res(9e18, 1e9);
    for (int y = l; y <= r; y++)
      res = min(res, mp(find1(y), y));
    printf("%I64d\n", res.first);
    find1(res.second);
    printf("%d %d\n", res.second, ansx);
  }
  return 0;
}