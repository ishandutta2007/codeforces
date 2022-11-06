#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

int main(void)
{
  int n, k; scanf("%d %d", &n, &k);
  vector<int> V;
  bool ok = true;
  REP(i, k) { int x; scanf("%d", &x); V.push_back(x); if (x == 1 || x == n) ok = false; }
  sort(V.begin(), V.end());
  unordered_map<int, int> bio;
  REP(i, k) if (++bio[V[i]-i] >= 3) ok = false;
  puts(ok ? "YES" : "NO");
  return 0;
}