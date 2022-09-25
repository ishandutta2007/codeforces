#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) ((int) (x).size())
 
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
    cin >> tn;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}
 
const int maxn = 2e5;
int a[maxn];
int b[maxn];
int killed[2][maxn];
 
int solve()
{
    int m, k;
    cin >> m >> k;
    for (int i = 1; i <= k; ++i)
        scanf("%d", a + i);
    for (int i = 0; i <= k; ++i)
        killed[0][i] = killed[1][i] = 0;
    bool angry = false;
    for (int i = 0; i < m - 1; ++i)
    {
        int c;
        scanf("%d%d", b + i, &c);
        if (!angry && c)
        {
            angry = true;
            for (int j = 0; j <= k; ++j)
                killed[1][j] = killed[0][j];
        }
        killed[0][b[i]]++;
    }
    int best = 0;
    if (angry)
    {
        best = INF;
        for (int i = 1; i <= k; ++i)
        {
            if (killed[0][i] != killed[1][i])
                continue;
            best = min(best, a[i] - killed[0][i]);
        }
        assert(best <= killed[1][0]);
    }
    for (int i = 1; i <= k; ++i)
    {
        if (angry && killed[0][i] == killed[1][i])
        {
            if (a[i] - killed[0][i] <= killed[1][0])
            {
                cout << "Y";
                continue;
            }
        }
        if (a[i] - killed[0][i] <= killed[0][0] - best)
            cout << "Y";
        else
            cout << "N";
    }
    cout << "\n";
    return 0;
}