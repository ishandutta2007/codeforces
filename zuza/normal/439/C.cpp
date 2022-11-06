#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

bool solve() {
  int n, k, par; scanf("%d %d %d", &n, &k, &par);
  int nepar = k - par;

  vector<int> P, N;

  int suma = 0;
  REP(i, n) {
    int x; scanf("%d", &x);
    suma ^= (x&1);
    if (x&1) N.push_back(x);
    else P.push_back(x);
  }
  if (suma%2 != nepar%2) return false;

  vector< vector<int> > grupe(k);
  REP(i, k) {
    if (i < nepar) {
      if (N.empty()) return false;
      grupe[i].push_back(N.back());
      N.pop_back();
    } else {
      assert(N.size()%2 == 0);
      if (!N.empty()) {
        grupe[i].push_back(N.back()); N.pop_back();
        grupe[i].push_back(N.back()); N.pop_back();
      } else if (!P.empty()) {
        grupe[i].push_back(P.back()); P.pop_back();
      } else return false;
    }
  }

  copy(P.begin(), P.end(), back_inserter(grupe[0])); P.clear();
  copy(N.begin(), N.end(), back_inserter(grupe[0])); N.clear();

  puts("YES");
  REP(i, k) {
    printf("%d", (int)grupe[i].size());
    for (int x : grupe[i]) printf(" %d", x);
    putchar('\n');
  }
  return true;
}

int main(void)
{
  if (solve() == false)
    puts("NO");

  return 0;
}