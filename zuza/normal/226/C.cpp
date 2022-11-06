#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

struct Mat {
  llint a[2][2];
};

Mat mult(Mat a, Mat b, llint mod) {
  Mat ans = {0, 0, 0, 0};
  REP(i, 2) REP(j, 2) REP(k, 2) {
    ans.a[i][j] += a.a[i][k] * b.a[k][j];
    ans.a[i][j] %= mod;
  }
  return ans;
}

Mat powermod(Mat b, llint e, llint mod) {
  Mat p2 = b;
  Mat ans; REP(i, 2) REP(j, 2) ans.a[i][j] = (i==j);
  for (; e; e >>= 1) {
    if (e&1) ans = mult(ans, p2, mod);
    p2 = mult(p2, p2, mod);
  }
  return ans;
}

llint fib(llint e, llint mod) {
  Mat base = {0, 1, 1, 1};
  Mat ret = powermod(base, e, mod);
  return ret.a[0][1];
}

int main(void)
{
  llint m, l, r, k; cin >> m >> l >> r >> k;

  llint max_g = 1;
  
  for (llint g = 1; g <= r; ) {
    llint next = 1e18;
    if (g <= r) next = min(next, r/(r/g)+1);
    if (g <= l-1) next = min(next, (l-1)/((l-1)/g)+1);
    g = next;
    if (r/(g-1) - (l-1)/(g-1) >= k) max_g = (g-1);
  }

  cout << fib(max_g, m) << endl;
  return 0;
}