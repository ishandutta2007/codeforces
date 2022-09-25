#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int xl1, xr1, yl1, yr1;
int xl2, xr2, yl2, yr2;
int asks;

int ask(int x1, int y1, int x2, int y2) {
    ++x1, ++y1;
    ++asks;
    assert(asks <= 200);
#ifdef LOCAL
    int res = 0;
    if (x1 <= xl1 && xr1 <= x2 && y1 <= yl1 && yr1 <= y2)
        ++res;
    if (x1 <= xl2 && xr2 <= x2 && y1 <= yl2 && yr2 <= y2)
        ++res;
    cerr << "ask " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << res << '\n';
    return res;
#endif
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int x;
    cin >> x;
    return x;
}

int n;

int binsearch(int coord, int bound, bool rev) {
    //cerr << "search\n";
    int L = 0, R = n;
    while (L + 1 < R) {
        int C = (L + R) / 2;
        int a[] = {0, 0, n, n};
        a[coord] = C;
        int res = ask(a[0], a[1], a[2], a[3]);
        //cerr << "res " << res << '\n';
        if ((res >= bound) ^ rev)
            L = C;
        else
            R = C;
    }
    if (rev)
        return R;
    else
        return L;
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    cin >> n;
    cin >> xl1 >> yl1 >> xr1 >> yr1;
    cin >> xl2 >> yl2 >> xr2 >> yr2;
    #else
    cin >> n;
    #endif
    int xl1 = binsearch(0, 2, false);
    int xl2 = binsearch(0, 1, false);
    int xr1 = binsearch(2, 1, true);
    int xr2 = binsearch(2, 2, true);
    if (xl2 < xr1 && ask(xl2, 0, xr1, n) > 0) {
        swap(xr1, xr2);
    }

    int yl1 = binsearch(1, 2, false);
    int yl2 = binsearch(1, 1, false);
    int yr1 = binsearch(3, 1, true);
    int yr2 = binsearch(3, 2, true);
    if (yl2 < yr1 && ask(0, yl2, n, yr1) > 0) {
        swap(yr1, yr2);
    }
    
    if (ask(xl1, yl1, xr1, yr1) != 1 || ask(xl2, yl2, xr2, yr2) != 1) {
        swap(yl1, yl2);
        swap(yr1, yr2);
    }
    assert(ask(xl1, yl1, xr1, yr1) == 1);
    assert(ask(xl2, yl2, xr2, yr2) == 1);
    cout << "! " << xl1 + 1 << ' ' << yl1 + 1 << ' ' << xr1 << ' ' << yr1 << ' ' << xl2 + 1 << ' ' << yl2 + 1 << ' ' << xr2 << ' ' << yr2 << endl;

    //cerr << xl1 + 1 << ' ' << yl1 + 1 << ' ' << xr1 << ' ' << yr1 << '\n';
    //cerr << xl2 + 1 << ' ' << yl2 + 1 << ' ' << xr2 << ' ' << yr2 << '\n';
}