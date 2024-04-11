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

int k;
vvb busy;
int xc, yc;

struct Ans { int x, y1, y2; };
int getF(Ans a) {
  int r = 0;
  eprintf("getF(%d, %d-%d)\n", a.x, a.y1, a.y2);
  for (int y = a.y1; y <= a.y2; y++)
    if (busy[a.x][y]) return INF;
    else r += abs(a.x - xc) + abs(y - yc);
  return r;
}
Ans getAns(int m) {
  Ans a; int bans = INF;
  a.x = INF;

  Ans ca;
  for (int sx = 0; sx < k; sx++) {
    for (int sy = 0; sy + m <= k; sy++) {
      ca.x = sx; ca.y1 = sy; ca.y2 = sy + m - 1;
      int cans = getF(ca);
      if (cans < bans) {
        bans = cans;
        a = ca;
      }
    }
  }
  if (bans < INF) {
    for (int y = a.y1; y <= a.y2; y++)
      busy[a.x][y] = true;
  }
  return a;
}

int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d%d", &n, &k) >= 2) {
    xc = yc = k >> 1;

    busy = vvb(k, vb(k, false));
    for (int i = 0; i < n; i++) {
      int m; scanf("%d", &m);
      Ans a = getAns(m);
      if (a.x < k) {
        printf("%d %d %d\n", a.x + 1, a.y1 + 1, a.y2 + 1);
      } else
        printf("-1\n");
    }

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}