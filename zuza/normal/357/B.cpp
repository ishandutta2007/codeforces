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

int main(void)
{
  const int MAXN = 1e5 + 123;
  static int color[MAXN]; memset(color, -1, sizeof color);
  int n, m; scanf("%d %d", &n, &m);

  REP(i, m) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c); --a, --b, --c;
    if (color[a] == -1 && color[b] == -1 && color[c] == -1) {
      color[a] = 0;
      color[b] = 1;
      color[c] = 2;
    } else {
      int next = max(max(color[a], color[b]), color[c]); next = (next + 1) % 3;
      if (color[a] == -1) { color[a] = next; next = (next + 1) % 3; }
      if (color[b] == -1) { color[b] = next; next = (next + 1) % 3; }
      if (color[c] == -1) { color[c] = next; next = (next + 1) % 3; }
    }
  }

  REP(i, n) {
    if (color[i] == -1) color[i] = 0;
    printf("%d%c", color[i]+1, i+1 == n ? '\n' : ' ');
  }
  return 0;
}