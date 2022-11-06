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

struct S {
  llint u;
  bool c;
  bool a;

  friend S operator + (const S& a, const S& b) {
    return {a.u + b.u + a.a*b.c, a.c, b.a};
  }
};

bool construct(int len, S orig, bool doit) {
  int left = len;
  left -= orig.c;
  left -= orig.a;
  left -= orig.u * 2;
  if (left >= 0) {
    if (doit) {
      if (orig.c) putchar('C');
      REP(i, left) putchar('Z');
      REP(i, orig.u) printf("AC");
      if (orig.a) putchar('A');
      putchar('\n');
    }
    return true;
  }
  return false;
}

int main(void)
{
  int k, x, alen, blen; scanf("%d %d %d %d", &k, &x, &alen, &blen);

  S A, B;
  REP(u1, 51) REP(u2, 51) REP(c1, 2) REP(c2, 2) REP(a1, 2) REP(a2, 2) {
    A.u = u1; B.u = u2;
    A.c = c1; B.c = c2;
    A.a = a1; B.a = a2;

    S origA = A;
    S origB = B;

    S res;
    for (int i = 3; i <= k; ++i) {
      res = A + B;
      if (res.u > x) { res.u = -1; break; }
      A = B;
      B = res;
    }

    if (res.u == x) {
      if (construct(alen, origA, false))
        if (construct(blen, origB, false)) {
          construct(alen, origA, true);
          construct(blen, origB, true);
          exit(0);
        }
    }
  }

  puts("Happy new year!");
  return 0;
}