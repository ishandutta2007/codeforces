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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXN = 1e5 + 123;

vector<int> E[MAXN];
vector<int> recon;

int flip[MAXN];

void dfs(int x, int dad, int a, int b) {
  int on = flip[x] ^ a;
  if (on) recon.push_back(x);

  for (int y : E[x]) {
    if (y != dad) {
      dfs(y, x, b, a ^ on);
    }
  }
}

int main(void)
{
  int n; scanf("%d", &n);
  REP(i, n-1) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  memset(flip, 0, sizeof flip);
  REP(i, n) { int x; scanf("%d", &x); flip[i] ^= x; }
  REP(i, n) { int x; scanf("%d", &x); flip[i] ^= x; }

  dfs(0, -1, 0, 0);

  int sz = recon.size();
  printf("%d\n", sz);
  sort(recon.begin(), recon.end()); REP(i, sz) printf("%d\n", recon[i]+1);

  return 0;
}