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
bool cmp(double a, double b) { return fabs(a - b) < EPS; }

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, l, v1, v2;
  while (scanf("%d%d%d%d", &n, &l, &v1, &v2) >= 1) {
    vll as(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &as[i]);
    sort(as.begin(), as.end());
    as.resize(n + n);
    for (int i = 0; i < n; i++) as[i + n] = as[i] + 2ll * l;

    double slen = double(l) * v2 / double(v1 + v2);
    eprintf("slen=%.2lf\n", slen);

    vector<pair<double, int> > evs;
    vector<double> xs;
    for (int i = 0; i < sz(as); i++) {
      evs.pb(mp(as[i] - slen, 1));
      evs.pb(mp(as[i], -1));

      if (as[i] - slen > EPS && as[i] - slen < 2 * l - EPS)
        xs.pb(as[i] - slen);
      if (as[i] > EPS && as[i] < 2 * l - EPS)
        xs.pb(as[i]);
    }
    xs.pb(0); xs.pb(2 * l);
    sort(evs.begin(), evs.end());
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end(), cmp), xs.end());

    int ptr = 0;
    int ccnt = 0;

    vector<double> res(n + 1);
    for (int i = 0; i + 1 < sz(xs); i++) {
      while (ptr < sz(evs) && evs[ptr].first <= xs[i] + EPS)
        ccnt += evs[ptr++].second;
      double clen = xs[i + 1] - xs[i];
      res[ccnt] += clen;
    }
    for (int i = 0; i <= n; i++)
      printf("%.18lf\n", res[i] / 2 / l);
  }
  return 0;
}