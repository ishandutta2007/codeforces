#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

string days[] = {
    "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"
};

int get(string s) {
    forn (i, 7)
        if (s == days[i])
            return i;
    assert(false);
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    string s, t;
    cin >> s >> t;
    int a = get(s), b = get(t);
    if (a == b || (a + 2) % 7 == b || (a + 3) % 7 == b)
        cout << "YES\n";
    else
        cout << "NO\n";
}