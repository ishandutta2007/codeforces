#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long llong;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

typedef complex<double> base;
const int LG = 21;
const double pi = acosl(-1);

vector<base> ang[LG + 1];

void initFFT() {
    ang[LG].resize(1 << LG);
    forn (i, 1 << LG)
        ang[LG][i] = polar(1., i * 2 * pi / (1 << LG));
    for (int k = LG - 1; k >= 0; --k) {
        ang[k].resize(1 << k);
        forn (i, 1 << k)
            ang[k][i] = ang[k + 1][i * 2];
    }
}

void recFFT(base *a, int lg, bool inv) {
    if (lg == 0)
        return;
    int hlen = (1 << lg) >> 1;
    recFFT(a, lg - 1, inv);
    recFFT(a + hlen, lg - 1, inv);

    forn (i, hlen) {
        base w = ang[lg][i];
        if (inv)
            w = conj(w);
        base u = a[i];
        base v = a[i + hlen] * w;
        a[i] = u + v;
        a[i + hlen] = u - v;
    }
}

void fft(base *a, int lg, bool inv) {
    int n = 1 << lg;
    int j = 0, bit;
    for (int i = 1; i < n; ++i) {
        for (bit = n >> 1; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    recFFT(a, lg, inv);
    if (inv)
        forn (i, n) {
            a[i] /= double(n);
        }
}

const int maxn = 2100100;
base a[maxn];
base b[maxn];
bool bad[maxn];

void solve() {
    string s;
    int n;
    cin >> n >> s;

    int lg = 1;
    while ((1 << lg) <= 2 * n + 5)
        ++lg;
    forn (i, 1 << lg)
        a[i] = b[i] = 0;

    forn (i, n) {
        if (s[i] == 'V')
            a[i] = 1;
        else if (s[i] == 'K')
            b[n - i] = 1;
    }
    fft(a, lg, false);
    fft(b, lg, false);
    forn (i, 1 << lg)
        a[i] *= b[i];
    fft(a, lg, true);

    //cerr << fixed;
    //cerr.precision(3);
    //forn (i, 1 << lg)
        //cerr << a[i] << '\n';

    forn (i, n + 1)
        bad[i] = false;
    for (int i = 1; i <= n; ++i)
        if (a[n - i].real() > 0.5 || a[n + i].real() > 0.5)
            bad[i] = true;
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i)
            bad[i] |= bad[j];
        if (!bad[i])
            res.push_back(i);
    }
    cout << sz(res) << '\n';
    for (int x: res)
        cout << x << ' ';
    cout << '\n';
}

int main() {
#ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    initFFT();
    int tn;
    cin >> tn;
    forn (i, tn)
        solve();
}