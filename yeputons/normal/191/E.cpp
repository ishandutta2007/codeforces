#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "std"

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const ll INF = 1e18;
class segm_tree {
  const vll &vals;
  int off;
  vi tr;
  
  public:
  segm_tree(const vll &_vals) : vals(_vals) {
    off = 1; while (off < sz(vals)) off <<= 1;
    tr = vi(2 * off);
  }
  void add(ll x, int v) {
    x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    for (x += off; x >= 1; x >>= 1)
      tr[x] += v;
  }
  int getCnt(ll l, ll r) {
    l = lower_bound(vals.begin(), vals.end(), l) - vals.begin();
    r = upper_bound(vals.begin(), vals.end(), r) - vals.begin() - 1;
    l += off; r += off;
    int res = 0;
    while (l <= r) {
      if (l & 1) res += tr[l++];
      if (!(r & 1)) res += tr[r--];
      l >>= 1; r >>= 1;
    }
    return res;
  }
};

int n;
vll ss;
vll vals;

ll getCnt(ll maxs) {
  segm_tree tr(vals);
  for (int i = 0; i <= n; i++)
    tr.add(ss[i], 1);
  
  ll res = 0;
  for (int l = 0; l <= n; l++) {
    tr.add(ss[l], -1);
    // x - ss[l] >= maxs
    // x <= maxs + ss[l]
    res += tr.getCnt(maxs + ss[l], INF);
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif
  
  ll k;
  while (scanf("%d%I64d", &n, &k) >= 2) {
    vll as(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &as[i]);
      
    ss = vll(n + 1);
    for (int i = 0; i < n; i++)
      ss[i + 1] = ss[i] + as[i];
      
    vals = ss;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
      
    ll L = -INF, R = INF;
    assert(getCnt(L) >= k);
    assert(getCnt(R) < k);
    while (L + 1 < R) {
      ll M = (L + R) / 2;
      if (getCnt(M) >= k) L = M;
      else R = M;
    }
    printf("%I64d\n", L);
  }
  return 0;
}