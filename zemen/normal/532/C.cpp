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
    freopen("c.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

void winner(bool c)
{
    if (!c)
        cout << "Polycarp";
    else
        cout << "Vasiliy";
    exit(0);
}

int solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    while (true)
    {
        if (x1 >= x2 && y1 >= y2)
            winner(1);
        if (x2 >= x1 && y2 >= y1)
            winner(0);
        if (x2 < x1)
            --x1;
        else if (y1 > 0)
            --y1;
        if (x1 == 0 && y1 == 0)
            winner(0);

        if (x2 > x1 && y2 > y1)
            winner(0);

        int x21 = max(0, x2 - 1);
        int y21 = max(0, y2 - 1);
        if (x21 != x1 || y21 != y1)
            x2 = x21, y2 = y21;
    }
    return 0;
}