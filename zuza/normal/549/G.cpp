#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1e6;
int A[MAXN];

int main(void) {
  int add = 0;
  int n; scanf("%d", &n);
  REP(i, n) scanf("%d", A+i);
  reverse(A, A+n);

  auto cmpf = [&](int a, int b) {
    return make_pair(A[a]-a, a) > make_pair(A[b]-b, b);
  };
  set<int, decltype(cmpf)> pq(cmpf);
  REP(i, n) pq.insert(i);

  int last = 2e9;
  bool ok = true;
  vector<int> out;
  REP(i, n) {
    int idx = *pq.begin(); pq.erase(pq.begin());
    int val = A[idx]-idx+add;
    out.push_back(val);
    if (!(last >= val)) ok = false;
    last = val;
    ++add;
  }

  if (ok) {
    reverse(out.begin(), out.end());
    REP(i, n) printf("%d%c", out[i], i+1 == n ? '\n' : ' ');
  } else puts(":(");

  return 0;
}