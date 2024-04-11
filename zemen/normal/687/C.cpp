#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 505;
bitset<maxn> d[maxn][maxn];
int c[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    forn (i, n)
        cin >> c[i];
    d[0][0][0] = 1;
    forn (i, n) {
        forn (s, k + 1) {
            if (s + c[i] < maxn) {
                d[i + 1][s + c[i]] |= d[i][s];
                d[i + 1][s + c[i]] |= (d[i][s] << c[i]);
            }
            d[i + 1][s] |= d[i][s];
        }
    }
    vector<int> res;
    forn (i, k + 1) {
        if (d[n][k][i])
            res.push_back(i);
    }
    cout << res.size() << '\n';
    for (auto x: res)
        cout << x << ' ';
    cout << '\n';
}