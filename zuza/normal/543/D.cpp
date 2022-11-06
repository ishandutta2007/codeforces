#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 2e5 + 123;
const int mod = 1e9 + 7;

int n;
vector<int> E[MAXN];
llint dp[MAXN];

void dfsA(int x, int d) {
  dp[x] = 1;
  for (int y : E[x]) {
    if (y != d) {
      dfsA(y, x);
      dp[x] = dp[x]*(dp[y]+1) % mod;
    }
  }
}

llint ans[MAXN];

template<typename T>
ostream& operator << (ostream& os, vector<T> v) {
  os << "{";
  bool first = true;
  for (auto val : v) {
    if (first) first = false; else os << ", ";
    os << val;
  }
  return os << "}";
}


void dfsB(int x, int d, llint up) {
  ans[x] = dp[x] * (up+1) % mod;

  int sz = E[x].size();
  vector<llint> pref(sz+1), suf(sz+1);

  pref[0] = 1;
  REP(i, sz) {
    int y = E[x][i];
    pref[i+1] = pref[i] * (y==d ? 1 : dp[y]+1) % mod;
  }
  suf[sz] = 1;
  for (int i = sz-1; i >= 0; --i) {
    int y = E[x][i];
    suf[i] = suf[i+1] * (y==d ? 1 : dp[y]+1) % mod;
  }

  REP(i, sz) {
    int y = E[x][i];
    if (y != d) {
      dfsB(y, x, (up+1) * pref[i] % mod * suf[i+1] % mod);
    }
  }
}

int main(void) {
  scanf("%d", &n);
  for (int y = 1; y < n; ++y) {
    int x; scanf("%d", &x); --x;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  dfsA(0, -1);
  dfsB(0, -1, 0);

  REP(i, n) printf("%lld%c", ans[i], i+1 == n ? '\n' : ' ');
  return 0;
}