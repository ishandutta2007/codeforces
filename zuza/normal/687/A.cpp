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

const int MAXN = 1e5 + 123;

vector<int> E[MAXN];
int color[MAXN];

bool dfs(int x, int c) {
  if (color[x] != -1) {
    if (color[x] == c) return true;
    if (color[x] != c) return false;
  }
  color[x] = c;
  for (int y : E[x]) {
    if (!dfs(y, c^1))
      return false;
  }
  return true;
}

int main(void) {
  memset(color, -1, sizeof color);
  int n, e; scanf("%d %d", &n, &e);
  REP(i, e) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  bool ok = true;
  REP(i, n) {
    if (color[i] == -1)
      if (dfs(i, 0) == false) {
        ok = false;
        break;
      }
  }

  if (ok) {
    vector<int> idxs(n);
    iota(idxs.begin(), idxs.end(), 0);
    auto mid = partition(idxs.begin(), idxs.end(), [](int x) { 
        return color[x] == 0;
      });
    auto output = [](vector<int>::iterator a, vector<int>::iterator b) {
      int sz = b - a;
      printf("%d\n", sz);
      REP(i, sz) printf("%d%c", *(a+i)+1, i+1 == sz ? '\n' : ' ');
    };
    output(idxs.begin(), mid);
    output(mid, idxs.end());
  } else {
    printf("-1\n");
  }
  return 0;
}