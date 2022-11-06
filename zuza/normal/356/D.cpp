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

const int MAXN = 70000 + 123;

int n, s;
int A[MAXN];

int recon[MAXN];

int main(void)
{
  scanf("%d %d", &n, &s);
  int maksind = 0;
  REP(i, n) { 
    scanf("%d", A+i);
    if (A[i] > A[maksind]) maksind = i;
  }
  int maxS = s - A[maksind];

  {
    static unsigned int dp[MAXN / 32 + 123];
    static unsigned int shift[MAXN / 32 + 123];

    memset(dp, 0, sizeof dp);
    memset(recon, -1, sizeof recon);
    dp[0] |= 1;
    recon[0] = -2;

    REP(i, n) { 
      if (i == maksind) continue;

      int right_a = A[i] / 32;
      int right_b = A[i] % 32;
      memset(shift, 0, sizeof shift); // speed!

      for (int j = 0, ub = maxS/32+1; j < ub; ++j) {
        shift[j+right_a] |= dp[j] << right_b;
        if (right_b > 0) shift[j+right_a+1] |= (dp[j] >> (32-right_b));
      }

      for (int j = 0, ub = maxS/32+1; j < ub; ++j) {
        unsigned int newb = shift[j] & ~dp[j];
        if (newb) {
          for (int b = 0; b < 32; ++b)
            if (newb&(1<<b)) {
              dp[j] |= 1<<b;
              recon[32*j + b] = i;
            }
        }
      }

      // printf("A[%d] = %d\n", i, A[i]);
      // for (int j = 0; j <= maxS; ++j)
      //   printf("%d", (dp[j/32] >> (j%32))&1);
      // putchar('\n');
    }
  }

  static vector<int> kids[MAXN];
  static int add[MAXN];
  if (maxS >= 0 && recon[maxS] != -1) {
    vector<int> rest;
    static char root[MAXN] = {0};

    int S = s - A[maksind];
    while (S != 0) {
      int i = recon[S];
      root[i] = true;
      S -= A[i];
    }

    REP(i, n) {
      if (!root[i]) { 
        if (i != maksind) rest.push_back(i);
      }
      else { add[i] = A[i]; kids[i].clear(); }
    }
    sort(rest.begin(), rest.end(), [](int a, int b) { return A[a] > A[b]; });

    int last = maksind;
    for (int i : rest) {
      kids[last].push_back(i);
      add[last] = A[last] - A[i];
      last = i;
    }
    
    add[last] = A[last];

    REP(i, n) {
      printf("%d %d", add[i], (int)kids[i].size());
      for (int k : kids[i]) printf(" %d", k+1);
      putchar('\n');
    }
  } else {
    puts("-1");
  }

  return 0;
}