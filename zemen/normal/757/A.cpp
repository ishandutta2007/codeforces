#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int cnt[1000];

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    string s;
    cin >> s;
    for (char c: s)
        cnt[int(c)]++;
    int res = inf;
    res = min(res, cnt[int('B')]);
    res = min(res, cnt[int('u')] / 2);
    res = min(res, cnt[int('l')]);
    res = min(res, cnt[int('b')]);
    res = min(res, cnt[int('a')] / 2);
    res = min(res, cnt[int('s')]);
    res = min(res, cnt[int('r')]);
    cout << res << '\n';
}