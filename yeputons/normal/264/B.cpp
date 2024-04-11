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

const int MAXV = 1e5 + 10;
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vb has(MAXV + 1, false);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      has[x] = true;
    }

    vi dyn(MAXV + 1, 0);
    int ans = 1;
    for (int i = 2; i <= MAXV; i++) if (has[i]) {
      int cv = 0;
      for (int x = 2; x * x <= i; x++) if (i % x == 0) {
        cv = max(cv, dyn[x]);
        cv = max(cv, dyn[i / x]);
      }
      cv++;
      for (int x = 1; x * x <= i; x++) if (i % x == 0) {
        dyn[x] = max(dyn[x], cv);
        dyn[i / x] = max(dyn[i / x], cv);
      }
    }
    ans = max(ans, *max_element(dyn.begin(), dyn.end()));
    printf("%d\n", ans);
  }
  return 0;
}