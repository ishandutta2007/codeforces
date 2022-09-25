#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int main() {
    #ifdef LOCAL
    //assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int tn;
    cin >> tn;
    forn (iter, tn) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "! 1 1" << endl;
            continue;
        }
        int mn = -1, mx = -1;
        string s;

        for (int i = 0; i < n; i += 2) {
            int mn1 = i, mx1 = i + 1;
            if (i + 1 < n) {
                cout << "? " << i + 1 << ' ' << i + 2 << endl;
                cin >> s;
                if (s == ">")
                    swap(mn1, mx1);
            } else
                mx1 = mn1;
            if (i == 0) {
                mn = mn1, mx = mx1;
                continue;
            }
            cout << "? " << mn1 + 1 << ' ' << mn + 1 << endl;
            cin >> s;
            if (s == "<")
                mn = mn1;

            cout << "? " << mx1 + 1 << ' ' << mx + 1 << endl;
            cin >> s;
            if (s == ">")
                mx = mx1;
        }
        cout << "! " << mn + 1 << ' ' << mx + 1 << endl;
    }
}