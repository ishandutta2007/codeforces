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

struct S { int x, idx; };
vector<pair<int, int> > recon;

void push(S& a, S& b) { // a < b
  assert(a.x <= b.x);
  b.x -= a.x;
  a.x *= 2;
  recon.push_back({a.idx, b.idx});
}

int main(void)
{

  int n; scanf("%d", &n);
  vector<S> A;

  REP(i, n) {
    int x; scanf("%d", &x);
    A.push_back({x, i});
  }
  REP(i, n-2) {
    S& a = A[i], &b = A[i+1], &c = A[i+2];

    while (true) {
      if (a.x > b.x) swap(a, b);
      if (a.x > c.x) swap(a, c);
      if (b.x > c.x) swap(b, c);
      if (a.x == 0) break;

      int div = b.x / a.x;
      for (; div; div /= 2) {
        if (div&1) {
          push(a, b);
        } else {
          push(a, c);
        }
      }
    }
  }

  int zeros = 0; REP(i, n) zeros += (A[i].x == 0);
  if (zeros != n-2) { puts("-1"); exit(0); }

  int sz = recon.size(); 
  printf("%d\n", sz);
  REP(i, sz) printf("%d %d\n", recon[i].first+1, recon[i].second+1);

  return 0;
}