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

const int MAXL = 1e6;
char s[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int k, L, R;
  while (scanf("%s%d%d%d", s, &k, &L, &R) >= 1) {
    k *= 2;
    vector<char> cs(k);
    vi mivs(k), ks(k);
    for (int i = 0; i < k;) {
      int l, r;
      scanf(" %c%d%d", &cs[i], &l, &r), cs[i];
      mivs[i] = r + 1; ks[i] = -1;
      i++;

      cs[i] = cs[i - 1];
      mivs[i] = l; ks[i] = 1;
      i++;
    }
    int n = strlen(s);

    vvi poses(128);
    vi pid(n);
    for (int i = n - 1; i >= 0; i--) {
      int c = s[i];
      pid[i] = sz(poses[c]);
      poses[c].pb(i);
    }

    int zcnt = 0;
    for (int i = 0; i < k; i++)
      if (mivs[i] == 0)
        zcnt += ks[i];

    vi cnt(n, zcnt);
    int ccnt = 0;
    ll ans = 0;
    for (int st = n - 1; st >= 0; st--) {
      int c = s[st];
//      eprintf("st=%d: %c; cnt=%d\n", st, c, cnt[st]);

      if (L <= cnt[st] && cnt[st] <= R)
        ccnt++;

      for (int i = 0; i < k; i++) if (cs[i] == c && mivs[i] >= 1 && mivs[i] <= pid[st] + 1) {
//        eprintf("  cond: >=%d, k=%d\n", mivs[i], ks[i]);
        int npid = pid[st] - mivs[i] + 1;
        assert(npid >= 0);
        int l = poses[c][npid];
        int r = npid > 0 ? poses[c][npid - 1] : n;
//        eprintf("  l=%d, r=%d\n", l, r);

        assert(st <= l && l <= r && r <= n);
        for (int i2 = l; i2 < r; i2++) {
          bool ov = L <= cnt[i2] && cnt[i2] <= R;
          cnt[i2] += ks[i];
//          eprintf("  cnt[%d]=%d\n", i2, cnt[i2]);
          bool nv = L <= cnt[i2] && cnt[i2] <= R;
          ccnt += ((int)nv - ov);
        }
      }

//      eprintf(" ccnt=%d\n", ccnt);
      ans += ccnt;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}