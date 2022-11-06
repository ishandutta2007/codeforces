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

const int MAXN = 5012;
int R, S;

char grid[MAXN][MAXN];
int Desno[MAXN][MAXN];

int main(void)
{
  scanf("%d %d", &R, &S);
  REP(i, R) scanf("%s", grid[i]);

  REP(i, R) {
    Desno[i][S] = 0;
    for (int j = S-1; j >= 0; --j) {
      if (grid[i][j] == '0')
        Desno[i][j] = 0;
      else
        Desno[i][j] = 1 + Desno[i][j+1];
    }
  }

  int maks = 0;

  REP(s1, S) {
    static vector<int> V; V.clear();
    REP(r, R) V.push_back(Desno[r][s1]);
    sort(V.begin(), V.end(), greater<int>());
    REP(i, R) {
      maks = max(maks, V[i] * (i+1));
    }
  }

  printf("%d\n", maks);
  return 0;
}