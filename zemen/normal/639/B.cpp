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

int n, d, h;

void fail() {
    cout << -1 << '\n';
    exit(0);
}

void solve() {
    if (d > h * 2)
        fail();
    if (d == 1 && n > 2)
        fail();
    int last = 0;
    forn (i, h) {
        cout << last + 1 << ' ' << last + 2 << '\n';
        ++last;
    }
    int cd = d - h;
    int last2 = last + 1;
    if (cd) {
        --cd;
        cout << 1 << ' ' << last2 + 1 << '\n';
        while (cd) {
            --cd;
            cout << last2 + 1 << ' ' << last2 + 2 << '\n';
            ++last2;
        }
        ++last2;
    }
    while (last2 < n) {
        cout << last << ' ' << last2 + 1 << '\n';
        ++last2;
    }
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    cin >> n >> d >> h;
    solve();

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}