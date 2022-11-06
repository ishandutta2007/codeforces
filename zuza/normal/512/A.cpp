#include <cassert>
#include <cstring>
#include <cstdio>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int graf[30][30];

int bio[30];
string alpha;

void dfs(int x) {
  if (bio[x]) return;
  bio[x] = true;
  REP(y, 26) if (graf[x][y]) dfs(y);
  alpha += char(x + 'a');
}

int main(void) {
  memset(graf, 0, sizeof graf);
  int n; scanf("%d", &n);
  
  vector<string> grid;
  REP(i, n) {
    static char buff[123]; scanf("%s", buff);
    grid.push_back(buff);
  }

  REP(i, n-1) {
    int ml = min(grid[i].size(), grid[i+1].size());
    REP(j, ml) {
      if (grid[i].substr(0, j) == grid[i+1].substr(0, j)) {
        graf[ grid[i][j]-'a' ][ grid[i+1][j]-'a' ] = 1;
        //        TRACE(grid[i][j] _ grid[i+1][j]);
      }
    }
  }

  REP(i, 26) if (!bio[i]) dfs(i);
  reverse(alpha.begin(), alpha.end());

  bool ok = true;
  REP(i, n-1) {
    auto trans = [&](string s) {
      for (char& c : s)
        c = alpha.find(c) + 'a';
      return s;
    };
    if (trans(grid[i]) > trans(grid[i+1]))
      ok = false;
  }

  if (ok)
    puts(alpha.c_str());
  else
    puts("Impossible");

  return 0;
}