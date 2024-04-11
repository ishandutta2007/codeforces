#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
typedef pair<int, int> pii;

const int maxn = 200200;
char s[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, a, b, tmp;
    cin >> n >> a >> b >> tmp;
    scanf("%s", s);
    vector<pii> v;
    int ck = 0;
    forn (l, n) {
        if (s[l] == '1')
            continue;
        int r = l;
        while (r < n && s[r] == '0')
            ++r;
        if (r - l >= b)
            v.emplace_back(l, r);
        ck += (r - l) / b;
        l = r - 1;
    }
    assert(ck >= a);
    cout << ck - a + 1 << '\n';
    forn (iter, ck - a + 1) {
        assert(!v.empty());
        auto l = v.back().first;
        auto r = v.back().second;
        v.pop_back();
        int pos = r - b;
        cout << pos + 1 << ' ';
        r = pos;
        if (r - l >= b)
            v.emplace_back(l, r);
    }
    cout << '\n';
}