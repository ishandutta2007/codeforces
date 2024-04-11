#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define VAR(name, val) __typeof(val) name=(val)
#define FORC(it, V) for(VAR(it, (V).begin()); it != (V).end(); ++it)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int n, k; scanf("%d %d", &n, &k);
  int sum = 0;
  REP(i, n) {
    static char buff[100]; scanf("%s", buff);
    bool ok = true;
    static bool has[100];
    memset(has, 0, sizeof has);
    for (char* ptr = buff; *ptr; ++ptr)
      has[*ptr - '0'] = true;
    for (int i = 0; i <= k; ++i)
      if (!has[i])
        ok = false;
    sum += ok;
  }
  printf("%d\n", sum);
  return 0;
}