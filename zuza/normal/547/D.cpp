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

struct Pt {
  int x, y, idx;
};

const int MAXN = 2e5 + 123;

char color[MAXN];
vector<int> E[MAXN];

void dfs(int x, int c, int dad) {
  char p = (c == 0) ? 'r' : 'b';
  if (color[x] != '?') {
    assert(color[x] == p);
    return;
  }

  color[x] = p;
  for (auto y : E[x])
    if (y != dad)
      dfs(y, c^1, x);
}

int main(void) {
  
  memset(color, '?', sizeof color);

  static vector<Pt> R[MAXN], S[MAXN];

  int n; scanf("%d", &n);
  REP(i, n) {
    int x, y; scanf("%d %d", &x, &y);
    R[x].push_back({x, y, i});
    S[y].push_back({x, y, i});
  }

  REP(x, MAXN) {
    auto doit = [](vector<Pt>& v) {
      int sz = v.size();
      for (int i = 0; i+1 < sz; i += 2) {
        int a = v[i].idx, b = v[i+1].idx;
        E[a].push_back(b);
        E[b].push_back(a);
      }
    };

    doit(R[x]);
    doit(S[x]);
  }

  REP(i, n) {
    if (color[i] == '?')
      dfs(i, 0, -1);
  }

  REP(i, n) putchar(color[i]); putchar('\n');
  return 0;
}