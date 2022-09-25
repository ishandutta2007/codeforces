#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 1001;
ld p[maxn][maxn];
bool used[maxn];
ld M[maxn];
ld CM[maxn];

ld rem[maxn];
int n;

void calccm(int u)
{
    if (rem[u] == 1)
    {
        CM[u] = 1e18;
        return;
    }
    CM[u] = (M[u] + 1.0) / (1 - rem[u]);
}

void get(int u)
{
    used[u] = true;
    forn (i, n)
    {
        if (used[i])
            continue;
        M[i] += CM[u] * rem[i] * p[i][u];
        rem[i] *= (1 - p[i][u]);
        calccm(i);
    }
}

int solve()
{
    cin >> n;
    forn (i, n)
        forn (j, n)
        {
            int per;
            scanf("%d", &per);
            p[i][j] = (ld) per / 100.0;
        }
    forn (i, n - 1)
        rem[i] = 1;
    fill(CM, CM + n - 1, 1e18);
    get(n - 1);
    while (!used[0])
    {
        int u = -1;
        forn (i, n)
        {
            if (used[i])
                continue;
            if (u == -1 || CM[i] < CM[u])
                u = i;
        }
        assert(u != -1);
        assert(CM[u] < 1e18);
        get(u);
    }
    cout << CM[0] << '\n';
    return 0;
}