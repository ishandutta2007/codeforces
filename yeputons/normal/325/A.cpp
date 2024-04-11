#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
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

const int inf = 1e9;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    int minx = inf, miny = inf;
    int maxx = -inf, maxy = -inf;
    int sumsq = 0;
    for (int i = 0; i < n; i++) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);
      sumsq += (x2 - x1) * (y2 - y1);
      minx = min(minx, x1);
      maxx = max(maxx, x2);
      miny = min(miny, y1);
      maxy = max(maxy, y2);
    }
    int need = (maxx - minx) * (maxy - miny);
    printf(need == sumsq && maxx - minx == maxy - miny ? "YES\n" : "NO\n");
  }
  return 0;
}