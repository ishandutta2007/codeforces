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
int a[maxn];

int d[maxn];
pii nx[maxn];
bool bad[maxn];
int gc[maxn];
vector<int> num[maxn];
int m;

int gcd(int a, int b) {
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int phi[maxn];

int bin(ll a, int d, ll mod) {
    ll res = 1;
    while (d) {
        if (d & 1) {
            res *= a;
            res %= mod;
        }
        d >>= 1;
        a *= a;
        a %= mod;
    }
    return res;
}

int inv(ll a, ll mod) {
    return bin(a, phi[mod] - 1, mod);
}

int divide(int a, int b) {
    int g = gc[a];
    assert(gc[b] % g == 0);

    ll a1 = a / g;
    a1 = inv(a1, m / g);

    ll res = ll(b / g) * a1;
    res %= m;
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n >> m;
    forn (i, n) {
        scanf("%d", a + i);
        bad[a[i]] = true;
    }
    forn (i, m + 1)
        gc[i] = gcd(i, m);
    for (int i = 1; i <= m; ++i)
        phi[i] = i;
    for (int i = 1; i <= m; ++i) {
        for (int j = i * 2; j <= m; j += i)
            phi[j] -= phi[i];
    }
    //forn (i, 10)
        //cerr << i << ' ' << phi[i] << '\n';
    for (int g = m; g >= 1; --g) {
        if (m % g)
            continue;
        for (int i = 0; i < m; i += g) {
            if (gc[i] != g)
                continue;
            if (bad[i])
                continue;
            num[g].push_back(i);
            d[g]++;
        }
        nx[g] = {-1, -1};
        for (int to = g * 2; to <= m; to += g) {
            if (m % to)
                continue;
            nx[g] = max(nx[g], pii{d[to], to});
        }
        if (nx[g].first != -1)
            d[g] += nx[g].first;
    }

    cout << d[1] << '\n';
    int g = 1;
    vector<int> pr;
    while (g != -1) {
        pr.insert(pr.end(), num[g].begin(), num[g].end());
        g = nx[g].second;
    }
    //for (int x: pr)
        //cerr << x << ' ';
    //cerr << '\n';
    //return 0;
    vector<int> res;
    res.push_back(pr[0]);
    for (int i = 1; i < sz(pr); ++i) {
        int x = divide(pr[i - 1], pr[i]);
        ll xx = (ll(pr[i - 1]) * x) % m;
        assert(xx == pr[i]);
        res.push_back(x);
    }
    for (auto x: res)
        cout << x << ' ';
    cout << '\n';
}