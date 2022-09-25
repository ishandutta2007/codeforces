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
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 5001;
ll v[maxn], d[maxn], p[maxn], killed[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        cin >> v[i] >> d[i] >> p[i];
    vector<int> res;
    forn (i, n)
    {
        if (killed[i])
            continue;
        res.push_back(i + 1);
        ll kills = 0;
        ll q = v[i];
        forab (j, i + 1, n)
        {
            if (killed[j])
                continue;
            if (q >= 0)
                p[j] -= q;
            --q;
            p[j] -= kills;
            if (p[j] < 0)
            {
                killed[j] = true;
                kills += d[j];
            }
        }
    }
    cout << sz(res) << '\n';
    for (int x: res)
        cout << x << ' ';
    cout << '\n';
    return 0;
}