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

ll getAns(ll l, ll r, int len) {
  ll c = 1;
  for (int i = 0; i < len; i++) c *= 10;
  ll best = c * 5 / 10;
  c--;

  ll ans = max(l * (c - l), r * (c - r));
  for (ll d = -5; d <= 5; d++) {
    ll cur = best + d;
    if (l <= cur && cur <= r)
      ans = max(ans, cur * (c - cur));
  }
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  ll l, r;
  while (scanf("%I64d%I64d", &l, &r) >= 2) {
    ll ans = 0;
    ll minx = 1;
    for (int len = 1; minx <= r; len++, minx *= 10) {
      ans = max(ans, getAns(max(l, minx), min(r, minx * 10 - 1), len));
    }
    printf("%I64d\n", ans);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}