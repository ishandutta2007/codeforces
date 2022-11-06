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

enum { I, Q, D };

///////////// @@@@@@@@@@@@@@@@ LL!

struct E {
  int type;
  llint x;
  int idx;
};

struct IS {
  llint a, b;
  int idx;
};

const int MAXN = 1e6;
int out[MAXN];

int main(void) {
  int ni, nb; scanf("%d %d", &ni, &nb);
  vector<IS> is;
  REP(i, ni) {
    llint a, b; scanf("%lld %lld", &a, &b);
    is.push_back({a, b, i});
  }

  vector<E> es;
  vector<IS> gaps;
  REP(i, ni-1) {
    llint lo = is[i+1].a - is[i].b;
    llint hi = is[i+1].b - is[i].a;
    gaps.push_back({lo, hi, i});
    es.push_back({I, lo, i});
    es.push_back({D, hi, i});
  }
  REP(i, nb) {
    llint a; scanf("%lld", &a);
    es.push_back({Q, a, i});
  }
  sort(es.begin(), es.end(), [](E a, E b) {
      if (a.x != b.x) return a.x < b.x;
      return a.type < b.type;
    });
  memset(out, -1, sizeof out);

  auto cmpf = [&](int a, int b) {
    if (gaps[a].b != gaps[b].b) return gaps[a].b < gaps[b].b;
    return a < b;
  };
  set<int, decltype(cmpf)> S(cmpf);

  for (auto& e : es) {
    if (e.type == I) {
      S.insert(e.idx);
    } else if (e.type == Q) {
      if (!S.empty()) {
        int ii = *S.begin(); S.erase(S.begin());
        out[ii] = e.idx;
      }
    } else if (e.type == D) {
      S.erase(e.idx);
    }
  }

  bool all = true;
  REP(i, ni-1) if (out[i] == -1) all = false;
  if (all) {
    puts("Yes");
    REP(i, ni-1) printf("%d%c", out[i]+1, i+1 == ni-1 ? '\n' : ' ');
  } else {
    puts("No");
  }

  return 0;
}