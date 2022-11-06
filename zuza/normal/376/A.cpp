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

typedef long long llint;

int main(void)
{
  const int MAXN = 1e6 + 123;
  static char buff[MAXN]; scanf("%s", buff);
  int len = strlen(buff);

  llint R = 0;
  int dulj = -1;
  for (int i = 0; i < len; ++i) {
    if (dulj != -1) ++dulj;
    if (buff[i] == '^') dulj = 0;
    if (isdigit(buff[i]) && dulj != -1) R += dulj * (buff[i] - '0');
  }

  llint L = 0;
  dulj = -1;
  for (int i = len - 1; i >= 0; --i) {
    if (dulj != -1) ++dulj;
    if (buff[i] == '^') dulj = 0;
    if (isdigit(buff[i]) && dulj != -1) L += dulj * (buff[i] - '0');
  }

  if (L < R) puts("right");
  else if (L > R) puts("left");
  else puts("balance");

  return 0;
}