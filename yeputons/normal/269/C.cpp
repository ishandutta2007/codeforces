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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vvi es(n), esw(n), esid(n);
    vi ans(m + 1, -1);
    vi bal(n, 0);
    
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c), a--, b--;
      es[a].pb(b); esw[a].pb(c); esid[a].pb(i + 1);
      es[b].pb(a); esw[b].pb(c); esid[b].pb(-(i + 1));

      bal[a] += c;
      bal[b] += c;
    }

    deque<int> q;
    bal[0] = 0;
    q.pb(0);

    vb was(n, false);
    was[0] = true;

    while (!q.empty()) {
      int v = q.front(); q.pop_front();
      was[v] = true;

//      eprintf("v=%d\n", v);
      for (int i = 0; i < sz(es[v]); i++) {
        int b = es[v][i];
        if (was[b]) continue;

        bal[b] -= 2 * esw[v][i];
        if (esid[v][i] > 0) ans[esid[v][i] - 1] = 0;
        else ans[-esid[v][i] - 1] = 1;
        if (b == n - 1) continue;

//        eprintf("bal[%d]=%d\n", b, bal[b]);
//        assert(bal[b] >= 0);
        if (bal[b] == 0) {
          q.pb(b);
        }
      }
    }
    for (int i = 0; i < m; i++)
      printf("%d\n", ans[i]);
//    break;
  }
  return 0;
}