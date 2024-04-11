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

struct Loga {
  int n;
  vector<int> data;
  Loga(int n) : n(n), data(n+1, 0) {
  }
  void update(int x, int delta) {
    for (++x; x <= n; x += x&-x) {
      data[x] += delta;
    }    
  }
  int query(int x) { // [0, x>
    int sum = 0;
    for (; x; x -= x&-x) sum += data[x];
    return sum;
  }
};

const int MAXN = 200000 + 123;

int D[MAXN], F[MAXN];
int tt = 0;
int n, q;

int poc[MAXN];
int depth[MAXN];
vector<int> E[MAXN];
Loga L[2] = {2*MAXN, 2*MAXN};

void dfs(int x, int dad, int dep) {
  depth[x] = dep;
  D[x] = tt++;
  for (int y : E[x]) {
    if (y == dad) continue;
    dfs(y, x, dep+1);
  }
  F[x] = tt++;
}

int main(void)
{
  scanf("%d %d", &n, &q);
  REP(i, n) scanf("%d", poc+i);
  REP(i, n-1) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1, 0);
  REP(i_q, q) {
    int type, x; scanf("%d %d", &type, &x); --x;
    int d = depth[x]%2;
    if (type == 1) {
      int val; scanf("%d", &val);
      L[d].update(D[x], +val);
      L[d].update(F[x], -val);
      L[d^1].update(D[x], -val);
      L[d^1].update(F[x], +val);
    } else {
      int val = L[d].query(D[x] + 1);
      printf("%d\n", poc[x] + val);
    }
  }

  return 0;
}