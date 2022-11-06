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

const llint mod = 1e9 + 7;
const int MAXN = 3e5;

llint fakt[MAXN];

llint inv[MAXN];
llint ifakt[MAXN];

inline llint binom(int n, int k) {
  return fakt[n] * ifakt[k] % mod * ifakt[n-k] % mod;
}

int main(void)
{
  fakt[0] = 1;
  FOR(i, 1, MAXN) fakt[i] = (fakt[i-1] * i) % mod;
  inv[1] = 1;
  FOR(i, 2, MAXN) {
    inv[i] = (mod - mod/i) * inv[mod%i] % mod;
    assert(i * inv[i] % mod == 1);
  }
  ifakt[0] = 1;
  FOR(i, 1, MAXN) ifakt[i] = ifakt[i-1] * inv[i] % mod;
  
  int nq; scanf("%d", &nq);
  REP(iq, nq) {
    static vector<int> ps; ps.clear();
    int n, f; scanf("%d %d", &n, &f);

    llint ans = 0;
    int tmp = n; for (int i = 2; i*i <= tmp; ++i) {
      if (tmp%i == 0) {
        while (tmp%i == 0) tmp /= i;
        ps.push_back(i);
      }
    }
    if (tmp > 1) ps.push_back(tmp);

    int nps = ps.size();
    REP(state, 1<<nps) {
      llint g = 1;
      int sign = 1; REP(i, nps) if (state&(1<<i)) { sign *= -1; g *= ps[i]; }

      if (n-g*f >= 0) {
        assert(n%g == 0);
        ans += sign * binom(n/g-1, f-1);

        if (ans < 0) ans += mod;
        if (ans >= mod) ans -= mod;
      }
    }

    cout << ans << endl;
  }

  return 0;
}