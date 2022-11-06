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
  llint money; cin >> money;
  llint m, k; cin >> m >> k; money /= k;

  llint L = 1, R = 10;
  llint start = m;

  for (int digs = 1; ; ++digs) {
    llint kol = max(0LL, R - max(L, start));
    llint add = min(kol, money / digs);

    money -= add*digs;
    start += add;

    if (add < kol) break;
    L *= 10; R *= 10;
  }

  cout << start - m << endl;
  return 0;
}