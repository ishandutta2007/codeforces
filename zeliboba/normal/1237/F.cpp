#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 998244353;

vi f(const vi& v) {
  vi x;
  for (int i = 0; i < v.size(); ++i) if (v[i] == 0) {
    if (i && v[i - 1] == 0) ++x.back();
    else x.push_back(1);
  }
  return x;
}

int dw(int x) {
  if (x < mod) return x;
  return x - mod;
}

vl g(const vi& x, int n) {
  vl d(n + 1);
  d[0] = 1;
  vl d1(d.size());
  vl tmp(d.size());
  for (int l : x) {
//    cerr << l << endl;
    d1.assign(d1.size(), 0);
    for (int i = 1; i <= l; ++i) {
      tmp = d1;
      d1 = d;
      for (int j = 1; j < d.size(); ++j) {
        d[j] = dw(d[j] + tmp[j - 1]);
      }
    }
  }
  return d;
}

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

vl fac(5000, 1);
vl invfac(5000, 1);

ll bin(int k, int n) {
  if (k < 0 || k > n) return 0;
  return fac[n] * invfac[n - k] % mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 1; i < fac.size(); ++i) {
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = mpow(fac[i], mod - 2);
  }
  int n, m, k;
  cin >> n >> m >> k;
  vi r(n), c(m);
  for (int i = 0; i < k; ++i) {
    int a,b,d,e;
    cin >> a >> b >> d >> e;
    r[a-1] = r[d-1] = 1;
    c[b-1] = c[e-1] = 1;
  }
  int cx = 0, cy = 0;
  for (int i = 0; i < r.size(); ++i) cx += r[i] == 0;
  for (int i = 0; i < c.size(); ++i) cy += c[i] == 0;
  vi x = f(r), y = f(c);
  vl dx = g(x, cx / 2);
  vl dy = g(y, cy / 2);
  ll res = 0;
  for (int i = 0; i <= cx / 2; ++i) for (int j = 0; j <= (cy - i) / 2; ++j) if (2 * i + j <= cx) {
//    cerr << i << ' ' << j << ' ' << dx[i] << ' ' << dy[j] << endl;
    res = (res + dx[i] * dy[j] % mod * bin(j, cx - 2 * i) % mod * bin(i, cy - 2 * j)) % mod;
  }
  cout << (res + mod) % mod << endl;
  return 0;
}