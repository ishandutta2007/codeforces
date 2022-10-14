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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n, k;
  while (scanf("%d%d", &n, &k) >= 2) {
    vector<double> as(n);
    for (int i = 0; i < n; i++)
      scanf("%lf", &as[i]);

    int len = n / k;

    int q;
    scanf("%d", &q);
    vb was(n, false);

    double miv = 1e100, mav = -1e100;
    for (int i = 0; i < q; i++) {
      double csum = 0;
      for (int i2 = 0; i2 < len; i2++) {
        int x;
        scanf("%d", &x), x--;
        csum += as[x];
        was[x] = true;
      }
      csum /= len;
      miv = min(miv, csum);
      mav = max(mav, csum);
    }

    vector<double> ns;
    for (int i = 0; i < n; i++) if (!was[i]) ns.pb(as[i]);
    sort(ns.begin(), ns.end());

    int wbils = (n - sz(ns)) / len;

    if (sz(ns) >= len && wbils < k) {
      double csum = 0;
      for (int i = 0; i < len; i++) csum += ns[i];
      csum /= len;
      miv = min(miv, csum);
      mav = max(mav, csum);

      csum = 0;
      for (int i = sz(ns) - len; i < sz(ns); i++) csum += ns[i];
      csum /= len;
      miv = min(miv, csum);
      mav = max(mav, csum);
    }
    printf("%.18e %.18e\n", miv, mav);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}