#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1e6 + 123;
const llint mod = 1e9 + 7;

vector<int> calc_Z(const char* S, int len) {
  vector<int> Z(len);
  Z[0] = len;
  int lo = 1, hi = 1;

  FOR(i, 1, len) {
    int z = 0;
    if (i < hi) z = min(Z[i-lo], hi-i);
    while (i+z < len && S[z] == S[i+z]) ++z;
    Z[i] = z;
    if (i+z > hi) lo = i, hi = i+z;
  }

  return Z;
}

int main(void) {
  int nL, nk; scanf("%d %d", &nL, &nk);

  char S[MAXN]; scanf("%s", S);
  int len = strlen(S);
  vector<int> Z = calc_Z(S, len);

  int last = -1e9;
  int nq = nL;
  llint p = 1;

  REP(i, nk) {
    int a; scanf("%d", &a); --a;

    int diff = a - last;
    nq -= len;
    if (diff < len) {
      nq += len-diff;
      if (Z[diff] != len-diff) p = 0;
    }

    last = a;
  }

  REP(i, nq) p = p*26 % mod;
  printf("%lld\n", p);

  return 0;
}