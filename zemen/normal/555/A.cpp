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

int solve()
{
    int n, k;
    cin >> n >> k;
    int res = n - 1;
    forn (i, k)
    {
        int c;
        cin >> c;
        vector<int> a;
        forn (i, c)
        {
            int q;
            cin >> q;
            --q;
            a.push_back(q);
        }
        a.push_back(100000000);
        res += c - 1;
        int q = 0;
        while (q == a[q])
        {
            if (q)
                res -= 2;
            ++q;
        }
    }
    cout << res << '\n';
    return 0;
}