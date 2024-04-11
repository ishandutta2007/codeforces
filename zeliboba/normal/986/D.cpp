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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

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

typedef TPoint2D<double> base;

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
    double ang = 2*PI/len * (invert ? -1 : 1);
    base wlen (cosl(ang), sinl(ang));
    for (int i=0; i<n; i+=len) {
      base w (1, 0);
      for (int j=0; j<len/2; ++j) {
        base u = a[i+j], v = a[i+j+len/2] * w;
        a[i+j] = u + v;
        a[i+j+len/2] = u - v;
        if (j % 32 == 0) w = base(cosl(ang*j), sinl(ang*j));
        w = w*wlen;
      }
    }
  }
  if (invert)
    for (int i=0; i<n; ++i)
      a[i] = a[i] * (1.0 / n);
}

void out(const vi & v) {
  for (auto x : v) cerr << x << ' '; cerr << endl;
}

const int B = 100;
void upd(vi & res) {
  for (int i = 0; i + 1 < res.size(); ++i) {
    res[i+1] += res[i] / B;
    res[i] %= B;
  }
  while (res.back() >= B) {
    int nx = res.back() / B;
    res.back() %= B;
    res.push_back(nx);
  }
  while (res.size() > 1 && res.back() == 0) res.pop_back();
}

vi mul(const vi & a, const vi & b) {
  int n = 1;
  while (n < a.size() + b.size()) n *= 2;
  vector<base> x(n), y(n);
  for (int i = 0; i < a.size(); ++i) x[i] = base(a[i], 0);
  for (int i = 0; i < b.size(); ++i) y[i] = base(b[i], 0);
  fft(x, 0);
  fft(y, 0);
  for (int i = 0; i < x.size(); ++i) x[i] = x[i] * y[i];
  fft(x, 1);
  vi res(a.size()+b.size());
  for (int i = 0; i < res.size(); ++i) {
    res[i] = round(x[i].X);
  }
  upd(res);
  return res;
}

vi mul(vi v, int a) {
  for (int i = 0; i < v.size(); ++i) v[i] *= a;
  upd(v);
  return v;
}

bool les(const vi& a, const vi& b) {
  if (a.size() < b.size()) return true;
  if (a.size() > b.size()) return false;
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] < b[i]) return true;
    if (a[i] > b[i]) return false;
  }
  return false;
}

vi mpow(const vi& v, int n) {
  if (n == 0) return vi(1, 1);
  if (n == 1) return v;
  vi x = mpow(v, n / 2);
  x = mul(x, x);
  if (n % 2 == 1) {
    x = mul(x, v);
  }
  return x;
}

char s[2000000];

int main() {
  scanf("%s", s);
  int l = strlen(s);
  vi v0(l);
  for (int i = 0; i < l; ++i) v0[i] = s[l-i-1] - '0';
  vi v;
  for (int i = 0; i < v0.size(); i += 2) {
    v.push_back(v0[i] + 10 * (i + 1 < v0.size() ? v0[i+1] : 0));
  }
  if (v == vi(1, 1)) {
    cout << 1 << endl; return 0;
  }
  int k = (log(v.back()) + (l - 1) * log(10.)) / log(3.) - 10;
  k = max(k, 0);
  if (k % 2) --k;
  vi v3 = mpow(vi(1, 3), k);
//  cerr << k << ": ";  out(v3);
  while (les(mul(v3, 4), v)) {
    v3 = mul(v3, 3);
    ++k;
  }
//  cerr << k << ": ";  out(v3);
  int res = 3 * k + 4;
  while (les(mul(v3, 2), v)) {
    v3 = mul(v3, 3);
    ++k;
  }
//  cerr << k << ": ";  out(v3);
  res = min(res, 3 * k + 2);
  while (les(v3, v)) {
    v3 = mul(v3, 3);
    ++k;
  }
//  cerr << k << ": ";  out(v3);
  res = min(res, 3 * k);
  cout << res << endl;
  return 0;
}