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

int main(void) {
  char buff[123]; scanf("%*d %s", buff);
  int frek[26] = {0};
  for (char *ptr = buff; *ptr; ++ptr)
    frek[ tolower(*ptr) - 'a' ] = true;
  bool ok = true;
  REP(i, 26) ok &= (frek[i] == true);
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}