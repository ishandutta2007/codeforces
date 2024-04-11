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
  int n; scanf("%d", &n);
  int pos = 0;

  REP(i, n) {
    if (pos < i) { putchar('R'); ++pos; }
    assert(pos == i);
    int kol; scanf("%d", &kol);
    bool first = true;

    REP(j, kol) {
      if (!first) {
        char dir = (i == 0) ? 'R' : 'L';
        char other = (i == 0) ? 'L' : 'R';
        putchar(dir); putchar(other);
      } else first = false;
      putchar('P');
    }
  }

  putchar('\n');
  return 0;
}