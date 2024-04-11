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

const int MAXN = 1e5 + 123;

int n, e;
vector<int> E[MAXN];

enum { W, G, B };
int color[MAXN];

int solve(int x, int dad) {
  color[x] = G;
  int left = -1;

  auto process = [&left, x](int b) {
    if (left == -1) { left = b; return; }
    printf("%d %d %d\n", left+1, x+1, b+1);
    left = -1;
  };

  for (int b : E[x]) {
    if (b == dad) continue;

    if (color[b] == W) {
      int val = solve(b, x);
      if (val != -1) process(val);
    } else if (color[b] == G) {
      process(b);
    } else if (color[b] == B) {
      continue;
    } else {
      assert(false);
    }
  }

  color[x] = B;
  if (left == -1) return x;
  process(dad);
  return -1;
}

int main(void)
{
  scanf("%d %d", &n, &e);
  REP(i, e) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  if (e&1) {
    puts("No solution");
    return 0;
  }

  REP(i, n) color[i] = W;
  assert(solve(0, -1) == 0);

  return 0;
}