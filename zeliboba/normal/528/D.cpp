#include <cstdio>
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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
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

template<typename T> TPoint2D<T> operator*(const T& p1, const TPoint2D<T>& p2) { return p2 * p1; }

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
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1, 0);
            for (int j=0; j<len/2; ++j) {
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
    for (int i = 0; i < res.size(); ++i) res[i] = round(x[i].X);
    return res;
}

int main() {
    string s,t;
    int n,m,k;
    cin >> m >> n >> k >> s >> t;
    vi a(s.size()), b(t.size());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') a[i] = 0;
        if (s[i] == 'C') a[i] = 1;
        if (s[i] == 'G') a[i] = 2;
        if (s[i] == 'T') a[i] = 3;
    }
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == 'A') b[i] = 0;
        if (t[i] == 'C') b[i] = 1;
        if (t[i] == 'G') b[i] = 2;
        if (t[i] == 'T') b[i] = 3;
    }
    vvi w(4, vi(s.size()));
    vi c(4);
    for (int i = 0; i < min((int)a.size(), k); ++i) {
        ++c[a[i]];
    }
    for (int i = 0; i < a.size(); ++i) {
        if (i + k < a.size()) ++c[a[i+k]];
        if (i > k) --c[a[i-k-1]];
        for (int t = 0; t < 4; ++t) if (c[t])
            w[t][i] = 1;
    }
    reverse(b.begin(), b.end());
    vi res(a.size());
    for (int t = 0; t < 4; ++t) {
        vi c(a.size(), 0);
        vi d(b.size(), 0);
        for (int i = 0; i < a.size(); ++i) if (w[t][i])
            c[i] = 1;
        for (int i = 0; i < b.size(); ++i) if (b[i] == t)
            d[i] = 1;
        vi x = mul(c, d);
        for (int i = 0; i < a.size(); ++i) {
            res[i] += x[i + n - 1];
//            cerr << t << ' ' << i << ' ' << w[t][i] << ' ' << res[i] << endl;
        }
    }
    int cnt = 0;
    for (int i = 0; i + n <= a.size(); ++i) if (res[i] == n)
        ++cnt;
    cout << cnt << endl;
    return 0;
}