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
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (as[i] >= 3 * k) {
        as[i] -= 3 * k;
      } else
        as[i] %= k;
      ans += as[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}