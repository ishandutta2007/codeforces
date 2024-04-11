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

  int n, R, r;
  while (scanf("%d%d%d", &n, &R, &r) >= 1) {
    if (2 * r >= R) {
      if (2 * r == R)
        printf(n <= 2 ? "YES\n" : "NO\n");
      else if (n == 1) {
        printf(r <= R ? "YES\n" : "NO\n");
      } else
        printf("NO\n");
    } else {
      double a = R - r;
      double b = 2 * r;
      double ansin = b / 2 / a;
      eprintf("%.2lf\n", ansin);
      double ang = 2 * asin(ansin);
      ang *= n;
      if (ang <= 2 * M_PI + EPS)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}