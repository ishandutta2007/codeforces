#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int n; scanf("%d", &n);
  vector<int> V;
  multiset<int> S;
  REP(i, n) { int x; scanf("%d", &x); V.push_back(x); }
  sort(V.data(), V.data() + n);

  int pola = n/2;
  int matches = 0;
  for (int i = pola; i < n; ++i) S.insert(V[i]);
  for (int i = 0; i < pola; ++i) {
    auto it = S.lower_bound(V[i]*2);
    if (it != S.end()) {
      ++matches; S.erase(it);
    }
  }

  printf("%d\n", n - matches);
  return 0;
}