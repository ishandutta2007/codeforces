#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
double mx[maxn], mn[maxn];
double smx[maxn], smn[maxn];
double s[maxn], t[maxn];

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        scanf("%lf", mx + i);
    }
    forn (i, n) {
        scanf("%lf", mn + i);
    }
    forn (i, n) {
        smx[i + 1] = smx[i] + mx[i];
        smn[i + 1] = smn[i] + mn[i];
    }
    forn (i, n) {
        double prod = smx[i + 1];
        double sum = 1 + prod - (1 - smn[i + 1]);

        double B = -sum, C = prod;
        double D = sqrt(max(0., B * B - 4 * C));
        double s = (-B + D) / 2.;
        double t = (-B - D) / 2.;
        if (s > t)
            swap(s, t);
        ::s[i + 1] = s, ::t[i + 1] = t;
        //cerr << s * t << ' ' << prod << '\n';
        //cerr << s + t << ' ' << sum << '\n';
    }
    forn (i, n)
        cout << s[i + 1] - s[i] << ' ';
    cout << '\n';
    forn (i, n)
        cout << t[i + 1] - t[i] << ' ';
    cout << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}