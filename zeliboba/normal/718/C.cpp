#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;

ll dw(ll x) {
  if (x >= mod) return x-mod;
  return x;
}

pii add(const pii& a, const pii& b) {
  return pii((a.first + b.first)%mod, (a.second + b.second)%mod);
}

pii mul(const pii& a, const pii& b) {
  return pii((a.first*b.first + 5*a.second*b.second) % mod, (a.first*b.second+a.second*b.first) % mod);
}

pii mpow(pii x, ll n) {
  pii res(1, 0);
  while (n) {
    if (n & 1) res = mul(res, x);
    x = mul(x, x);
    n /= 2;
  }
  return res;
}

const int N = 1 << 17;
class Tree {
  public:

vii a0, s;

void init(const vii & v) {
  a0.assign(2*N, pii(1, 0));
  s.assign(2*N, pii(0, 0));
  for (int i = 0; i < v.size(); ++i) s[N+i] = v[i];
  for (int i = N - 1; i > 0; --i) s[i] = add(s[2*i], s[2*i+1]);
}

void update (int v, int tl, int tr, int l, int r, pii madd) {
  if (l > r)
    return;
  if (l == tl && tr == r) {
    a0[v] = mul(a0[v], madd);
    s[v] = mul(s[v], madd);
  } else {
    int tm = (tl + tr) / 2;
    int l1 = max(l,tm+1), r1 = min(r,tm);
    int l2 = max(l, tl), r2 = min(r, tr);
/*    if (l2 <= r2) {
      a0[v] = mul(a0[v], madd);
      s[v] = mul(s[v], madd);
    }*/
    update (v*2, tl, tm, l, r1, madd);
    update (v*2+1, tm+1, tr, l1, r, madd);
    s[v] = mul(a0[v], add(s[2*v], s[2*v+1]));
  }
}

pii getsum (int v, int tl, int tr, int l, int r, pii madd) {
  if (l > r) 
    return pii(0, 0);
  if (l == tl && tr == r) {
    return mul(s[v], madd);
  } else {
    int tm = (tl + tr) / 2;
    madd = mul(madd, a0[v]);
    return add(getsum (v*2, tl, tm, l, min(r,tm), madd),
               getsum (v*2+1, tm+1, tr, max(l,tm+1), r, madd));
  }
}
};

int main() {
  int n, m;
  scanf("%d%d",&n,&m);
  vi a(n);
  vii v1(n), v2(n);
  ll inv2 = (mod + 1) / 2;
  ll inv5 = (2*mod + 1) / 5;
  pii x[2] = {pii(inv2, inv2), pii(inv2, -inv2)};
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    v1[i] = mul(mpow(x[0], a[i]), pii(0, inv5));
    v2[i] = mul(mpow(x[1], a[i]), pii(0, -inv5));
  }
  Tree f[2];
  f[0].init(v1);
  f[1].init(v2);
  for (int i = 0; i < m; ++i) {
    int type, l, r, madd;
    scanf("%d%d%d", &type, &l, &r);
    --l; --r;
    if (type == 1) {
      scanf("%d", &madd);
      f[0].update(1, 0, N-1, l, r, mpow(x[0], madd));
      f[1].update(1, 0, N-1, l, r, mpow(x[1], madd));
    } else {
      pii res = add(f[0].getsum(1, 0, N-1, l, r, pii(1, 0)), f[1].getsum(1, 0, N-1, l, r, pii(1, 0)));
//    cerr << res.first << ' ' << res.second << endl;
      assert(res.second%mod == 0);
      printf("%d\n", (int)(res.first + mod) % mod);
    }
  }
  return 0;
}