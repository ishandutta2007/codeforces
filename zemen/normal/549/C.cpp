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
    int n, k;
    cin >> n >> k;
    int a[2] = {0, 0};
    forn (i, n)
    {
        int t;
        cin >> t;
        a[t % 2]++;
    }
    int win[4][4];
    forn (i, 4)
        forn (j, 4)
        {
            int b[2];
            b[0] = a[0], b[1] = a[1];
            int who = 0;
            while (b[0] + b[1] > k)
            {
                if (b[0] + b[1] == k + 1 && b[0] && b[1])
                {
                    if (b[1] % 2 == who)
                        --b[1];
                    else
                        --b[0];
                }
                else if (who == 0)
                {
                    int which;
                    if (i < 2)
                        which = i;
                    else if (i == 2)
                    {
                        if (b[0] < b[1])
                            which = 1;
                        else which = 0;
                    }
                    else
                    {
                        if (b[0] > b[1])
                            which = 1;
                        else which = 0;
                    }
                    if (b[which] == 0)
                        which ^= 1;
                    b[which]--;
                }
                else if (who == 1)
                {
                    int which;
                    if (j < 2)
                        which = j;
                    else if (j == 2)
                    {
                        if (b[0] < b[1])
                            which = 1;
                        else which = 0;
                    }
                    else
                    {
                        if (b[0] > b[1])
                            which = 1;
                        else which = 0;
                    }
                    if (b[which] == 0)
                        which ^= 1;
                    b[which]--;
                }
                who ^= 1;
            }
            win[i][j] = (b[1] % 2) ^ 1;
        }
    forn (i, 4)
    {
        bool ok = true;
        forn (j, 4)
            if (win[i][j] == 1)
                ok = false;
        if (ok)
        {
            cout << "Stannis\n";
            return 0;
        }
    }
    forn (j, 4)
    {
        bool ok = true;
        forn (i, 4)
            if (win[i][j] == 0)
                ok = false;
        if (ok)
        {
            cout << "Daenerys\n";
            return 0;
        }
    }
    assert(false);
    return 0;
}