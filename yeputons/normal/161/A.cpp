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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m, x, y;
  while (scanf("%d%d%d%d", &n, &m, &x, &y) >= 1) {
    vector<pii> as(n), bs(m);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i].first), as[i].second = i + 1;
    for (int i = 0; i < m; i++)
      scanf("%d", &bs[i].first), bs[i].second = i + 1;

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    vector<pii> ans;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
      while (ptr < m && bs[ptr].first < as[i].first - x)
        ptr++;
      if (ptr < m && bs[ptr].first <= as[i].first + y) {
        ans.pb(mp(as[i].second, bs[ptr].second));
        ptr++;
      }
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}