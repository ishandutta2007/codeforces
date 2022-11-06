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
  const int MAXLEN = 1e6 + 123;
  static char buff[MAXLEN]; scanf("%s", buff);
  static int frek[10] = {0};
  int len = strlen(buff);
  REP(i, len) ++frek[buff[i] - '0'];

  vector<int> V = {1, 6, 8, 9};
  REP(i, 4) --frek[V[i]];

  do {
    int rem = 0;
    REP(i, 4) rem = (rem*10 + V[i]) % 7;
    REP(i, 10) REP(j, frek[i]) rem = (rem*10 + i) % 7;
    if (rem == 0) {
      REP(i, 4) printf("%d", V[i]);
      REP(i, 10) REP(j, frek[i]) printf("%d", i);
      putchar('\n');
      exit(0);
    }
  } while (next_permutation(V.begin(), V.end()));

  puts("0");
  return 0;
}