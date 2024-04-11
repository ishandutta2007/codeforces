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

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n * n);
    int s = 0;
    for (int i = 0; i < n * n; i++) {
      scanf("%d", &as[i]);
      s += as[i];
    }
    assert((s % n) == 0);
    s /= n;

    sort(as.begin(), as.end());
    do {
      bool g = true;
      for (int y = 0; y < n; y++) {
        int cs = 0;
        for (int x = 0; x < n; x++)
          cs += as[y * n + x];
        g = g && cs == s;
      }
      for (int x = 0; x < n; x++) {
        int cs = 0;
        for (int y = 0; y < n; y++)
          cs += as[y * n + x];
        g = g && cs == s;
      }
      int cs1 = 0, cs2 = 0;
      for (int x = 0; x < n; x++) {
        cs1 += as[x * n + x];
        cs2 += as[(n - 1 - x) * n + x];
      }
      g = g && cs1 == s && cs2 == s;
      if (g) {
        printf("%d\n", s);
        for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
          printf("%d%c", as[y * n + x], "\n "[x + 1 < n]);
        goto end;
      }
    } while (next_permutation(as.begin(), as.end()));
    assert(false);

    end:;
  }
  return 0;
}