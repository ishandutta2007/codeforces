#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cstring>
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
typedef vector<string> vs;

#define MAXA 100000
//100000
#define MAXB 30

char mem[MAXA + 1][MAXB + 1];
int n;

int mpow(int a, int b) {
  ll res = 1;
  for (; b && (res < n); b--)
    res *= (ll)a;
  return min(res, (ll)n);
}

int getMem(int a, int b) {
  if (a > MAXA)
    if (b > 1) {
      assert(mpow(a, b) >= n);
      return 1;
    } else {
      assert(b == 1);
      assert(mpow(a, b) < n);
      assert(mpow(a, b + 1) >= n);
      return !((n - a) & 1);
    }
  if (b > MAXB) {
    assert(mpow(a, b) >= n);
    return 1;
  }
  assert(mem[a][b] >= 0);
  return mem[a][b];
}

int main() {
  #ifdef DEBUG
  freopen("stdin", "r", stdin);
  freopen("stdout", "w", stdout);
  #endif

  int sa, sb;
  while (scanf("%d%d%d", &sa, &sb, &n) >= 3) {
    memset(mem, -1, sizeof mem);

    for (int a = MAXA; a >= 2; a--) {
      for (int b = MAXB; b >= 1; b--) {
        if (mpow(a, b) >= n) {
          mem[a][b] = 1;
          continue;
        }

        mem[a][b] = !getMem(a + 1, b) || !getMem(a, b + 1);
      }
    }
    if (sa == 1) {
      int res = -1;
      for (int x = MAXA; x >= sb; x--) {
        if (res == 0 || !getMem(2, x)) {
          res = 1;
        } else if (res == -1) {
          res = -1;
        } else {
          assert(res == 1);
          res = 0;
        }
      }
      switch (res) {
      case -1: printf("Missing\n"); break;
      case 0: printf("Stas\n"); break;
      case 1: printf("Masha\n"); break;
      }
    } else 
      printf(getMem(sa, sb) ? "Masha\n" : "Stas\n");

    next:;
    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}