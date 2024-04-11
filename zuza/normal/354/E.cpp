#include <algorithm>

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

int dp[20][5];

int len;
int digs[21];

llint recon[6];

int solve(int x, int ost) {
  if (x == len) {
    if (ost == 0) return true;
    return false;
  }

  int& ref = dp[x][ost];
  if (ref != -1) return ref;
  ref = false;

  for (int a = 0; a <= 6; ++a) // 4
    for (int b = 0; a+b <= 6; ++b) { // 7
      int val = 4*a + 7*b + ost;
      if (val % 10 != digs[x]) continue;

      if (solve(x+1, val / 10)) {
        REP(i, 6) {
          int d = 0;
          if (i < a) d = 4;
          else if (i < a+b) d = 7;
          recon[i] = 10*recon[i] + d;
        }
        return ref = true;
      }
    }

  return ref;
}

int main(void)
{
  int TT; scanf("%d", &TT);
  REP(cs, TT) {
    {
      llint S; cin >> S;
      for (len = 0; S > 0; S /= 10)
        digs[len++] = S % 10;
    }

    memset(dp, -1, sizeof dp);
    memset(recon, 0, sizeof recon);

    if (solve(0, 0)) {
      REP(i, 6) cout << recon[i] << ((i+1 == 6) ? '\n' : ' ');
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}