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

const char *ACS = "RGB";
int geti(const char c) { return strchr(ACS, c) - ACS; }

const int MAXL = 1e6 + 1e3;
char s1[MAXL + 1], s2[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s%s", s1, s2) >= 1) {
    int l1 = strlen(s1), l2 = strlen(s2);
    ll ans = 0;
      vi lpos(l2, 0);
      int cl = 0;
      for (int r = 0; r < l2; r++) {
        lpos[r] = cl;
        if (s1[cl] == s2[r]) cl++;
      }
      vi rpos(l2, l1 - 1);
      int cr = 0;
      for (int l = 0; l < l1 && cr < l2; l++) {
        rpos[cr] = min(l1 - 1, l);
        if (s1[l] == s2[cr]) cr++;
      }
      for (int i = 0; i < l2; i++) {
//        eprintf("%d: %d..%d\n", i, lpos[i], rpos[i]);
        if (lpos[i] <= rpos[i])
          ans += rpos[i] - lpos[i] + 1;
      }

    vi c1s[9];
    for (int i = 0; i < 9; i++) c1s[i] = vi();

    for (int i = 0; i + 1 < l1; i++) {
      int cty = geti(s1[i]) * 3 + geti(s1[i + 1]);
      c1s[cty].pb(i + 1);
    }

    for (int i = 0; i + 1 < l2; i++) {
      int cty = geti(s2[i + 1]) * 3 + geti(s2[i]);
      if (s2[i] == s2[i + 1]) continue;

      int l1 = max(lpos[i], lpos[i + 1] + 1);
      int r1 = min(rpos[i], rpos[i + 1]);

      if (l1 <= r1) {
        int cri = upper_bound(c1s[cty].begin(), c1s[cty].end(), r1) - c1s[cty].begin();
        int cle = lower_bound(c1s[cty].begin(), c1s[cty].end(), l1) - c1s[cty].begin();
        ans -= cri - cle;
//        eprintf("i2=%d, cty=%d; %d; %d..%d\n", i, cty, cri - cle, l1, r1);
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}