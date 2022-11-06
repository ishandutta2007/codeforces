#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

llint gcd(llint a, llint b) { return b == 0 ? a : gcd(b, a%b); }
llint lcm(llint a, llint b) { return a / gcd(a, b) * b; }

const int MAXN = 1e6 + 123;

int lA, lB;
llint nA, nB;

char A[MAXN], B[MAXN];

int frekA[MAXN][26];
int frekB[MAXN][26];

int main(void)
{
  cin >> nA >> nB;
  cin >> A; lA = strlen(A);
  cin >> B; lB = strlen(B);

  llint L = llint(nA) * lA;
  assert(L == llint(nB) * lB);
  llint mult = L / lcm(lA, lB);

  int g = gcd(lA, lB);
  memset(frekA, 0, sizeof frekA);
  memset(frekB, 0, sizeof frekB);

  for (int i = 0; i < lA; ++i)
    ++frekA[i%g][A[i] - 'a'];

  REP(i, lB)
    ++frekB[i%g][B[i] - 'a'];

  llint suma = 0;
  REP(i, g) {
    REP(j, 26) suma += llint(frekA[i][j]) * frekB[i][j];
  }

  cout << L - suma * mult << endl;
  return 0;
}