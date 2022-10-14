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

  ll t1, t2, x1, x2, t0;
  while (scanf("%I64d%I64d%I64d%I64d%I64d", &t1, &t2, &x1, &x2, &t0) >= 1) {
    if (t0 == t1 && t0 == t2) {
      printf("%I64d %I64d\n", x1, x2);
      continue;
    }
    if (t0 == t1) {
      printf("%I64d 0\n", x1);
      continue;
    }
    if (t0 == t2) {
      printf("0 %I64d\n", x2);
      continue;
    }

    ll ba = t2, bb = 1;
    ll by1 = 0, by2 = x2;

    ll y2 = 1;
    for (int y1 = 1; y1 <= x1; y1++) {
      ll ca, cb;
      while (y2 <= x2) {
         ca = t1 * y1 + t2 * y2;
         cb = y1 + y2;
        if (t0 * cb <= ca) break;
        y2++;
      }
      if (y2 > x2) break;

      assert(t0 * cb <= ca);
      // ca / cb <= ba / bb
      // ca * bb <= ba * cb
      if (ca * bb < ba * cb) {
        ba = ca; bb = cb;
        by1 = y1; by2 = y2;
      } else if (ca * bb == ba * cb && by1 + by2 < y1 + y2) {
        ba = ca; bb = cb;
        by1 = y1; by2 = y2;
      }
    }
    assert(by1 >= 0 && by2 >= 0);
    {
      ll ca = t1 * by1 + t2 * by2;
      ll cb = by1 + by2;
      assert(cb > 0);
    }
    printf("%I64d %I64d\n", by1, by2);
 }
  return 0;
}