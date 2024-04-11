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

const int MAXN = 5012;

struct Loga {
  int seg[MAXN];
  Loga() { clear(); }
  void clear() { memset(seg, 0, sizeof seg); }
  void update(int x, int d) {
    for (++x; x < MAXN; x += x&-x)
      seg[x] += d;
  }
  int query(int x) {
    int sum = 0;
    for (; x; x -= x&-x)
      sum += seg[x];
    return sum;
  }
  int query(int a, int b) {
    return query(b) - query(a);
  }
} loga;

int n;
int A[MAXN];

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", A+i);

  int invs = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      if (A[i] > A[j])
        ++invs;

  int best = 1e9;
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    loga.clear();
    for (int j = i+1; j < n; ++j) {
      if (A[i] > A[j]) {
        int val = invs - 2*loga.query(A[j], A[i]) - 1;
        if (val < best) {
          best = val;
          cnt = 1;
        } else if (val == best) {
          ++cnt;
        }
      }
      loga.update(A[j], 1);
    }
  }
  
  printf("%d %d\n", best, cnt);
  return 0;
}