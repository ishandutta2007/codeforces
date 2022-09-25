#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)

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
    freopen("a.in", "r", stdin);
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
    int n;
    string s;
    cin >> n >> s;
    forn (i, n)
        forn (j, n)
        {
            if (j == 0)
                continue;
            int ok = 0;
            forn (k, 5)
            {
                int pos = i + j * k;
                if (pos < n && s[pos] == '*')
                    ++ok;
            }
            if (ok == 5)
            {
                cout << "yes\n";
                return 0;
            }
        }
    cout << "no\n";
    return 0;
}