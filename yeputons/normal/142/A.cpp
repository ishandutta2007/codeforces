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

ll n;
ll calc(ll a, ll b, ll c) { return a * b * c - n; }
void relax(ll &miv, ll &mav, ll val) { miv = min(miv, val); mav = max(mav, val); }

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%I64d", &n) >= 1) {
    ll miv = 9e18, mav = -1;

    for (ll a = 1; a * a * a <= n; a++)
    for (ll b = a; a * b * b <= n; b++) {
      ll c = n / a / b;
      if (a * b * c != n) continue;

      relax(miv, mav, calc(a + 1, b + 2, c + 2));
      relax(miv, mav, calc(b + 1, c + 2, a + 2));
      relax(miv, mav, calc(c + 1, a + 2, b + 2));
    }
    printf("%I64d %I64d\n", miv, mav);
  }
  return 0;
}