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

#define sqr(x) ((x) * (x))

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int x1, y1, r1;
  int x2, y2, r2;
  while (scanf("%d%d%d", &x1, &y1, &r1) >= 1) {
    scanf("%d%d%d", &x2, &y2, &r2);

    int d2 = sqr(x1 - x2) + sqr(y1 - y2);
    double ans = 0;

    if (d2 >= sqr(r1 + r2)) {
      ans = (sqrt(d2) - (r1 + r2));
    } else if (d2 >= sqr(r1 - r2)) {
      ans = 0;
    } else {
      ans = (abs(r1 - r2) - sqrt(d2));
    }

    ans /= 2;
    printf("%.18e\n", ans);
  }
  return 0;
}