#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

llint powmod(llint b, llint e, llint mod) {
  llint ans = 1, p2 = b;
  for (; e; e >>= 1, p2 = p2*p2 % mod)
    if (e&1)
      ans = ans*p2 % mod;
  return ans;
}

int main(void) {
  const int MAXLEN = 1e5 + 123;
  const int mod = 1e9 + 7;
  static char buff[MAXLEN];

  int len; scanf("%d", &len);
  scanf("%s", buff);

  map<char, int> frek;
  map<int, int> vals;

  REP(i, len) ++frek[buff[i]];
  for (auto p : frek) vals[p.second]++;
  printf("%d\n", (int)powmod(vals.rbegin()->second, len, mod));
  return 0;
}