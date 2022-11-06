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

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int main(void)
{
  int n_l, n_b; scanf("%d %d", &n_l, &n_b);
  vector<int> sol(n_l, -1);
  set<int> left; REP(i, n_l) left.insert(i);
  REP(i, n_b) {
    int b; scanf("%d", &b); --b;
    auto it = left.lower_bound(b);
    for (; it != left.end();) {
      sol[*it] = b;
      it = left.erase(it);
    }
  }
  REP(i, n_l) printf("%d%c", sol[i]+1, i+1 == n_l ? '\n' : ' ');
  return 0;
}