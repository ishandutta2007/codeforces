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

ll getFir(ll minx, ll fir, ll step) {
  if (minx <= fir) return fir;
  minx -= fir;
  if (minx % step == 0) return fir + minx;
  minx += step - minx % step;
  return fir + minx;
}

vector<pair<ll, ll> > getMlen(ll l, ll r, int c) {
  ll len = (1LL << c) - 1;

  ll step = (1LL << (c + 1));
  ll fir = getFir(l, (1LL << c), step);

  vector<pair<ll, ll> > res;
//  eprintf("%I64d..%I64d; %d\n", l, r, c);
//  eprintf("step=%I64d, fir=%I64d\n", step, fir);
  for (int i = 0; fir <= r && i < 3; fir += step, i++) {
    res.pb(mp(min(len, fir - l), min(len, r - fir)));
//    eprintf("pb(%I64d %I64d)\n", min(len, fir - l), min(len, r - fir));
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  ll l1, r1, l2, r2;
  while (scanf("%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2) >= 1) {
    ll ans = 0;
    for (int cmax = 0; cmax < 30; cmax++) {
      vector<pair<ll, ll> > p1 = getMlen(l1, r1, cmax), p2 = getMlen(l2, r2, cmax);
      for (int i = 0; i < sz(p1); i++)
      for (int j = 0; j < sz(p2); j++)
        ans = max(ans, min(p1[i].first, p2[j].first) + 1 + min(p1[i].second, p2[j].second));
    }
    printf("%I64d\n", ans);
//    break;
  }
  return 0;
}