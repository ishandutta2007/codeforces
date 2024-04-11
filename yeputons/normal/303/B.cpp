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

int get(int minv, int maxv, int targ) {
  if (targ < minv) return minv;
  if (maxv < targ) return maxv;
  return targ;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int w, h, x, y, a, b;
  while (scanf("%d%d%d%d%d%d", &w, &h, &x, &y, &a, &b) >= 1) {
    int d = gcd(a, b);
    a /= d; b /= d;

    int cw = a, ch = b;
    for (;;) {
      int cw2 = cw + a, ch2 = ch + b;
      if (cw2 > w || ch2 > h) break;
      cw = cw2; ch = ch2;
    }
    int x1 = get(max(0, x - cw), min(w - cw, x), x - (cw / 2 + cw % 2));
    int y1 = get(max(0, y - ch), min(h - ch, y), y - (ch / 2 + ch % 2));
    printf("%d %d %d %d\n", x1, y1, x1 + cw, y1 + ch);
  }
  return 0;
}