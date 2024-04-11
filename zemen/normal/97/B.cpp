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

const int maxn = 100100;
pii a[maxn];

vector<pii> res;

void solve(int l, int r) {
    //cerr << "solve " << l << ' ' << r << '\n';
    if (l >= r)
        return;
    int m = (l + r) / 2;
    int x = a[m].first;
    int l1 = l, r1 = l;
    while (r1 < r && a[r1].first < x)
        ++r1;
    int l2 = r, r2 = r;
    while (l2 > l && a[l2 - 1].first > x)
        --l2;
    for (int i = l; i < r; ++i)
        res.emplace_back(x, a[i].second);
    solve(l1, r1);
    solve(l2, r2);
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    solve(0, n);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << sz(res) << '\n';
    for (auto p: res)
        cout << p.first << ' ' << p.second << '\n';
}