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

const double PI = acos(-1.0);

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
        if (j % 64 == 0) w = base(cosl(ang*j), sinl(ang*j));
        w = w*wlen;
      }
    }
  }
  if (invert)
    for (int i=0; i<n; ++i)
      a[i] = a[i] * (1.0 / n);
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
  vi res(a.size()+b.size()-1);
  for (int i = 0; i < res.size(); ++i) res[i] = round(x[i].X);
  return res;
}

char s[500005];

int main() {
  //  std::ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    int n;
    scanf("%d%s", &n, s);
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'V') a[i] = 1;
      if (s[i] == 'K') b[i] = 1;
    }
    reverse(b.begin(), b.end());
    vi c = mul(a, b), bad(n + 1);
    for (int i = 0; i < c.size(); ++i) if (c[i]) {
      bad[abs(i + 1 - n)] = 1;
    }
    vi res;
    for (int p = 1; p <= n; ++p) {
      bool ok = 1;
      for (int i = p; i < bad.size(); i += p) if (bad[i]) {
        ok = 0; break;
      }
      if (ok) res.push_back(p);
    }
    printf("%d\n", (int)res.size());
    for (int i : res) printf("%d ", i);
    printf("\n");
  }
  return 0;
}