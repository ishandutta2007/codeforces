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

const int MOD = 1e9 + 7;
int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int w, n;
  while (scanf("%d%d", &w, &n) >= 1) {
    vector<pii> evs;
    vector<int> pts;
    for (int i = 0; i < n; i++) {
      int st, en;
      scanf("%d%d", &st, &en);
      evs.pb(mp(en, (en + 1)));
      evs.pb(mp(st, -(en + 1)));
      pts.pb(st);
      pts.pb(en);
    }
    sort(evs.begin(), evs.end());
    sort(pts.begin(), pts.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());

    const int begin = 0;
    const int end = w;

    vi cnt(sz(pts), 0);

    int ccnt = 0; int ans = 0;
    int p = sz(evs) - 1;
    for (int i = sz(pts) - 1; i >= 0; i--) {
      if (pts[i] == end) cnt[i] = add(cnt[i], 1);
      cnt[i] = add(cnt[i], ccnt);

      if (pts[i] == begin) ans = add(ans, cnt[i]);

      while (p >= 0 && evs[p].first == pts[i]) {
        int id = lower_bound(pts.begin(), pts.end(), abs(evs[p].second) - 1) - pts.begin();
        assert(id >= i);
        if (evs[p].second > 0)
          ccnt = add(ccnt, cnt[id]);
        else
          ccnt = add(ccnt, MOD - cnt[id]);
        p--;
      }
    }
    printf("%d\n", ans);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}