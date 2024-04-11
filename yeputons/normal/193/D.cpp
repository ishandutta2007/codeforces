#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

const int INF = 1e9;
class Solver {
  struct Data {
    pii vals[3];

    Data() { for (int i = 0; i < 3; i++) vals[i] = mp(INF, 0); }
    Data(int x) { for (int i = 1; i < 3; i++) vals[i] = mp(INF, 0); vals[0] = mp(x, 1); }
    void operator+=(const Data &d2) {
      int p1 = 0, p2 = 0;
      pii vals2[3];

      for (int p3 = 0; p3 < 3; p3++) {
        assert(p1 < 3 && p2 < 3);
        int cmp = vals[p1].first - d2.vals[p2].first;
        if (cmp < 0) vals2[p3] = vals[p1++];
        else if (cmp > 0) vals2[p3] = d2.vals[p2++];
        else {
          vals2[p3] = mp(vals[p1].first, vals[p1].second + d2.vals[p2].second);
          p1++; p2++;
        }
      }
      for (int i = 0; i < 3; i++) vals[i] = vals2[i];
    }
  };

  vector<Data> tr;
  vi tradd;
  int off;

  void norm(int v) {
    if (!tradd[v]) return;
    if (v < off) {
      tradd[2 * v] += tradd[v];
      tradd[2 * v + 1] += tradd[v];
    }
    for (int i = 0; i < 3; i++) tr[v].vals[i].first += tradd[v];
    tradd[v] = 0;
  }

  int lr, rr, vr;
  void _add(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return;
    if (lr <= lt && rt <= rr) {
      tradd[v] += vr;
      return;
    }
    norm(v);
    int mt = (lt + rt) / 2;
    _add(2 * v, lt, mt); norm(2 * v);
    _add(2 * v + 1, mt + 1, rt); norm(2 * v + 1);
    tr[v] = tr[2 * v];
    tr[v] += tr[2 * v + 1];
  }

  public:
  Solver(int n) {
    off = 1; while (off < n) off <<= 1;
    tr = vector<Data>(2 * off);
    tradd = vi(2 * off, 0);

    for (int i = 0; i < n; i++) {
      tr[off + i] = 0;
    }
    for (int i = off - 1; i >= 1; i--) {
      tr[i] = tr[2 * i];
      tr[i] += tr[2 * i + 1];
    }
  }
  int calc() {
    norm(1);
    int ans = 0;
    for (int i = 0; i < 3; i++) {
      assert(tr[1].vals[i].first >= 0);
      assert(tr[1].vals[i].second >= 0);
      if (tr[1].vals[i].first <= 2)
        ans += tr[1].vals[i].second;
    }
    return ans;
  }
  void add(int l, int r, int v) {
    lr = l; rr = r; vr = v;
    return _add(1, 0, off - 1);
  }
};

const int MAXN = 3e5 + 1e3;
int n;
int as[MAXN], pos[MAXN];

inline int calcNeigh(int x, int l) {
  int cp = pos[x];
  int ans = 0;
  if (cp > 0) ans += as[cp - 1] >= l && as[cp - 1] < as[cp];
  if (cp + 1 < n) ans += as[cp + 1] >= l && as[cp + 1] < as[cp];
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]), pos[--as[i]] = i;

    ll ans = 0;
    Solver s(n);
    {
      for (int r = 0; r < n; r++)
        s.add(r, n - 1, -calcNeigh(r, 0) + 1);
    }
    for (int l = 0; l < n; l++) {
      ans += s.calc() - 1 - l;
      s.add(l, n - 1, calcNeigh(l, l) - 1);

      for (int x = max(0, pos[l] - 1); x < n && x <= pos[l] + 1; x++) if (as[x] != l) {
        int r = as[x];
        int oval = -calcNeigh(r, l) + 1;
        int nval = -calcNeigh(r, l + 1) + 1;
        s.add(r, n - 1, nval - oval);
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}