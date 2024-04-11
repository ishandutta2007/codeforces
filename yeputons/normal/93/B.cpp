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
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  double w;
  while (scanf("%d%lf%d", &n, &w, &m) >= 3) {
    double nw = w * n / m;
    try {
      vector<double> rem(n, w);
      vector<vector<pair<int, double> > > res(m);
      vi was(n, 0);

      int ptr = 0;
      for (int i = 0; i < m; i++) {
        double crem = nw;
        while (crem > EPS) {
          while (rem[ptr] <= EPS)
            if (++ptr >= n) ptr = 0;

          double d = min(rem[ptr], crem);
          if (++was[ptr] > 2) throw 0;
          rem[ptr] -= d; crem -= d;
          res[i].pb(mp(ptr, d));
        }
      }
      printf("YES\n");
      for (int i = 0; i < m; i++)
        for (int i2 = 0; i2 < sz(res[i]); i2++)
          printf("%d %.18lf%c", res[i][i2].first + 1, res[i][i2].second, "\n "[i2 + 1 < sz(res[i])]);
    } catch (...) {
      printf("NO\n");
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}