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


int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    int a;
    cin >> a;
    int res = 0;
    while (a) {
        if (a % 8 == 1)
            ++res;
        a /= 8;
    }
    cout << res << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}