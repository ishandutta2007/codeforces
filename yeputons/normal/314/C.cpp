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

const int MOD = 1e9 + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

const int MAXV = 1e6 + 10;

class fenv_tree {
  static int f(int x) { return x & -x; }
  vector<int> tr;

  public:
  fenv_tree(int n) : tr(n + 1) {}
  void add(int x, const int &val) {
    for (x++; x < sz(tr); x += f(x))
      madd(tr[x], val);
  }
  int get(int x) {
    int res = 0;
    for (x++; x > 0; x -= f(x))
      madd(res, tr[x]);
    return res;
  }
};

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

    int ans = 0;

    vi dyn(n);
    fenv_tree sums(MAXV + 1);
    vi off(MAXV + 1, 0);
    vi last(MAXV + 1, -1);

    for (int i = 0; i < n; i++) {
      int cval = sums.get(as[i]);
      madd(cval, off[as[i]]);
      madd(off[as[i]], MOD - cval);

      #ifdef DEBUG
      {
        int tmp = 0;
        int st = max(0, last[as[i]]), en = i;
        for (int i2 = st; i2 < en; i2++)
          if (as[i] >= as[i2])
            madd(tmp, dyn[i2]);
        eprintf("i=%d, %d..%d; val=%d, %d==%d\n", i, st, en, as[i], tmp, cval);
        assert(tmp == cval);
      }
      #endif

      if (last[as[i]] < 0) {
        madd(cval, 1);
      }

      dyn[i] = mmul(cval, as[i]);
      madd(ans, dyn[i]);

      last[as[i]] = i;
      sums.add(as[i], dyn[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}