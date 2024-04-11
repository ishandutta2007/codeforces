#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
typedef pair<int, int> pii;


int res = 0;

int calc(vector<pii> a, int A) {
    int p = -1;
    int ret = -inf;
    while (p + 1 < sz(a) && a[p + 1].first <= A) {
        ++p;
        ret = max(ret, a[p].second);
    }

    vector<pii> pr = a;
    forn (i, sz(pr) - 1)
        pr[i + 1].second = max(pr[i].second, pr[i + 1].second);

    int p2 = -1;
    for (; p >= 0; --p) {
        p2 = min(p2, p - 1);
        while (p2 + 1 < sz(a) && p2 + 1 < p && a[p2 + 1].first + a[p].first <= A)
            ++p2;
        if (p2 >= 0)
            res = max(res, a[p].second + pr[p2].second);
    }

    return ret;
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n, A, B;
    cin >> n >> A >> B;

    vector<pii> a;
    vector<pii> b;
    forn (i, n) {
        int beau, pr;
        char c;
        cin >> beau >> pr >> c;
        if (c == 'C')
            a.emplace_back(pr, beau);
        else
            b.emplace_back(pr, beau);
    }
    sort(all(a));
    sort(all(b));
    int ap = calc(a, A);
    int bp = calc(b, B);
    res = max(res, ap + bp);
    cout << res << '\n';
}