#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <complex>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define EACH(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FOR(i,k,n) for (int i=(k);i<(int)(n);i++)
#define FEQ(i,k,n) for(int i=(k);i<=(int)(n);i++)
typedef long long ll;
typedef complex<double> P;

int main()
{
  int n, x[1000];
  while (scanf("%d", &n) != EOF) {
    REP(i, n) scanf("%d", x+i);

    bool intersect = false;
    REP(i, n - 1) {
      for (int j = i + 1; j < n - 1; j++) {
        int x0 = min(x[i], x[i + 1]), x1 = max(x[i], x[i + 1])
          , y0 = min(x[j], x[j + 1]), y1 = max(x[j], x[j + 1]);
        if ((x0 < y0 && y0 < x1 && x1 < y1) ||
            (y0 < x0 && x0 < y1 && y1 < x1) ||
            (x0 == y0 && x1 == y1)) {
          intersect = true;
          break;
        }
      }
      if (intersect) break;
    }
    puts(intersect ? "yes" : "no");
  }

  return 0;
}