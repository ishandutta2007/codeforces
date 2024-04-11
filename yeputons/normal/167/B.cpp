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

  int n, minw, stf;
  while (scanf("%d%d%d", &n, &minw, &stf) >= 1) {
    vector<double> ps(n); vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%lf", &ps[i]), ps[i] /= 100.0;
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vector<vector<vector<double> > > d(n + 1, vector<vector<double> >(n + 1, vector<double>(2 * n + 1, 0)));
    d[0][0][min(n, stf) + n] = 1;
    for (int i = 0; i < n; i++)
    for (int wwin = 0; wwin <= i; wwin++)
    for (int bal = -i; bal <= n; bal++) {
      double cval = d[i][wwin][bal + n];
      d[i + 1][wwin][bal + n] += cval * (1 - ps[i]);

      int nbal = bal + as[i];
      nbal = min(nbal, n);
      d[i + 1][wwin + 1][nbal + n] += cval * ps[i];
    }
    double res = 0;
    for (int wwin = minw; wwin <= n; wwin++)
    for (int bal = 0; bal <= n; bal++)
      res += d[n][wwin][bal + n];
    printf("%.18e\n", res);
  }
  return 0;
}