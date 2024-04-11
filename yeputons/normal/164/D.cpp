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

struct pt {
  int x, y;
  pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }

  int dist2() const { return x * x + y * y; }
};

const int MAXN = 1000;

int todel[MAXN];

int es[MAXN][MAXN];
int ecnt[MAXN];

int n;
bool go(int pos, int rem) {
  if (pos >= n) {
    for (int i = 0; i < n && rem; i++)
      if (!todel[i]) {
        todel[i] = pos + 1;
        rem--;
      }
    return true;
  }
  if (todel[pos] || !ecnt[pos]) return go(pos + 1, rem);

  // All neigbours
  int need = 0;
  for (int i = 0; i < ecnt[pos]; i++) {
    int b = es[pos][i];
    if (todel[b]) continue;
    todel[b] = pos + 1;
    need++;
  }
  if (need <= rem && go(pos + 1, rem - need))
    return true;

  for (int i = 0; i < ecnt[pos]; i++) {
    int b = es[pos][i];
    if (todel[b] == pos + 1) todel[b] = 0;
  }

  // Me
  if (rem > 0 && need > 1) {
    todel[pos] = pos + 1;
    if (go(pos + 1, rem - 1)) return true;
    todel[pos] = 0;
  }  
  return false;
}

int k;
int ds[MAXN][MAXN];

bool check(int maxd) {
  eprintf("check(%d)\n", maxd);
  memset(ecnt, 0, sizeof ecnt);
  for (int a = 0; a < n; a++)
  for (int b = 0; b < n; b++) if (ds[a][b] > maxd) {
    es[a][ecnt[a]++] = b;
  }
  memset(todel, 0, sizeof todel);
  return go(0, k);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d", &n, &k) >= 1) {
    vector<pt> pts(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &pts[i].x, &pts[i].y);

    if (k + 1 == n) {
      for (int i = 0; i < k; i++)
        printf("%d%c", i + 1, "\n "[i + 1 < k]);
      continue;
    }

    vi ads;
    for (int a = 0; a < n; a++) {
      ds[a][a] = 0;
      for (int b = a + 1; b < n; b++) {
        ads.pb(ds[a][b] = ds[b][a] = (pts[b] - pts[a]).dist2());
      }
    }
    sort(ads.begin(), ads.end());
    ads.erase(unique(ads.begin(), ads.end()), ads.end());

    int L = 0, R = sz(ads) - 1;
    if (check(ads[L])) R = L;
    assert(check(ads[R]));

    while (L + 1 < R) {
      int M = (L + R) / 2;
      if (check(ads[M])) R = M;
      else L = M;
    }
    bool res = check(ads[R]);
    assert(res);

    for (int i = 0; i < n; i++)
      if (todel[i]) printf("%d ", i + 1);
    printf("\n");
  }
  return 0;
}