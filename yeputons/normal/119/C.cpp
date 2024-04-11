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

struct Cls {
  ll a, b, c;
  int id;
  bool operator<(const Cls &c2) const { return c < c2.c; }
};

void relax(ll &a1, int &b1, ll a2, int b2) {
  if (a1 >= a2) return;
  a1 = a2;
  b1 = b2;
}

const int MAXD = 100;
const int MAXN = 50;
const int MAXM = 50;
ll d[MAXM + 1][MAXN + 1][MAXD + 1];
int fr[MAXM + 1][MAXN + 1][MAXD + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) >= 1) {
    vector<Cls> cs(m);
    for (int i = 0; i < m; i++)
      scanf("%I64d%I64d%I64d", &cs[i].a, &cs[i].b, &cs[i].c), cs[i].id = i;
    sort(cs.begin(), cs.end());

    memset(d, 0x80, sizeof d);

    for (int i = 0; i < m; i++) {
      for (int curd = 0; curd <= MAXD; curd++) {
        ll cval = cs[i].a + curd;
        if (cval > cs[i].b) break;
        relax(d[i][1][curd], fr[i][1][curd], cval, -1);
      }

      for (int rem = n; rem > 1; rem--) {
        for (int pr = 0; pr < i; pr++) if (cs[pr].c < cs[i].c) {
          for (int prd = 0; prd <= MAXD; prd++) {
            ll pval = cs[pr].a + prd;
            if (pval > cs[pr].b) break;

            ll pans = d[pr][rem - 1][prd];

            // + k
            {
              ll cval = pval + k;
              ll curd = cval - cs[i].a;
              if (cs[i].a <= cval && cval <= cs[i].b)
                relax(d[i][rem][curd], fr[i][rem][curd], pans + cval, pr * (MAXD + 1) + prd);
            }
            // * k
            {
              ll cval = pval * k;
              ll curd = cval - cs[i].a;
              if (cval / k == pval && cs[i].a <= cval && cval <= cs[i].b)
                relax(d[i][rem][curd], fr[i][rem][curd], pans + cval, pr * (MAXD + 1) + prd);
            }
          }
        }
      }
    }

    ll bans = -1;
    int bi = -1, bd = -1;
    for (int i = 0; i < m; i++)
      for (int cd = 0; cd <= MAXD; cd++)
        if (d[i][n][cd] > bans) {
          bans = d[i][n][cd];
          bi = i;
          bd = cd;
        }
    if (bans < 0) {
      printf("NO\n");
    } else {
      printf("YES\n");

      vector<pair<int, ll> > ans;

      int i = bi, cd = bd;
      int rem = n;
      for (int rem = n;; rem--) {
        assert(rem >= 0);
        ans.pb(mp(cs[i].id, cs[i].a + cd));
        int frv = fr[i][rem][cd];
        if (frv < 0) {
          assert(rem == 1);
          break;
        }

        int prd = frv % (MAXD + 1); frv /= MAXD + 1;
        int pr = frv;
        i = pr; cd = prd;
      }

      assert(sz(ans) == n);
      reverse(ans.begin(), ans.end());
      for (int i = 0; i < sz(ans); i++)
        printf("%d %I64d\n", ans[i].first + 1, ans[i].second);
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}