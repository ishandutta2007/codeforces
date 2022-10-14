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

const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int mul(int a, int b) { return ll(a) * b % MOD; }
int pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) res = mul(res, a);
  return res;
}

const int MAXN = 1e5 + 10;
int facs[MAXN + 1];
int ifacs[MAXN + 1];
int C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return mul(facs[n], mul(ifacs[k], ifacs[n - k]));
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  facs[0] = 1;
  ifacs[0] = 1;

  for (int i = 1; i <= MAXN; i++) {
    facs[i] = mul(facs[i - 1], i);
    ifacs[i] = pow(facs[i], MOD - 2);
    assert(mul(facs[i], ifacs[i]) == 1);
  }

  vi ls;
  for (int len = 1; len <= 9; len++) {
    for (int msk = 0; msk < (1 << len); msk++) {
      int x = 0;
      for (int i = 0; i < len; i++)
        x = x * 10 + ((msk & (1 << i)) ? 7 : 4);
      ls.pb(x);
    }
  }
  sort(ls.begin(), ls.end());
  int m = sz(ls);

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    int cnt0 = 0;
    vi cnts(m, 0);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      int id = lower_bound(ls.begin(), ls.end(), x) - ls.begin();
      if (id == m || ls[id] != x) cnt0++;
      else cnts[id]++;
    }

    vvi dyn(m + 1, vi(m + 1, 0));
    dyn[m][0] = 1;
    for (int i = m - 1; i >= 0; i--)
    for (int rem = 0; rem <= m; rem++) {
      dyn[i][rem] = dyn[i + 1][rem];
      if (rem)
        add(dyn[i][rem], mul(dyn[i + 1][rem - 1], cnts[i]));
    }
    
    int ans = 0;
    for (int clen = k; clen >= 0; clen--)
      if (clen <= m)
        add(ans, mul(C(cnt0, k - clen), dyn[0][clen]));
    printf("%d\n", ans);
  }
  return 0;
}