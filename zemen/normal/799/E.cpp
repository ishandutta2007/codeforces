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

const int maxn = 200200;
int n, m, k;
int ccc[maxn];
int msk[maxn];

ll res = infl;
ll cur;

ll pr[maxn];

vector<ll> v3;
vector<pii> v1;
vector<pii> v2;
set<pii> vall;

auto it = vall.begin();
int itpos = 0;

void ans() {
    if (res == infl)
        res = -1;
    cout << res << '\n';
    exit(0);
}

void del(pii x) {
    if (it == vall.end() || *it > x)
        cur -= x.first, itpos--;
    if (it != vall.end() && *it == x)
        ++it;
    vall.erase(x);
}

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    cin >> n >> m >> k;
    forn (i, n)
        scanf("%d", ccc + i);
    int q;
    cin >> q;
    forn (i, q) {
        int x;
        scanf("%d", &x);
        --x;
        msk[x] |= 1;
    }
    cin >> q;
    forn (i, q) {
        int x;
        scanf("%d", &x);
        --x;
        msk[x] |= 2;
    }
    forn (i, n) {
        if (msk[i] < 3)
            vall.emplace(ccc[i], i);
        if (msk[i] == 1)
            v1.emplace_back(ccc[i], i);
        if (msk[i] == 2)
            v2.emplace_back(ccc[i], i);
        if (msk[i] == 3)
            v3.push_back(ccc[i]);
    }
    sort(all(v3));
    sort(all(v1));
    sort(all(v2));
    reverse(all(v1));
    reverse(all(v2));
    forn (i, sz(v3))
        pr[i + 1] = pr[i] + v3[i];

    cur = pr[min(m, sz(v3))];
    it = vall.begin();

    for (int p = min(m, sz(v3)); p >= 0; --p) {
        //cerr << "p " << p << '\n';
        while (p < k) {
            if (v1.empty() || v2.empty())
                ans();
            del(v1.back());
            del(v2.back());
            cur += v1.back().first;
            cur += v2.back().first;
            v1.pop_back();
            v2.pop_back();
            --k;
            m -= 2;
        }
        while (it != vall.end() && itpos + p < m) {
            cur += it->first;
            ++itpos;
            ++it;
        }
        while (it != vall.begin() && itpos + p > m) {
            --it;
            --itpos;
            cur -= it->first;
        }
        if (itpos + p == m)
            res = min(res, cur);

        if (p)
            cur -= v3[p - 1];
    }
    ans();
}