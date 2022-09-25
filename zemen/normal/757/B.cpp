#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int B = 100100;
int cnt[B + 5];

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int res = 1;
    for (int i = 2; i < B; ++i) {
        int cur = 0;
        for (int j = 1; j * i < B; ++j)
            cur += cnt[j * i];
        res = max(res, cur);
    }
    cout << res << '\n';
}