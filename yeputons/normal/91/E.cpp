#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

struct Frac {
  int a, b;
  Frac() : a(0), b(1) {}
  Frac(int _a, int _b = 1) : a(_a), b(_b) {}
  bool operator<(const Frac &f2) const {
    return ll(a) * f2.b < ll(b) * f2.a;
  }
};
struct Walrus {
  int a, b, id;
  bool operator<(const Walrus &w2) const {
    if (b != w2.b) return b < w2.b;
    return a > w2.a;
  }

  Frac operator&(const Walrus &w2) const {
    assert(b < w2.b);
    return Frac(a - w2.a, w2.b - b);
  }
};
bool good(const Walrus &a, const Walrus &b, const Walrus &c) {
  return (a & b) < (b & c);
}

class Solver {
  vector<pair<Frac, int> > evs;
  vector<Walrus> as;

  public:
  Solver() {}
  Solver(const vector<Walrus> &_as) : as(_as) {
    sort(as.begin(), as.end());
    int n = sz(as);
    if (!n) return;

    vi st(n);
    int sten = 0;

    for (int i = 0; i < sz(as); i++) if (!i || as[i - 1].b != as[i].b) {
      while (sten >= 2 && !good(as[st[sten - 2]], as[st[sten - 1]], as[i]))
        sten--;
      st[sten++] = i;
    }
    evs.resize(sten);
    evs[0] = mp(-1e100, st[0]);
    for (int i = 1; i < sten; i++) {
      evs[i] = mp(as[st[i - 1]] & as[st[i]], st[i]);
    }
  }
  void relax(int t, int &res, ll &rh) {
    int id = upper_bound(evs.begin(), evs.end(), mp(Frac(t), -1)) - evs.begin() - 1;
    if (id < 0 || id >= sz(evs)) return;
    Walrus w = as[evs[id].second];
    ll ch = w.a + ll(w.b) * t;
    if (ch > rh) {
      rh = ch;
      res = w.id;
    }
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vector<Walrus> as(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &as[i].a, &as[i].b), as[i].id = i;

    int off = 1;
    while (off < n) off <<= 1;

    vector<Solver> s(2 * off);
    vi ls(2 * off, n), rs(2 * off, n);
    for (int i = 0; i < n; i++) {
      ls[off + i] = i; rs[off + i] = i + 1;
      s[off + i] = Solver(vector<Walrus>(1, as[i]));
    }
    for (int i = off - 1; i >= 1; i--) {
      ls[i] = ls[2 * i];
      rs[i] = rs[2 * i + 1];
      s[i] = Solver(vector<Walrus>(as.begin() + ls[i], as.begin() + rs[i]));
    }

    for (int i = 0; i < m; i++) {
      int l, r, t;
      scanf("%d%d%d", &l, &r, &t), l--, r--;
      l += off; r += off;

      int res = -1;
      ll rh = -1;
      while (l <= r) {
        if (l & 1) s[l++].relax(t, res, rh);
        if (!(r & 1)) s[r--].relax(t, res, rh);
        l >>= 1; r >>= 1;
      }
      printf("%d\n", res + 1);
    }
  }
  return 0;
}