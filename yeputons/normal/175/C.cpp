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

const ll INF = 9e18;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<ll> ks(n), cs(n);
    ll sumcnt = 0;
    for (int i = 0; i < n; i++)
      scanf("%I64d%I64d", &ks[i], &cs[i]), sumcnt += ks[i];

    int t;
    scanf("%d", &t);

    vll ps(t + 2, 0);
    for (int i = 0; i < t; i++)
      scanf("%I64d", &ps[i + 1]);
    while (ps[t] >= sumcnt) {
      t--;
      ps.resize(t + 2);
    }
    ps[t + 1] = sumcnt;

    vector<ll> cnts(t + 1);
    for (int i = 0; i <= t; i++) {
      cnts[i] = ps[i + 1] - ps[i];
    }

    vector<pair<ll, pii> > tys;
    for (int a = 0; a < n; a++)
    for (int b = 0; b <= t; b++)
      tys.pb(mp(cs[a] * (b + 1), mp(a, b)));
    sort(tys.begin(), tys.end());
    reverse(tys.begin(), tys.end());

    ll ans = 0;
    for (int i = 0; i < sz(tys); i++) {
      ll cc = tys[i].first;
      int a = tys[i].second.first;
      int b = tys[i].second.second;

      ll ccnt = min(cnts[b], ks[a]);
      ans += cc * ccnt;
      cnts[b] -= ccnt;
      ks[a] -= ccnt;
    }
    for (int i = 0; i < sz(cnts); i++) assert(!cnts[i]);
    for (int i = 0; i < n; i++) assert(!ks[i]);
    printf("%I64d\n", ans);
  }
  return 0;
}