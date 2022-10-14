#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

int n;
vector<double> x;

vector<double> radius;
vi s;
void relax(int i, int j) {
  int t = s[j];
  radius[i] = min(radius[i], (x[i] - x[j]) * (x[i] - x[j]) / (4 * radius[t]));
}
const double EPS = 1e-9;

vector<double> p;
double solve(int botva) {
  radius.clear();
  s.clear();

  double sum = 0;
  for (int i = 0; i < n; i++) {
    radius.pb(p[i]);
    for (int j = 0; j < sz(s) && j < botva; j++) {
      relax(i, sz(s) - j - 1);
    }
    while (!s.empty() && radius[s.back()] <= radius[i] + EPS) {
      s.pop_back();
    }
    s.pb(i);
    sum += radius[i];
  }
  eprintf("%.4lf\n", radius[n - 1]);
  return sum;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  n = 500;
  x.resize(0);
  p.resize(0);

  x.pb(0);
  p.pb(5e5);

  const double FFR = 500;
  double cx = 1e5, cr = FFR;
  x.pb(cx);
  p.pb(cr);
  for (int i = 2; i < n - 1; i++) {
    double maxd = sqrt(4 * cr * cr);
    assert(maxd > 1);
    int nx = (int)(cx + maxd - EPS);
    x.pb(nx);
    p.pb(FFR);
    cr = (nx - cx) * (nx - cx) / (4 * cr);

    cx = nx;
  }

  x.pb(1e6);
  p.pb(1e6);
  assert(sz(x) == n);
  assert(sz(p) == n);
    double d = solve(300);
    d -= solve(1000);
    eprintf("d=%.2lf\n", d);
    if (d > 2) {
      printf("%d\n", n);
      for (int i = 0; i < n; i++)
        printf("%d %d\n", (int)(x[i] + 0.4), (int)(p[i] + 0.4));
    }
  return 0;
}