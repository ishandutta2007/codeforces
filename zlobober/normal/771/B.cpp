#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int m;
string getNew() {
    if (m >= 26) {
        return string(1, 'A') + char(m++ - 26 + 'a');
    }
    return string(1, m++ + 'A');
}

const int maxn = 200;
string res[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        if (i < k - 1)
            res[i] = getNew();
        else {
            string type;
            cin >> type;
            if (type == "YES")
                res[i] = getNew();
            else
                res[i] = res[i - k + 1];
        }
    }
    forn (i, n)
        cout << res[i] << ' ';
    cout << '\n';
}