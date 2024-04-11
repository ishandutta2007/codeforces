#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

llint digsum(llint x) {
  llint sum = 0;
  for (; x; x /= 10) sum += x%10;
  return sum;
}

int main(void) {
  int a, b, c; scanf("%d %d %d", &a, &b, &c);
  vector<int> V;

  FOR(ds, 0, 9*9+1) {
    llint pot = 1; 
    REP(i, a) pot *= ds;
    llint x = pot*b + c;
    llint lim = 1e9;

    if (0 < x && x < lim && digsum(x) == ds) {
      V.push_back((int)x);
    }
  }
  sort(V.begin(), V.end());
  int sz = V.size(); printf("%d\n", sz);
  REP(i, sz) printf("%d%c", V[i], i+1 == sz ? '\n' : ' ');
  return 0;
}