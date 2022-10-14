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
    vll as(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &as[i]);

    int cpow = 1;
    while (cpow < n) cpow <<= 1;

    ll cans = 0;
    for (int i = 0; i + 1 < n; i++) {
      while (i + cpow >= n) cpow >>= 1;
      assert(cpow > 0);
      cans += as[i];
      as[i + cpow] += as[i];
      as[i] = 0;
      printf("%I64d\n", cans);
    }
  }
  return 0;
}