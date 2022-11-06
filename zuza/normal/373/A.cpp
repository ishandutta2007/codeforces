#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int k; scanf("%d", &k);
  map<int, int> frek;
  bool ok = true;

  REP(i, 4) {
    REP(j, 4) {
      char c; scanf(" %c", &c);
      if (isdigit(c)) if (++frek[c - '0'] > 2*k) ok = false;
    }
  }

  puts(ok ? "YES" : "NO");
  return 0;
}