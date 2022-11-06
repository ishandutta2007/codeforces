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

// !!! pazi llint

struct MaxEnvelope {
  struct Line { llint k, l; };

  vector<Line> data;
  int best_ptr;

  MaxEnvelope() { best_ptr = 0; data.clear(); }

  static int ccw(Line a, Line b, Line c) { // overflow ?
    llint sum = 0;
    sum += a.k*(b.l - c.l);
    sum += b.k*(c.l - a.l);
    sum += c.k*(a.l - b.l);
    return (sum > 0) - (sum < 0); // sgn
  }

  void insert(llint k, llint l) { // k raste (moze bit i jednak) i VECI je od 0
    int sz = data.size();
    Line nov{k, l};

    if (sz >= 1 && k == data.back().k && l < data.back().l) return;
    while (sz >= 1 && k == data.back().k && l >= data.back().l) { --sz; data.pop_back(); }
    while (sz >= 2 && ccw(data[sz-2], data[sz-1], nov) >= 0) { --sz; data.pop_back(); }
    best_ptr = min(best_ptr, (int)data.size());
    data.push_back(nov);
  }

  pair<llint, llint> query(llint y) {
    typedef pair<llint, llint> point;
    if (y == 0) return point(0, 0);
    if (data.empty()) return point(-1, -1);

    auto get_p = [y](Line p) {
      llint x = (y - p.l + p.k - 1) / p.k;
      llint real_y = p.k*x + p.l;
      return make_pair(x, real_y);
    };
    auto p_cmpf = [](point a, point b) {
      if (a.first != b.first) return a.first < b.first;
      return a.second > b.second;
    };

    if (best_ptr <= 0) best_ptr = 1;
    point best = get_p(data[best_ptr-1]);
    
    while (best_ptr < (int)data.size()) {
      point nov = get_p(data[best_ptr]);
      if (p_cmpf(nov, best)) {
        best = nov;
        ++best_ptr;
      } else {
        break;
      }
    }

    return best;
  }
};

int main(void)
{
  const int MAXN = 2e5 + 123;
  struct Par { int add, cost; };
  static Par A[MAXN];

  int n; llint goal; cin >> n >> goal;
  REP(i, n) scanf("%d %d", &A[i].add, &A[i].cost);
  sort(A, A+n, [](Par a, Par b) { return a.add < b.add; });

  int sz = 0;
  REP(i, n) {
    if (A[i].cost > goal) continue;
    while (sz >= 1 && A[i].cost <= A[sz-1].cost) --sz;
    A[sz++] = A[i];
  }
  n = sz;

  MaxEnvelope env;

  REP(i, n) {
    auto p = env.query(A[i].cost); // p je llint
    if (p.first == -1) continue;
    llint l = p.second - A[i].cost - p.first*A[i].add;
    env.insert(A[i].add, l);
  }

  auto p = env.query(goal);
  cout << p.first << endl;

  return 0;
}