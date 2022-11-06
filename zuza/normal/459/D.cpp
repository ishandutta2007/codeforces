#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Loga {
  int n;
  vector<llint> data;
  Loga(int n) : n(n), data(n+1, 0) {}
  void update(int x, int delta) {
    for (++x; x <= n; x += x&-x)
      data[x] += delta;
  }
  int query(int x) { // PAZI
    int ans = 0;
    for (; x; x -= x&-x) ans += data[x];
    return ans;
  }
  int query(int a, int b) { return query(b) - query(a); }
};

int main(void) {
  map<int, int> R, L;  

  int n; scanf("%d", &n);
  vector<int> A(n);
  REP(i, n) scanf("%d", &A[i]);

  Loga loga(n+1);
  for (int i = n-1; i >= 0; --i) {
    int val = ++R[ A[i] ];
    loga.update(val, +1);
  }
  llint ans = 0;
  REP(i, n) {
    { int val = --R[ A[i] ];
      loga.update(val+1, -1);
    }

    int lhs = ++L[ A[i] ];
    ans += loga.query(lhs);
  }
  printf("%lld\n", ans);

  return 0;
}