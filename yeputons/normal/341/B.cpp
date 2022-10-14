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
  static int f(int x) { return x & -x; }
  vi tr;
  public:
  fenv_tree(int n) : tr(n + 1, 0) {}
  void relax(int x, int val) {
    for (x++; x < sz(tr); x += f(x))
      tr[x] = max(tr[x], val);
  }
  int get(int x) {
    int res = 0;
    for (x++; x > 0; x -= f(x))
      res = max(res, tr[x]);
    return res;
  }
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]), as[i]--;

    fenv_tree tr(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int cans = tr.get(as[i]);
      cans++;
      ans = max(ans, cans);
      tr.relax(as[i], cans);
    }
    printf("%d\n", ans);
  }
  return 0;
}