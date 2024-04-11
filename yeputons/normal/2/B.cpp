#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define sqr(a, b) ((a) * (a))
#define INF 2000000000
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef double dbl;
typedef vector<dbl> vdbl;

typedef long long ll;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

int n;
string getAns(vector<vector<char> > fr) {
  string ret = "";
  int y = n - 1, x = n - 1;
  while (fr[y][x]) {
    ret = fr[y][x] + ret;
    switch (fr[y][x]) {
    case 'D': y--; break;
    case 'R': x--; break;
    default: assert(false);
    }
  }
  return ret;
}

int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    vvi p[2] = { vvi(n, vi(n, 0)), vvi(n, vi(n, 0)) };
    vvb zero = vvb(n, vb(n, false));
    for (int y = 0; y < n; y++)
      for (int x = 0; x < n; x++) {
        int v; scanf("%d", &v);
        if (!v) { zero[y][x] = true; continue; }
        for (; !(v % 2); p[0][y][x]++) v /= 2;
        for (; !(v % 5); p[1][y][x]++) v /= 5;
      }

    int bans = INF; string bpath = "";
    for (int step = 0; step < 2; step++) {
      vvi dyn(n, vi(n, INF));
      vector<vector<char> > fr(n, vector<char>(n, 0));

      dyn[0][0] = p[step][0][0];
      for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++) {
          if (!y && !x) continue;
          if (zero[y][x]) continue;

          if (y && (dyn[y - 1][x] < dyn[y][x])) {
            dyn[y][x] = dyn[y - 1][x];
            fr[y][x] = 'D';
          }
          if (x && (dyn[y][x - 1] < dyn[y][x])) {
            dyn[y][x] = dyn[y][x - 1];
            fr[y][x] = 'R';
          }
          dyn[y][x] += p[step][y][x];
        }
      if (bans > dyn[n - 1][n - 1]) {
        bans = dyn[n - 1][n - 1]; bpath = getAns(fr);
      }
    }
    if (bans > 1) {
      vector<vector<char> > fr(n, vector<char>(n, 0));
      for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++) {
          if (!y && !x) continue;
          fr[y][x] = y ? 'D' : 'R';
          if (y && zero[y - 1][x]) zero[y][x] = true, fr[y][x] = 'D';
          if (x && zero[y][x - 1]) zero[y][x] = true, fr[y][x] = 'R';
        }
      if (zero[n - 1][n - 1]) {
        bans = 1; bpath = getAns(fr);
      }
    }

    printf("%d\n%s\n", bans, bpath.c_str());

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}