#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
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
    vi f(n + 1, 0);
    vi fx(n + 1, 0);
    vi mink(n + 1, 1e9);

    for (int i = 2; i <= n; i++) {
      vi vals;
      for (int k = 2; k * k <= 2 * i; k++) if (2 * i % k == 0) {
        int ak = 2 * i / k - k + 1;
        if (ak % 2 != 0) continue;
        ak /= 2;
        if (ak <= 0) continue;
        assert(k * (k + 2 * ak - 1) == 2 * i);

        int val = fx[ak + k - 1] ^ fx[ak - 1];
        if (!val)
          mink[i] = min(mink[i], k);
        vals.pb(val);
      }
      sort(vals.begin(), vals.end());
      vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
      for (f[i] = 0; f[i] < sz(vals) && vals[f[i]] == f[i]; f[i]++);

      fx[i] = fx[i - 1] ^ f[i];
    }
    eprintf("f[%d]=%d\n", n, f[n]);
    if (!f[n]) printf("-1\n");
    else printf("%d\n", mink[n]);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}