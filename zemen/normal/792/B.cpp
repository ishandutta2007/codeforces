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
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    int pos = 0;
    forn (i, k) {
        //cerr << pos << '\n';
        int c;
        cin >> c;
        pos += c;
        pos %= sz(a);
        cout << a[pos] + 1 << ' ';
        a.erase(a.begin() + pos);
        if (pos == sz(a))
            pos = 0;
    }
    cout << '\n';
}