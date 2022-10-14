#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#ifdef DEBUG
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
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

  int n, maxd;
  while (scanf("%d%d", &n, &maxd) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    ll ans = 0;
    for (int l = 0; l < n; l++) {
      int cnt = upper_bound(as.begin(), as.end(), as[l] + maxd) - as.begin() - l - 1;
      if (cnt < 2) continue;
      ans += ll(cnt) * (cnt - 1) / 2;
    }

    printf("%I64d\n", ans);
  }
  return 0;
}