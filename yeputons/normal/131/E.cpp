#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vector<pii> as(m);
    for (int i = 0; i < m; i++)
      scanf("%d%d", &as[i].first, &as[i].second), as[i].first--, as[i].second--;

    vector<vector<pii> > rs[4];
    rs[0].resize(n);
    rs[1].resize(n);
    rs[2].resize(2 * n);
    rs[3].resize(2 * n);
    for (int i = 0; i < m; i++) {
      int c1 = as[i].first, c2 = as[i].second;
      int c3 = as[i].first + as[i].second, c4 = as[i].first - as[i].second + n - 1;

      rs[0][c1].pb(mp(c2, i));
      rs[1][c2].pb(mp(c1, i));
      rs[2][c3].pb(mp(c4, i));
      rs[3][c4].pb(mp(c3, i));
    }

    vi cnt(m, 0);
    for (int st = 0; st < 4; st++)
    for (int id = 0; id < sz(rs[st]); id++) {
      vector<pii> &cur = rs[st][id];
      if (sz(cur) < 2) continue;

      sort(cur.begin(), cur.end());
      for (int i = 0; i < sz(cur); i++) {
        int cid = cur[i].second;

        cnt[cid]++;
        if (0 < i && i + 1 < sz(cur))
          cnt[cid]++;
      }
    }
    vi ts(9);
    for (int i = 0; i < m; i++) {
      assert(cnt[i] < 9);
      ts[cnt[i]]++;
    }
    for (int i = 0; i < 9; i++) 
      printf("%d%c", ts[i], "\n "[i < 8]);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}