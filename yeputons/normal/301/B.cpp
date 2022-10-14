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

int n, d;
vi as;
vi xs, ys;

bool can(int start) {
  vi ds(n, -1);
  ds[0] = start;
  vb red(n, false);

  for (;;) {
    int maxv = -1, mini = -1;
    for (int i = 0; i < n; i++)
      if (ds[i] > maxv && !red[i]) {
        maxv = ds[i];
        mini = i;
      }
    if (mini < 0) break;

    red[mini] = true;
    for (int b = 0; b < n; b++) {
      int ntim = maxv - d * (abs(xs[mini] - xs[b]) + abs(ys[mini] - ys[b]));
      if (ntim < 0) continue;
      ntim += as[b];
      ds[b] = max(ds[b], ntim);
    }
  }
  return ds[n - 1] >= 0;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  while (scanf("%d%d", &n, &d) >= 1) {
    as = vi(n, 0);
    for (int i = 1; i + 1 < n; i++)
      scanf("%d", &as[i]);
    xs = vi(n, 0);
    ys = vi(n, 0);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &xs[i], &ys[i]);

    int L = -1, R = 1e9;
    while (L + 1 < R) {
      int M = (L + R) / 2;
      if (can(M)) R = M;
      else L = M;
    }
    printf("%d\n", R);
  }
  return 0;
}