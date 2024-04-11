#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define VAR(name, val) __typeof(val) name=(val)
#define FORC(it, V) for(VAR(it, (V).begin()); it != (V).end(); ++it)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXN = 123123;
int n;
int A[MAXN];

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", A+i);

  int maks = min(n, 2);
  for (int i = 0; i < n; ) {
    llint a = A[i];
    llint b = A[i+1];
    int len = 2;
    int j; for (j = i+2; j < n; ++j) {
      if (a+b == A[j]) {
        ++len;
        if (len > maks) maks = len;
        a = b;
        b = A[j];
      } else {
        break;
      }
    }
    i = j-1;
  }
  printf("%d\n", maks);
  return 0;
}