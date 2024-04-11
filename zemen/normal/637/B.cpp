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
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif

    int n;
    cin >> n;
    vector<string> s;
    set<string> used;
    forn (i, n) {
        string t;
        cin >> t;
        s.push_back(t);
    }
    reverse(s.begin(), s.end());
    for (auto t: s) {
        if (used.count(t))
            continue;
        used.insert(t);
        cout << t << '\n';
    }

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}