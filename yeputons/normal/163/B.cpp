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

#define EPS 1e-8
struct Animal {
  int m;
  double v;
  int id;

  bool operator<(const Animal &a2) const { return m != a2.m ? m < a2.m : v < a2.v - EPS; }
};

const int MAXS = 100;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k, h;
  while (scanf("%d%d%d", &n, &k, &h) >= 1) {
    vector<Animal> as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i].m);
    for (int i = 0; i < n; i++)
      scanf("%lf", &as[i].v), as[i].id = i + 1;
    sort(as.begin(), as.end());

    double L = 0, R = 1e9 + 1000;
    vi lafr;
    
    for (int step = 0; step < MAXS; step++) {
      double T = (L + R) / 2;
      vi maxp(n);
      for (int i = 0; i < n; i++) {
        maxp[i] = (int)min(T * as[i].v + EPS, n + 10.0) - 1;
      }

      vi ans(n + 1, 0);
      vi fr(n + 1, -1);
      ans[n] = k;
      for (int i = n - 1; i >= 0; i--) {
        ans[i] = ans[i + 1];
        int npos = ans[i + 1] - 1;
        if (npos <= maxp[i] && npos >= 0) {
          ans[i] = npos;
          fr[i] = 1;
        }
      }
      if (ans[0] > 0) L = T;
      else { lafr = fr; R = T; }
    }

    vi res;
    for (int x = 0; x < n; x++) if (lafr[x] > 0) res.pb(as[x].id);
    assert(sz(res) == k);
    for (int i = 0; i < k; i++)
      printf("%d%c", res[i], "\n "[i + 1 < k]);
  }
  return 0;
}