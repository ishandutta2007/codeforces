#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

struct Node {
  llint sz;
  llint suma;
  llint padd;
  void clear() { sz = 1; suma = padd = 0; }
  void update(Node &a, Node& b) {
    assert(sz == a.sz + b.sz);
    suma = a.suma + b.suma;
  }
  void prop(llint add) {
    suma += sz*add;
    padd += add;
  }
};

const int offset = 131072;
Node data[2*offset];

void build() {
  for (int x = 1; x < 2*offset; ++x) data[x].clear();
  for (int x = offset-1; x > 0; --x) data[x].sz = data[2*x].sz + data[2*x+1].sz;
}

template<typename F>
void process(int x, int a, int b, int lo, int hi, const F& f) {
  if (b <= lo || hi <= a) return;
  if (lo <= a && b <= hi) {
    if (f(data[x])) return;
  }
  assert(x < offset);
  if (data[x].padd != 0) {
    data[2*x].prop(data[x].padd);
    data[2*x+1].prop(data[x].padd);
    data[x].padd = 0;
  }
  process(2*x, a, (a+b)/2, lo, hi, f);
  process(2*x+1, (a+b)/2, b, lo, hi, f);
  data[x].update(data[2*x], data[2*x+1]);
}

void inc(int lo, int hi, llint add) { // [lo, hi>
  process(1, 0, offset, lo, hi, [&](Node& x) {
      x.prop(add);
      return true; // done
    });
}

llint get_sum(int lo, int hi) { // [lo, hi>
  llint ans = 0;
  process(1, 0, offset, lo, hi, [&](Node& x) {
      ans += x.suma;
      return true; // done
    });
  return ans;
}

int main(void)
{
  build();

  int nn, nq; scanf("%d %d", &nn, &nq);

  map<int, int> cuts;
  cuts[0] = -1;
  REP(i, nn) cuts[i+1] = i+1;

  auto insert_cut = [&](int x) {
    auto it = cuts.lower_bound(x);
    if (it->first == x) return;
    cuts[x] = it->second;
  };

  REP(iq, nq) {
    int type, lo, hi; scanf("%d %d %d", &type, &lo, &hi); --lo;
    if (type == 1) {
      int p; scanf("%d", &p);
      insert_cut(lo);
      insert_cut(hi);

      auto A = cuts.lower_bound(lo); assert(A->first == lo);
      auto B = cuts.lower_bound(hi); assert(B->first == hi);

      for (auto it = A; it != B; ++it) {
        auto it2 = next(it);
        llint add = abs(it2->second - p);
        inc(it->first, it2->first, add);
      }

      for (auto it = next(A); it != B; )
        it = cuts.erase(it);
      B->second = p;
    } else if (type == 2) {
      printf("%lld\n", get_sum(lo, hi));
    }
  }

  return 0;
}