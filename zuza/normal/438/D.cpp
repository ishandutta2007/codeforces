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

struct Node { 
  int maks;
  llint suma;
  Node() { maks = 0; suma = 0; } 
  void update(Node& a, Node& b) {
    maks = max(a.maks, b.maks);
    suma = a.suma + b.suma;
  }
};

struct Tour {
  int offset;
  vector<Node> data;

  Tour(int n) {
    offset = 1; while (offset < n) offset *= 2;
    data.resize(2*offset);
  }

  int tlo, thi;
  int tmod;

  template<typename F>
  void process(int x, int clo, int chi, const F& f) {
    if (chi <= tlo || thi <= clo) return;
    if (tlo <= clo && chi <= thi) {
      f(data[x]);
      return;
    }
    // prop?
    process(2*x, clo, (clo+chi)/2, f);
    process(2*x+1, (clo+chi)/2, chi, f);
    data[x].update(data[2*x], data[2*x+1]);
  }

  void do_mod(int x, int clo, int chi) {
    if (chi <= tlo || thi <= clo) return;
    if (data[x].maks < tmod) return;
    if (clo+1 == chi) {
      llint val = data[x].suma; val %= tmod;
      data[x].suma = data[x].maks = val;
      return;
    }
    do_mod(2*x, clo, (clo+chi)/2);
    do_mod(2*x+1, (clo+chi)/2, chi);
    data[x].update(data[2*x], data[2*x+1]);
  }

  void mod_it(int lo, int hi, int mod) {
    tlo = lo; thi = hi; tmod = mod;
    do_mod(1, 0, offset);
  }

  void update(int x, int val) {
    tlo = x; thi = x+1;
    process(1, 0, offset, [&](Node& node) {
        node.suma = node.maks = val;
      });
  }

  llint get_sum(int lo, int hi) {  // [lo, hi>
    tlo = lo; thi = hi;
    llint ans = 0;
    process(1, 0, offset, [&](Node &node) {
        ans += node.suma;
      });
    return ans;
  }
};

int read_int() { int x; scanf("%d", &x); return x; }

int main(void)
{
  int nn, nq; scanf("%d %d", &nn, &nq);
  Tour T(nn);
  REP(i, nn) {
    int x; scanf("%d", &x);
    T.update(i, x);
  }
  REP(iq, nq) {
    int type; scanf("%d", &type);
    if (type == 1) {
      int lo = read_int(), hi = read_int(); --lo;
      printf(LLD "\n", T.get_sum(lo, hi));
    } else if (type == 2) {
      int lo = read_int(), hi = read_int(), mod = read_int(); --lo;
      T.mod_it(lo, hi, mod);
    } else if (type == 3) {
      int k, val; scanf("%d %d", &k, &val); --k;
      T.update(k, val);
    }    
  }
  return 0;
}