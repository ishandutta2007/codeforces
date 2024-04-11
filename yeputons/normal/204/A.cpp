#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

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

ll calc(ll x) {
  ll res = 0;
  for (int i = 1; i <= 9; i++)
    if (i <= x) res += 1;

  ll base = 10;
  for (int len = 2; len <= 18; len++, base *= 10) {
    for (int d = 1; d < 10; d++) {
      ll minn = (base + 1) * d;
      ll maxn = (base + 1) * d + (base / 10 - 1) * 10;
      if (minn <= x) {
        res += (min(maxn, x) - minn) / 10 + 1;
      }
    }
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  ll L, R;
  while (scanf("%I64d%I64d", &L, &R) >= 1) {
    ll res = calc(R);
    if (L > 0) res -= calc(L - 1);
    printf("%I64d\n", res);
  }
  return 0;
}