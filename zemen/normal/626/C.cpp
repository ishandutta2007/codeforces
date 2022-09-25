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

int solve()
{
    int n, m;
    cin >> n >> m;
    int k = 0;
    int h = 0;
    while (n + m + k > 0)
    {
        ++h;
        if (h % 2 == 0 && h % 3 == 0)
        {
            if (n && m)
                --n, --m, ++k;
            else if (n)
                --n;
            else if (m)
                --m;
            else
                --k;
        }
        else if (h % 2 == 0)
        {
            if (n)
                --n;
            else if (k)
                --k;
        }
        else if (h % 3 == 0)
        {
            if (m)
                --m;
            else if (k)
                --k;
        }
    }
    cout << h << '\n';
    return 0;
}