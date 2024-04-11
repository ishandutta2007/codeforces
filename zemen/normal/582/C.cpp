#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 500001;

int a[maxn];

int gcd(int a, int b)
{
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

vector<int> lens[maxn];
vector<int> divs;
bool ok[maxn];
bool nicelen[maxn];
int blocks[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    forab (s, 1, n)
    {
        int g = gcd(s, n);
        if (g == s)
            divs.push_back(g);
        lens[g].push_back(s);
    }
    ll ans = 0;
    for (int s: divs)
    {
//        cerr << "S: " << s << '\n';
        fill(ok, ok + n, false);
        forn (rem, s)
        {
            int best = 0;
            for (int i = rem; i < n; i += s)
                best = max(best, a[i]);
            for (int i = rem; i < n; i += s)
                if (a[i] == best)
                    ok[i] = true;
        }
//        forn (i, n)
//            cerr << ok[i];
//        cerr << '\n';
        int ptr = 0;
        while (ptr < n && ok[ptr])
            ++ptr;
        if (ptr == n)
        {
            ans += (ll) sz(lens[s]) * n;
            continue;
        }
        assert(ptr < n);
        rotate(ok, ok + ptr, ok + n);
        assert(!ok[0]);
        vector<int> v;
        int total = 0;
        forn (i, n)
        {
            if (!ok[i])
                continue;
            ++total;
            if (!ok[i - 1])
                v.push_back(1);
            else
                v.back()++;
        }
        fill(blocks, blocks + n + 1, 0);
        for (auto x: v)
        {
//            cerr << "block " << x << '\n';
            blocks[x]++;
        }
        int all = sz(v);

        fill(nicelen, nicelen + n, false);
        for (auto len: lens[s])
            nicelen[len] = true;
        forab (len, 1, n)
        {
            if (nicelen[len])
            {
                ans += total;
//                cerr << len << ' ' << total << '\n';
            }
            total -= all;
            all -= blocks[len];
        }
    }
    cout << ans << '\n';
    return 0;
}