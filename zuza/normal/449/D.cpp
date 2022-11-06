#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

#include <bitset>
#include <functional>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int BITS = 20;
const int MAXN = 1<<BITS;
const llint mod = 1e9 + 7;

void subsets(int* A, int nb) {
  if (nb == 0) return ;

  int half = 1 << (nb-1);
  subsets(A, nb-1);
  subsets(A+half, nb-1);

  REP(i, half)tie(A[i], A[i+half]) = make_tuple(A[i]+A[i+half], A[i+half]);
}

int main(void) {
  static int frek[MAXN]; memset(frek, 0, sizeof frek);
  int n; scanf("%d", &n);
  REP(i, n) {
    int x; scanf("%d", &x);
    ++frek[x];
  }

  static llint pow2[MAXN]; REP(i, MAXN) pow2[i] = (i == 0) ? 1 : pow2[i-1] * 2 % mod;
  subsets(frek, BITS);

  llint ans = 0;
  REP(st, MAXN) {
    int sign = 1; REP(i, BITS) if (st&(1<<i)) sign = -sign;
    ans = (ans + sign * pow2[frek[st]]) % mod;
  }

  printf("%lld\n", (ans%mod + mod)%mod);
  return 0;
}