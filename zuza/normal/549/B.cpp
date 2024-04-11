#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 123;

int n;
int A[MAXN][MAXN];
int lose[MAXN];
int have[MAXN];

int main(void) {
  scanf("%d", &n);

  REP(i, n) {
    REP(j, n) {
      char c; scanf(" %c", &c);
      A[i][j] = (c == '1') ? 1 : 0;
    }
  }
  REP(i, n) scanf("%d", lose+i);
  memset(have, 0, sizeof have);

  vector<int> out;
  static int kol[MAXN]; memset(kol, 0, sizeof kol);
  while (true) {
    bool ok = true;
    REP(i, n) if (kol[i] == lose[i]) {
      out.push_back(i);
      REP(j, n) kol[j] += A[i][j];
      ok = false;
      break;
    }

    if (ok) {
      int sz = out.size();
      printf("%d\n", sz);
      for (int x : out) printf("%d ", x+1);
      putchar('\n');

      exit(0);
    }
  }
  return 0;
}