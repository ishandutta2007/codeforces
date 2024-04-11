#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int m, k;
  while (scanf("%d%d", &m, &k) >= 1) {
    vi ds(m), ss(m);
    for (int i = 0; i < m; i++) scanf("%d", &ds[i]);
    for (int i = 0; i < m; i++) scanf("%d", &ss[i]);

    int cful = 0;
    int ctim = 0;
    int maxs = 0;

    for (int i = 0; i < m; i++) {
      cful += ss[i];
      maxs = max(maxs, ss[i]);

      while (cful < ds[i]) {
        ctim += k;
        cful += maxs;
      }
      cful -= ds[i];
      ctim += ds[i];
    }
    printf("%d\n", ctim);
  }
  return 0;
}