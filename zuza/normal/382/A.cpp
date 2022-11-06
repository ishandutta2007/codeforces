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
  char a[123], b[123], c[123];

  a[0] = 0; scanf("%[^|]", a);
  b[0] = 0; scanf("|%[^\n]", b);
  scanf("%s", c);

  int alen = strlen(a);
  int blen = strlen(b);
  int clen = strlen(c);
  bool ok = false;

  int ladd = -1, radd = -1;
  if (alen < blen) {
    ladd = blen-alen;
    radd = 0;
    if (!(ladd > clen)) {
      if (!((clen - ladd) % 2 == 1)) {
        int tmp = (clen - ladd) / 2;
        ladd += tmp;
        radd = tmp;
        ok = true;
      }
    }
  } else { 
    radd = alen - blen;
    ladd = 0;
    if (!(radd > clen)) {
      if (!((clen - radd) % 2 == 1)) {
        int tmp = (clen - radd) / 2;
        radd += tmp;
        ladd += tmp;
        ok = true;
      }
    }
  }

  if (!ok) {
    puts("Impossible");
  } else {
    assert(ladd + radd == clen);
    REP(i, alen) putchar(a[i]);
    int ptr = 0; REP(i, ladd) { putchar(c[ptr]); ++ptr; }
    putchar('|');
    REP(i, blen) putchar(b[i]);
    REP(i, radd) { putchar(c[ptr]); ++ptr; }
    putchar('\n');
  }
  return 0;
}