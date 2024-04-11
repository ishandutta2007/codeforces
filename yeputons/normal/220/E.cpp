
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
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

class fenv_tree {
  static int f(int x) {
    #ifdef DEBUG
    int rv = x ^ (x & (x - 1));
    assert(rv == (x & -x));
    #endif
    return x & -x;
  }
  vi tr;

  public:
  fenv_tree(int n) : tr(n + 1, 0) {}
  void add(int x, int v) {
    assert(0 <= x && x + 1 < sz(tr));
    for (x++; x < sz(tr); x += f(x))
      tr[x] += v;
  }
  int get(int x) {
    int res = 0;
    assert(0 <= x && x + 1 < sz(tr));
    for (; x > 0; x -= f(x))
      res += tr[x];
    return res;
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  ll maxk;
  while (scanf("%d%I64d", &n, &maxk) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vi vals = as;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < n; i++)
      as[i] = lower_bound(vals.begin(), vals.end(), as[i]) - vals.begin();

    int vcnt = sz(vals);

    fenv_tree head(vcnt), tail(vcnt);
    int r = n;
    ll curk = 0;
    ll ans = 0;

    for (int l = 0; l < n; l++) {
      curk += head.get(vcnt - 1 - as[l]);
      curk += tail.get(as[l]);
      head.add(vcnt - 1 - as[l], 1);

      while (l + 1 < r && curk <= maxk) {
        r--;
        curk += head.get(vcnt - 1 - as[r]);
        curk += tail.get(as[r]);
        tail.add(as[r], 1);
      }
      while (r < n && (curk > maxk || l >= r)) {
        curk -= head.get(vcnt - 1 - as[r]);
        curk -= tail.get(as[r]);
        tail.add(as[r], -1);
        r++;
      }
//      eprintf("l=%d, r=%d; curk=%I64d\n", l, r, curk);
      ans += n - r;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}