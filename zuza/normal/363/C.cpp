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

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

const int MAXLEN = 200123;
char buff[MAXLEN];

int main(void)
{
  scanf("%s", buff);
  int len = strlen(buff);
  int ptr = 0;
  bool dup_bef = false;

  while (ptr < len) {
    char c = buff[ptr];
    int kol = 0;
    while (c == buff[ptr]) { ++ptr; ++kol; }

    if (kol >= 2) kol = 2;
    if (kol == 2 && dup_bef) {
      kol = 1;
      dup_bef = false;
    } else if (kol == 2) {
      dup_bef = true;
    } else {
      assert(kol == 1);
      dup_bef = false;
    }

    REP(i, kol) putchar(c);
  }

  putchar('\n');
  return 0;
}