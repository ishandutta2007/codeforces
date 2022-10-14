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
double getTime(double len, double v, double a) {
  double t1 = v / a;
  double clen = a * t1 * t1 / 2;
  if (clen <= len + EPS) {
    double rem = len - clen;
    return t1 + rem / v;
  } else {
    double t = sqrt(len * 2 / a);
    return t;
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  double a, d;
  while (scanf("%d%lf%lf", &n, &a, &d) >= 1) {
    double ct = 0;
    for (int i = 0; i < n; i++) {
      int t, v;
      scanf("%d%d", &t, &v);
      double nt = t + getTime(d, v, a);
      nt = max(nt, ct);
      printf("%.18e\n", nt);
      ct = nt;
    }
  }
  return 0;
}