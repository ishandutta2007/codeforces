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

const int MAXN = 100;
int ks[MAXN];
int d[MAXN + 1][3];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int tc;
  scanf("%d", &tc);
  for (int tn = 0; tn < tc; tn++) {
    ll x;
    scanf("%I64d", &x);

    ll a = 1, b = 2;
    vll fib;
    while (a <= x) {
      fib.pb(a);
      ll c = a + b;
      a = b; b = c;
    }
    int n = sz(fib);

    for (int i = n - 1; i >= 0; i--) {
      ks[n - 1 - i] = x >= fib[i];
      if (x >= fib[i])
        x -= fib[i];
    }
    assert(!x);

    memset(d, 0, sizeof d);
    d[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (!ks[i]) {
        d[i][0] = d[i + 1][0];
        d[i][2] = d[i + 1][1];
        d[i][1] = d[i + 1][0] + d[i + 1][2];
      } else {
        d[i][0] = d[i + 1][0] + d[i + 1][2];
        d[i][1] = d[i + 1][2];
      }
    }
    printf("%d\n", d[0][0]);
  }
  return 0;
}