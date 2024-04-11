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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, w, a, b;
  while (scanf("%d%d%d%d", &n, &w, &a, &b) >= 1) {
    a--, b--;
    int x1 = a % w, y1 = a / w;
    int x2 = b % w, y2 = b / w;

    int res = 0;
    if (y1 == y2) res = 1;
    else if (y1 + 1 == y2) {
      res = 1;
      if (x1 > 0 || (x2 < w - 1 && (b != n - 1))) res++;
    } else {
      if (x2 + 1 != x1) {
        res = 1;
        if (x1 > 0) res++;
        if (x2 < w - 1 && (b != n - 1)) res++;
      } else {
        res = 2;
      }
    }
    printf("%d\n", res);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}