#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define VAR(name, val) __typeof(val) name=(val)
#define FORC(it, V) for(VAR(it, (V).begin()); it != (V).end(); ++it)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int A; scanf("%d", &A);

  static char buff[4012]; scanf("%s", buff);
  int len = strlen(buff);

  static llint mapper[4012 * 9];
  llint svi = 0;
  llint suma_svih = 0;
  REP(i, len) suma_svih += buff[i] - '0';

  for (int i = 0; i < len; ++i) {
    int suma = 0;
    for (int j = i; j < len; ++j) {
      suma += buff[j] - '0';
      ++mapper[suma];
      ++svi;
    }
  }
  
  // d == 0?
  llint sol = 0;
  for (llint d = 1; d*d <= A; ++d) {
    if (A%d == 0 && d <= suma_svih && A/d <= suma_svih) {
      llint add = mapper[d] * mapper[A/d];
      sol += add;
      if (d*d != A) {
        sol += add;
      }
    }
  }
  
  if (A == 0) {
    sol = 2*mapper[0]*svi - mapper[0] * mapper[0];
  }
  cout << sol << endl;
  return 0;
}