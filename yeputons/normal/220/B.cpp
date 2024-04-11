 #include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
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

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vi vals = as;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vi cnt(sz(vals));
    for (int i = 0; i < n; i++) {
      as[i] = lower_bound(vals.begin(), vals.end(), as[i]) - vals.begin();
      cnt[as[i]]++;
    }

    vi good;
    for (int i = 0; i < sz(vals); i++)
      if (cnt[i] >= vals[i])
        good.pb(i);

    vvi cnts(sz(good), vi(n + 1, 0));
    for (int i = 0; i < sz(good); i++) {
      for (int i2 = 0; i2 < n; i2++)
        cnts[i][i2 + 1] = cnts[i][i2] + (as[i2] == good[i]);
    }

    for (int step = 0; step < m; step++) {
      int l, r;
      scanf("%d%d", &l, &r), l--, r--;

      int ans = 0;
      for (int i = 0; i < sz(good); i++) {
        int cnt = cnts[i][r + 1] - cnts[i][l];
        ans += cnt == vals[good[i]];
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}