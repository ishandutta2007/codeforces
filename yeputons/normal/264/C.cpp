#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

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

const ll INFLL = 1e18;
const int MAXN = 1e5 + 1e3;

class Cols {
  vi lasuse;
  int cver, ccnt;

  public:
  Cols(int n) : lasuse(n, 0), cver(1), ccnt(0) {}
  void insert(int v) {
    assert(0 <= v && v < sz(lasuse));
//    assert(lasuse[v] < cver);
    lasuse[v] = cver;
    ccnt++;
  }
  void erase(int v) {
    assert(0 <= v && v < sz(lasuse));
//    assert(lasuse[v] >= cver);
    assert(ccnt > 0);
    lasuse[v] = cver - 1;
    ccnt--;
  }
  bool hasnot(int x) { return ccnt > 1 || (ccnt == 1 && lasuse[x] < cver); }
  bool empty() const { return ccnt == 0; }
  void clear() { cver++; ccnt = 0; }
  void swap(Cols &c2) {
    lasuse.swap(c2.lasuse);
    ::swap(cver, c2.cver);
    ::swap(ccnt, c2.ccnt);
  }
};
class Magic {
  ll v1, v2;
  Cols c1, c2;
  
  public:
  Magic(int n) : v1(-INFLL - 1), v2(-INFLL - 2), c1(n), c2(n) { }
	void erase(const ll &cv, int cc) {
    if (v2 == cv) {
      assert(v1 > v2);
      c2.erase(cc);
      if (c2.empty()) v2 = -INFLL - 1;
      return;
    }
    if (v1 == cv) {
      assert(v1 > v2);
      c1.erase(cc);
      if (c1.empty()) {
        v1 = -INFLL - 1;
        swap(v1, v2);
        c1.swap(c2);
      }
    }
  }
  void add(const ll &cv, int cc) {
    if (cv < v2) return;
      assert(v1 >= v2);
      if (v1 == v2) {
        assert(c2.empty());
      }
    if (cv < v1) {
      if (v2 != cv) c2.clear();
      c2.insert(cc);
      v2 = cv;
      assert(v1 > v2);
      return;
    }

    if (v1 != cv) {
      c2.swap(c1);
      swap(v2, v1);
      c1.clear();
    }
    c1.insert(cc);
    v1 = cv;
  }
  ll get(int badc) {
    if (c1.hasnot(badc)) return v1;
    if (c2.hasnot(badc)) return v2;
    return -INFLL - 1;
  }
  void checkEmpty() const { assert(c1.empty()); assert(c2.empty()); }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, q;
  while (scanf("%d%d", &n, &q) >= 1) {
    vi vs(n), cs(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &vs[i]), assert(abs(vs[i]) <= int(1e5));
    for (int i = 0; i < n; i++)
      scanf("%d", &cs[i]), cs[i]--;

    while (q --> 0) {
      ll eqv, neqv;
      scanf("%I64d%I64d", &eqv, &neqv);
      assert(abs(eqv) <= 1e5);
      assert(abs(neqv) <= 1e5);

      Magic mgc(n);
      vector<ll> cdyn(n, -INFLL);
      for (int i = 0; i < n; i++)
        mgc.add(cdyn[i], i);

      ll ans = 0;
      for (int i = 0; i < n; i++) {
        int cc = cs[i];
        assert(0 <= cc && cc < n);
        ll cans = cdyn[cc] + vs[i] * eqv;
        cans = max(cans, mgc.get(cc) + vs[i] * neqv);
        cans = max(cans, vs[i] * neqv);
        ans = max(ans, cans);

        mgc.erase(cdyn[cc], cc);
        cdyn[cc] = max(cdyn[cc], cans);
        mgc.add(cdyn[cc], cc);
      }
      printf("%I64d\n", ans);
      for (int i = 0; i < n; i++)
        mgc.erase(cdyn[i], i);
      mgc.checkEmpty();
    }
  }
  return 0;
}