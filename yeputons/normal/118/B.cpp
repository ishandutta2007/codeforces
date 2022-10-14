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

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    vvi vals(2 * n + 1, vi(2 * n + 1, -1));
    int xc = n, yc = n;
    for (int y = 0; y <= 2 * n; y++)
      for (int x = 0; x <= 2 * n; x++) {
        vals[y][x] = abs(x - xc) + abs(y - yc);
        if (vals[y][x] > n)
          vals[y][x] = -1;
      }
    for (int y = 0; y < sz(vals); y++) {
      for (int x = 0; x < sz(vals[y]); x++) {
        if (vals[y][x] < 0 && x >= n)
          break;
        if (x) printf(" ");
        if (vals[y][x] >= 0)
          printf("%d", n - vals[y][x]);
        else
          printf(" ");
      }
      printf("\n");
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}