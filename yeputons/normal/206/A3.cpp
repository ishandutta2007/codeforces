#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vvi cs(n);
    vector<vector<pii> > bs(n);
    int scnt = 0;
    
    vi tmp;
    int answer = 0;
    bool needOut = true;

    for (int i = 0; i < n; i++) {
      int k, a, x, y, m;
      scanf("%d%d%d%d%d", &k, &a, &x, &y, &m);
      scnt += k;
      needOut = needOut && scnt <= 200000;
          
      vi ccs(k);
      for (int i2 = 0; i2 < k; i2++) {
        ccs[i2] = a;
        a = (ll(a) * x + y) % m;
      }
      int pr = -1;
      int st = 0;
      int bcnt = 0;
      for (int i2 = 0; i2 <= k; i2++) {
        if (i2 >= k || pr > ccs[i2]) {
          if (needOut)
            bs[i].pb(mp(st, i2));
          bcnt++;
          st = i2;
        }
        if (i2 < k)
          pr = ccs[i2];
      }
      answer = max(answer, bcnt - 1);
      if (needOut) cs[i] = ccs;
    }
    printf("%d\n", answer);

    if (needOut) {
      vector<pii> ord;
      vi ptrs(n, 0);

      for (int bptr = 0;; bptr++) {
        vector<pii> curs;
        bool cont = false;
        for (int i = 0; i < n; i++)
          if (sz(bs[i]) > bptr) {
            cont = true;
            if (needOut) {
              for (int i2 = bs[i][bptr].first; i2 < bs[i][bptr].second; i2++)
                curs.pb(mp(cs[i][i2], i));
            }
          }
        if (!cont) break;
        if (needOut) {
          sort(curs.begin(), curs.end());
          ord.insert(ord.end(), curs.begin(), curs.end());
        }
      }
      for (int i = 0; i < sz(ord); i++)
        printf("%d %d\n", ord[i].first, ord[i].second + 1);
    }
  }
  return 0;
}