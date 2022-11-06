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

bool solve(int x1, int y1, int x2, int y2) {
  if (x1%2 != x2%2) return false;
  if (y1%2 != y2%2) return false;
  if (x1/2%2 != x2/2%2 || y1/2%2 != y2/2%2) return false;
  return true;
}

int main(void)
{
  int T; scanf("%d", &T);
  REP(tt, T) {
    static char grid[10];
    vector<int> Vx, Vy;

    REP(i, 8) {
      scanf("%s", grid);
      REP(j, 8) if (grid[j] == 'K') {
        Vx.push_back(i);
        Vy.push_back(j);
      }
    }

    assert(Vx.size() == 2 && Vy.size() == 2);
    puts(solve(Vx[0], Vy[0], Vx[1], Vy[1]) ? "YES" : "NO");
  }
  return 0;
}