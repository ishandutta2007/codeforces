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

const int MAXN = 1e6;
int prefix[MAXN];

int main(void)
{
  int n, k; scanf("%d %d", &n, &k);
  prefix[0] = 0;
  REP(i, n) { 
    int x; scanf("%d", &x);
    prefix[i+1] = prefix[i] + x;
  }

  int mini = 1e9;
  int best = -1;
  for (int i = k; i <= n; ++i) {
    int val = prefix[i] - prefix[i-k];
    if (val < mini) { 
      mini = val;
      best = i;
    }
  }

  printf("%d\n", best+1-k);
  return 0;
}