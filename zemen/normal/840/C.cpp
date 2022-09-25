#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

const int maxn = 305;

bool issqr(ll a, ll b) {
  ll x = a * b;
  ll r = sqrtl(x);
  while (r * r < x)
    ++r;
  while (r * r > x)
    --r;
  return r * r == x;
}

const int mod = 1e9 + 7;
void udd(int& a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
}
int mul(ll a, ll b) {
  return a * b % mod;
}
int bin(int a, int deg) {
  int r = 1;
  while (deg) {
    if (deg & 1)
      r = mul(r, a);
    deg >>= 1;
    a = mul(a, a);
  }
  return r;
}
int inv(int x) {
  assert(x);
  return bin(x, mod - 2);
}
int fact[maxn];
int ifact[maxn];

int binom(int n, int k) {
  assert(k >= 0 && k <= n);
  return mul(mul(ifact[k], ifact[n - k]), fact[n]);
}

int d[2][maxn];
int solve(vector<int> a) {
  int cnt = 0;
  int q = 0;
  d[q][0] = 1;
  for (int x : a) {
    memset(d[q ^ 1], 0, sizeof(d[q ^ 1]));

    int slots = cnt + 1;
    cnt += x;

    forn (b, maxn) {
      if (!d[q][b])
        continue;
      int g = slots - b;
      for (int t = 1; t <= min(slots, x); ++t) {
        for (int f = max(0, t - g); f <= min(t, b); ++f) {
          int nb = (b - f) + (x - t);
          int ways = binom(x - 1, x - t);

          ways = mul(ways, binom(b, f));
          ways = mul(ways, binom(g, t - f));

          udd(d[q ^ 1][nb], mul(ways, d[q][b]));
        }
      }
    }
    q ^= 1;
  }

  int res = d[q][0];
  for (int x : a) {
    res = mul(res, fact[x]);
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  forn (i, maxn) {
    fact[i] = i ? mul(fact[i - 1], i) : 1;
    ifact[i] = inv(fact[i]);
  }
  int n;
  cin >> n;
  vector<int> a(n);
  forn (i, n)
    cin >> a[i];
  vector<int> g;
  while (!a.empty()) {
    int x = a.back();
    int s = 0;
    forn (i, sz(a)) {
      if (issqr(a[i], x)) {
        a.erase(a.begin() + i);
        ++s;
        --i;
      }
    }
    g.push_back(s);
  }
  int res = solve(g);
  cout << res << '\n';
}