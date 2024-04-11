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

const int MAXL = 1e6 + 1e3;
char buf[MAXL + 1];
char t[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<string> ss(n);
    vector<vvi> nes(26, vvi(n));
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      ss[i] = buf;
    }

    for (int c = 0; c < 26; c++) {
      for (int i = 0; i < n; i++) {
        nes[c][i] = vi(sz(ss[i]), INF);
        int las = INF;
        for (int i2 = sz(ss[i]) - 1; i2 >= 0; i2--) {
          if (ss[i][i2] == 'a' + c)
            las = i2;
          nes[c][i][i2] = las;
        }
      }
    }

    int l1;
    scanf("%d", &l1);
    vi sid(l1);
    for (int i = 0; i < l1; i++) scanf("%d", &sid[i]), sid[i]--;

    vvi nes2(26, vi(l1, INF));
    for (int c = 0; c < 26; c++) {
      int las = INF;
      for (int i = l1 - 1; i >= 0; i--) {
        if (nes[c][sid[i]][0] < INF) las = i;
        nes2[c][i] = las;
      }
    }

    scanf("%s", t);
    int l2 = strlen(t);
    vector<vector<pii> > dyn(l2 + 1, vector<pii>(l2 + 1, mp(INF, INF)));
    dyn[0][0] = mp(0, 0);
    for (int p2 = 0; p2 < l2; p2++)
    for (int ans = 0; ans <= p2; ans++) {
      pii cval = dyn[p2][ans];
      if (cval.first >= INF) continue;

      if (p2 < l2) {
        dyn[p2 + 1][ans] = min(dyn[p2 + 1][ans], cval);
      }

      int c = t[p2] - 'a';
      pii npos = cval;
      if (npos.first >= l1) continue;

//      eprintf("a %d %d\n", npos.second, nes[c][sid[npos.first]][npos.second]);
      npos.second = nes[c][sid[npos.first]][npos.second];
      if (npos.second >= INF) {
        npos.first++;
        if (npos.first >= l1) continue;
        npos.first = nes2[c][npos.first];
        if (npos.first >= INF) continue;

        npos.second = nes[c][sid[npos.first]][0];
//        assert(npos.second < INF);
//        eprintf("botva\n");
      }
//      eprintf("b %c %c\n", ss[sid[npos.first]][npos.second], 'a' + c);

//      assert(ss[sid[npos.first]][npos.second] == 'a' + c);
      if (++npos.second >= sz(ss[sid[npos.first]])) {
        npos.first++;
        npos.second = 0;
      }
      dyn[p2 + 1][ans + 1] = min(dyn[p2 + 1][ans + 1], npos);
    }

    int res = 0;
    for (int ans = l2; ans >= 0; ans--) if (dyn[l2][ans].first < INF) {
      res = ans;
      break;
    }
    printf("%d\n", res);
  }
  return 0;
}