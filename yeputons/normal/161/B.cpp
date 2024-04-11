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

struct El {
  int c, t, id;
  bool operator<(const El &e) const { return c < e.c; }
};

ll calc(const vector<El> &els, const vi &ids) {
  assert(sz(ids) > 0);

  bool has = false;
  ll ans = 0;
  int minc = 2e9;
  for (int i = 0; i < sz(ids); i++) {
    El e = els[ids[i]];
    ans += e.c;
    minc = min(minc, e.c);
    if (e.t == 1)
      has = true;
  }
  ans *= 2;
  if (has) ans -= minc;
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vector<El> els(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &els[i].c, &els[i].t), els[i].id = i;
    vector<El> sels = els;
    sort(els.begin(), els.end());

    vvi res(k);
    vi bads;
    res[0].pb(els[0].id);

    int ptr = 1;

    for (int i = n - 1; i > 0; i--) if (els[i].t == 1 && ptr < k) {
      res[ptr++].pb(els[i].id);
    } else
      bads.pb(els[i].id);

    int ptr2 = 0;
    while (ptr < k) {
      assert(ptr2 < sz(bads));
      res[ptr++].pb(bads[ptr2++]);
    }
    while (ptr2 < sz(bads))
      res[0].pb(bads[ptr2++]);

    ll ans = 0;
    for (int i = 0; i < k; i++)
      ans += calc(sels, res[i]);

    printf("%I64d.%I64d\n", ans / 2, ans % 2 * 5);
    for (int i = 0; i < k; i++) {
      printf("%d", sz(res[i]));
      for (int i2 = 0; i2 < sz(res[i]); i2++)
        printf(" %d", res[i][i2] + 1);
      printf("\n");
    }
  }
  return 0;
}