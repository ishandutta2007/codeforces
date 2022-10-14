#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class fenv_tree {
  vi tr, vals;

  static int f(int x) { return x & -x; }
  int get(int x) {
    int res = 0;
    for (x++; x > 0; x -= f(x))
      res += tr[x];
    return res;
  }

  public:
  fenv_tree(int n) : tr(n + 1, 0), vals(n, 0) {}
  
  void add(int x, int v) {
    vals[x] += v;
    for (x++; x < sz(tr); x += f(x))
      tr[x] += v;
  }
  int get(int l, int r) {
    return get(r) - get(l - 1);
  }
  void set(int x, int v) {
    add(x, v - vals[x]);
    assert(vals[x] == v);
  }
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi pos(n, -1);
    vi idByPos(n, -1);
    fenv_tree tr(n);

    for (int i = 0; i < n; i++) {
      int id;
      scanf("%d", &id), id--;
      idByPos[i] = id;
      pos[id] = i;
    }
    for (int i = 0; i + 1 < n; i++) {
      tr.set(i, pos[i] < pos[i + 1] ? 0 : 1);
    }

    int q;
    scanf("%d", &q);
    while (q --> 0) {
      int p, x, y;
      scanf("%d%d%d", &p, &x, &y), x--, y--;
      if (p == 2) {
        int p1 = x, p2 = y;
        x = idByPos[x];
        y = idByPos[y];
        swap(idByPos[p1], idByPos[p2]);
        swap(pos[x], pos[y]);
        for (int i = 0; i < 2; i++, swap(x, y)) {
          if (x > 0) {
            tr.set(x - 1, pos[x - 1] < pos[x] ? 0 : 1);
          }
          if (x + 1 < n) {
            tr.set(x, pos[x] < pos[x + 1] ? 0 : 1);
          }
        }
      } else {
        int ans = 1 + tr.get(x, y - 1);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}