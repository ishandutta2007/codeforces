#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
  ~__timestamper(){
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

void relax(int &a, int b) { a = max(a, b); }

int h, w;
vvi calc(const vvi &mat) {
  vvi dyn(h, vi(w, 0));
  for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++) {
    if (x) relax(dyn[y][x], dyn[y][x - 1]);
    if (y) relax(dyn[y][x], dyn[y - 1][x]);
    dyn[y][x] += mat[y][x];
  }
  return dyn;
}
void revy(vvi &a) {
  reverse(a.begin(), a.end());
}
void revx(vvi &a) {
  for (vi &b : a)
    reverse(b.begin(), b.end());
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  while (scanf("%d%d", &h, &w) == 2) {
    vvi mat(h, vi(w));
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      scanf("%d", &mat[y][x]);

    vvi dyn[2][2];
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        dyn[a][b] = calc(mat);

        revx(dyn[0][0]); revx(dyn[0][1]); revx(dyn[1][0]); revx(dyn[1][1]);
        revx(mat);
      }
      revy(dyn[0][0]); revy(dyn[0][1]); revy(dyn[1][0]); revy(dyn[1][1]);
      revy(mat);
    }

    int ans = 0;
    for (int y = 1; y + 1 < h; y++)
    for (int x = 1; x + 1 < w; x++) {
      {
        int cans = 0;
        cans += dyn[0][0][y - 1][x];
        cans += dyn[1][1][y + 1][x];
        cans += dyn[1][0][y][x - 1];
        cans += dyn[0][1][y][x + 1];
        ans = max(ans, cans);
      }
      {
        int cans = 0;
        cans += dyn[0][0][y][x - 1];
        cans += dyn[1][1][y][x + 1];
        cans += dyn[1][0][y + 1][x];
        cans += dyn[0][1][y - 1][x];
        ans = max(ans, cans);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}