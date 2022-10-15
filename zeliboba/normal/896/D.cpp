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
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;
int mod;

ll mpow (ll x, ll n, int mod) {
  ll res = 1;
  while (n) {
    if (n & 1) 
      res = res * x % mod;
    n /= 2;
    x = x * x % mod;
  }
  return res;
}

ll up(ll x, ll y) {
  if (x < 0) x += y;
  return x;
}

ll inv (ll a, ll b) {
  ll b1 = b;
  ll xa = 1, xb = 0, ya = 0, yb = 1;
  while (a % b != 0) {
    ll t = a / b;
    a -= t * b;
    xa = (xa - t * ya) % b1;
    xb = (xb - t * yb) % b1;
    swap(a, b);
    swap(xa, ya);
    swap(xb, yb);
  }
  return up(ya%b1, b1);
}

int dw(int x, int y) {
  if (x >= y) return x-y;
  return x;
}

const int modfft = 104857601;
int g;
int root = 1;
int root_1 = inv(root, modfft);
int root_pw = 1 << 4;
const int max_root_pw = 1<<19;
int W[2][max_root_pw];

void precalcw() {
  for (g = 2; g < modfft - 1; ++g) {
    if (mpow(g, (modfft - 1) / 2, modfft) != 1) {
      break;
    }
  }
  root = mpow(g, (modfft - 1) / root_pw, modfft);
  root_1 = inv(root, modfft);
  unsigned long long r[2] = {root, root_1};
  for (int t = 0; t < 2; ++t) {
    W[t][0] = 1;
    for (int i = 1; i < root_pw; ++i) {
      W[t][i] = W[t][i-1] * r[t] % modfft;
    }
  }
}

void fft (vector<int> & a, int invert) {
  int n = (int) a.size();
  assert(root_pw == n);
  precalcw();
  for (int i = 0; i < n; ++i) if (a[i] < 0) a[i] += modfft;

  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1)
      j -= bit;
    j += bit;
    if (i < j)
      swap (a[i], a[j]);
  }

  for (int len=2, t = n/len; len<=n; len<<=1, t/=2) {
    for (int i=0; i<n; i+=len) {
      for (int j=0, pw = 0; j<len/2; ++j, pw += t) {
        int u = a[i+j];
        int v = a[i+j+len/2] * (unsigned long long)W[invert][pw] % modfft;
        a[i+j] = dw(u+v, modfft);
        a[i+j+len/2] = u-v >= 0 ? u-v : u-v+modfft;
      }
    }
  }
  if (invert) {
    unsigned long long nrev = inv(n, modfft);
    for (int i=0; i<n; ++i)
      a[i] = a[i] * nrev % modfft;
  }
}

void out(vi v) {
  for (int i = 0; i < v.size(); ++i)
    cerr << v[i] << ' ';
  cerr << endl; 
}

vi mul_stupid(const vi &x, const vi &y, int mod) {
  vi res(x.size() + y.size() - 1);
  for (int i = 0; i < x.size(); ++i) for (int j = 0; j < y.size(); ++j)
    res[i+j] = (res[i+j] + x[i]*(unsigned long long)y[j]) % mod;
  return res;
}

vi mulfft(vi x, vi y) {
  x.resize(root_pw);
  y.resize(root_pw);
  //    out(x); out(y);
  fft(x,0);
  fft(y,0);
  for (int i = 0; i < x.size(); ++i) x[i] = x[i]*(unsigned long long)y[i]%modfft;
  fft(x,1);
  //    out(x);
  return x;
}

const long double PI = acosl(-1.);
template<typename T> struct TPoint2D {
  T X, Y;
  TPoint2D() : X(), Y() {}
  TPoint2D(const T& x, const T& y) : X(x), Y(y) {}
  TPoint2D(const TPoint2D<T>& p) : X(p.X), Y(p.Y) {}
  TPoint2D& operator=(const TPoint2D<T>& p) { X = p.X; Y = p.Y; return *this; }
  T operator&(const TPoint2D<T>& p) const { return X * p.X + Y * p.Y; }
  T operator^(const TPoint2D<T>& p) const { return X * p.Y - Y * p.X; }
  TPoint2D conj() const { return TPoint2D(X, -Y); }
  TPoint2D<T> operator*(const TPoint2D<T>& p) const { return TPoint2D<T>(*this & p.conj(), -*this ^ p.conj()); }
  TPoint2D<T> operator*(const T& p) const { return TPoint2D<T>(p * X, p * Y); }
  TPoint2D<T> operator-(void) const { return TPoint2D(-X, -Y); }
  TPoint2D<T> operator+(const TPoint2D<T>& p) const { return TPoint2D(X + p.X, Y + p.Y); }
  TPoint2D<T> operator-(const TPoint2D<T>& p) const { return *this + (-p); }
  T norm() const { return X * X + Y * Y; }
};
typedef TPoint2D<long double> base;
void fft (vector<base>& a, bool invert) {
  int n = (int) a.size();
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1)
      j -= bit;
    j += bit;
    if (i < j)
      swap (a[i], a[j]);
  }
  for (int len=2; len<=n; len<<=1) {
    long double ang = 2*PI/len * (invert ? -1 : 1);
    base wlen (cos(ang), sin(ang));
    for (int i=0; i<n; i+=len) {
      base w (1, 0);
      for (int j=0; j<len/2; ++j) {
        w = base(cosl(ang*j), sinl(ang*j));
        base u = a[i+j],  v = a[i+j+len/2] * w;
        a[i+j] = u + v;
        a[i+j+len/2] = u - v;
        w = w*wlen;
      }
    }
  }
  if (invert)
    for (int i=0; i<n; ++i)
      a[i] = a[i] * (1.0 / n);
}

vi mul(const vi & a, const vi & b, int mod) {
  int n = a.size() + b.size();
  if (n < 25) return mul_stupid(a, b, mod);
  while (root_pw < n) root_pw *= 2;
  assert(root_pw <= max_root_pw);
  //    cerr << a.size() << ' ' << b.size() << ' ' << root_pw << endl;
  vector<base> x(root_pw), y(root_pw);
  for (int i = 0; i < a.size(); ++i) x[i] = base(a[i], 0);
  for (int i = 0; i < b.size(); ++i) y[i] = base(b[i], 0);
  fft(x, 0);
  fft(y, 0);
  for (int i = 0; i < x.size(); ++i) x[i] = x[i] * y[i];
  fft(x, 1);
  vi xd = mulfft(a, b);
  //out(xd);
  vi res(root_pw);
  for (int i = 0; i < res.size(); ++i) {
    res[i] = ((long long)round((x[i].X - xd[i]) / modfft) % mod * modfft + xd[i]) % mod;
    //        res[i] = xd[i];
  }
  while (res.size() > 1 && res.back() == 0) res.pop_back();
  return res;
}

vi p, pw;

void fillp(int mod) {
  for (int d = 2; d * d <= mod; ++d) if (mod % d == 0) {
    p.push_back(d);
    pw.push_back(0);
    while (mod % d == 0) {
      mod /= d;
      ++pw.back();
    }
  }
  if (mod > 1) {
    p.push_back(mod);
    pw.push_back(1);
  }
}

vvi fact;

ll bin(int i, int k) {
  if (i > k || i < 0) return 0;
  assert(k < fact.size());
  ll r = fact[k].back() * inv(fact[i].back() * (ll)fact[k-i].back() % mod, mod) % mod;
  for (int j = 0; j < p.size(); ++j) {
    int c = fact[k][j] - fact[i][j] - fact[k-i][j];
    assert(c >= 0);
    r = r * mpow(p[j], c, mod) % mod;
  }
  return r;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, l, r;
  cin >> n >> mod >> l >> r;
  fillp(mod);
  fact.assign(3 * n + 15, vi(p.size() + 1, 0));
  fact[0].back() = 1;
  for (int i = 1; i < fact.size(); ++i) {
    fact[i] = fact[i-1];
    ll cur = i;
    for (int j = 0; j < p.size(); ++j) {
      while (cur % p[j] == 0) {
        cur /= p[j];
        ++fact[i][j];
      }
    }
    fact[i].back() = fact[i].back() * cur % mod;
  }
  vi a(2 * n + 5), b(2 * n + 5);
  for (int i = 0; i <= n && 3 * i < a.size(); ++i) {
    a[3 * i] = bin(i, n);
    if (i % 2) a[3 * i] = mod - a[3 * i];
  }
  for (int i = 0; i < b.size(); ++i) {
    b[i] = bin(i, i + n - 1);
  }
  vi res = mul(a, b, mod);
  //vi res = mul_stupid(a, b, mod);
//  out(a); out(b); out(res);
  ll sum = 0;
  for (int i = l; i <= r; ++i) {
//    cerr << res[i+n] << ' ' << res[i+2+n] << endl;
    sum += res[i + n];
    if (i + 2 <= n) sum -= res[i + 2 + n];
  }
  cout << (sum % mod + mod) % mod << endl;
  return 0;
}