#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void)
{
  int n; scanf("%d", &n);
  vector<double> V;
  REP(i, n) {
    double x; scanf("%lf", &x);
    V.push_back(x);
  }
  sort(V.begin(), V.end());
  
  double ans = 0;
  REP(a, n) FOR(b, a+1, n+1) {
    double suma = 0;

    FOR(i, a, b) {
      double p = 1;
      FOR(j, a, b) p *= (i == j) ? V[j] : (1-V[j]);
      suma += p;
    }

    if (suma > ans) ans = suma;
  }

  printf("%.12lf\n", ans);
  return 0;
}