#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#ifdef DEBUG
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const int inf = 1e9;

ll b;
int maxk;
vi cache;
int go(ll a) {
  if (a < b) return inf;
  if (a == b) return 0;
  if (cache[a - b] < inf) return cache[a - b];

  int res = go(a - 1);
  for (int x = 2; x <= maxk; x++) {
    ll na = a - (a % x);
    if (na < a)
      res = min(res, go(na));
  }
  res++;
  return cache[a - b] = res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  ll a;
  while (scanf("%I64d%I64d%d", &a, &b, &maxk) >= 1) {
    int mod = 1;
    for (int i = 2; i <= maxk; i++)
      mod = mod * i / gcd(mod, i);

    vi ds(mod, inf);
    ds[0] = 0;
    for (int i = 1; i < mod; i++) {
      ds[i] = ds[i - 1] + 1;
      for (int x = 2; x <= maxk; x++) {
        int ni = i - (i % x);
        if (ni < i) ds[i] = min(ds[i], ds[ni] + 1);
      }
    }
    ll ans = 0;
    if (b + mod < a) {
      ans += ds[a % mod];
      a -= a % mod;
      if (b < a) {
        ans++;
        a--;
      }
      {
        ll cnt = (a - b) / mod;
        a -= cnt * mod;
        ans += cnt * (ds[mod - 1] + 1);
      }
    }
    assert(b + mod >= a);
    cache = vi(a - b + 1, inf);
    ans += go(a);
    printf("%I64d\n", ans);
  }
  return 0;
}