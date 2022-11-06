#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 123;

int pow2[MAXN];
int fakt[MAXN];
int ifakt[MAXN];

int power_mod(int b, int e) {
  int ret = 1;
  int p2 = b;
  for (; e; e >>= 1) {
    if (e&1) ret = ret*(llint)p2 % mod;
    p2 = p2*(llint)p2 % mod;
  }
  return ret;
}

inline int binom(int n, int k) {
  if (n < 0 || k < 0 || n-k < 0) return 0;
  return fakt[n] * (llint)ifakt[k] % mod * (llint)ifakt[n-k] % mod;
}

int main(void)
{
  struct Par { int t, idx; };

  // LL na *
  int n; scanf("%d", &n); // ne koristi n!
  vector<Par> V;
  REP(x, n) {
    int t; scanf("%d", &t); --t;
    if (t != -1) {
      V.push_back({t, x});
    }
  }
  sort(V.begin(), V.end(), [](Par a, Par b) {
      return a.t < b.t;
    });

  fakt[0] = 1;
  for (int f = 1; f < MAXN; ++f) fakt[f] = fakt[f-1] * (llint)f % mod;
  ifakt[MAXN-1] = power_mod(fakt[MAXN-1], mod-2);
  for (int f = MAXN-2; f >= 0; --f) ifakt[f] = ifakt[f+1] * (llint)(f+1) % mod;
  for (int f = 1; f < MAXN; ++f) assert(fakt[f] * (llint)ifakt[f] % mod == 1); // !!!
  pow2[0] = 1; for (int e = 1; e < MAXN; ++e) pow2[e] = pow2[e-1] * 2LL % mod;

  if (V.size() == 0) { printf("%d\n", pow2[n-1]); return 0; }

  int sol = 0;
  int lo, hi;
  int cnt = 1;

  auto proc = [n, &lo, &hi, &cnt](Par p) {
    if (cnt == 0) return;
    if (lo <= p.idx && p.idx <= hi) { cnt = 0; return; }

    int t = hi-lo+1;
    int bet = p.t - t;

    if (p.idx < lo) {
      int side = lo - p.idx - 1;
      int other = bet - side;
      cnt = cnt * (llint)binom(bet, side) % mod;
      lo = p.idx;
      hi += other;
    } else {
      int side = p.idx - hi - 1;
      int other = bet - side;
      cnt = cnt * (llint)binom(bet, side) % mod;
      hi = p.idx;
      lo -= other;
    }

    if (lo < 0 || hi >= n) cnt = 0;
  };

  auto finish = [&]() {
    int r = n - hi - 1;
    int l = lo;
    cnt = cnt * (llint)binom(l+r, l) % mod;
    lo = 0; hi = n-1;
  };

  // nalijevo
  if (V[0].idx - V[0].t >= 0) {
    lo = V[0].idx - V[0].t; // sync
    hi = V[0].idx;
    cnt = V[0].t-1 >= 0 ? pow2[V[0].t - 1] : 1;

    for (int i = 1; i < (int)V.size(); ++i)
      proc(V[i]);
    finish();

    sol += cnt;
    sol %= mod;
  }

  // nadesni
  if (V[0].t > 0 && V[0].idx + V[0].t < n) {
    lo = V[0].idx;
    hi = V[0].idx + V[0].t;
    cnt = V[0].t-1 >= 0 ? pow2[V[0].t - 1] : 1;

    for (int i = 1; i < (int)V.size(); ++i)
      proc(V[i]);
    finish();

    sol += cnt;
    sol %= mod;
  }

  printf("%d\n", sol);
  return 0;
}