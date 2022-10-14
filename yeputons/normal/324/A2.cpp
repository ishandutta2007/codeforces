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

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vll sums(n + 1, 0);
    for (int i = 0; i < n; i++)
      sums[i + 1] = sums[i] + max(0, as[i]);

    map<int, pair<ll, int> > was;
    ll ans = -9e18;
    int al = -1, ar = -1;
    for (int i = 0; i < n; i++) {
      if (was.count(as[i])) {
        ll cans = 0;
        cans += as[i] * 2LL;
        cans += sums[i] - was[as[i]].first;
        if (cans > ans) {
          ans = cans;
          al = was[as[i]].second;
          ar = i;
        }

        was[as[i]] = min(was[as[i]], mp(sums[i + 1], i));
      } else {
        was[as[i]] = mp(sums[i + 1], i);
      }
    }
    vi res;
    for (int i = 0; i < al; i++) res.pb(i);
    for (int i = al + 1; i < ar; i++)
      if (as[i] < 0)
        res.pb(i);
    for (int i = ar + 1; i < n; i++)
      res.pb(i);

    printf("%I64d %d\n", ans, sz(res));
    for (int i = 0; i < sz(res); i++) {
      if (i) printf(" ");
      printf("%d", res[i] + 1);
    }
    printf("\n");
  }
  return 0;
}