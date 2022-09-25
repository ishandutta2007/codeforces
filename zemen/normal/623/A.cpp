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

const int maxn = 505;
bool a[maxn][maxn];
bool eq[maxn][maxn];
int comp[maxn];
vector<int> g[maxn];

void ass(bool eq)
{
    if (!eq)
    {
        cout << "No\n";
        exit(0);
    }
}

char s[maxn];
int n;
bool used[3];
void check(int u)
{
    if (u == n)
    {
        bool fail = false;
        forn (i, n)
            forn (j, n)
                if (((s[i] == 'a' && s[j] == 'c') || (s[i] == 'c' && s[j] == 'a')) == a[i][j])
                    fail = true;
        if (!fail)
        {
            cout << "Yes\n";
            s[n] = 0;
            cout << s << '\n';
            exit(0);
        }
        return;
    }
    if (u != comp[u])
    {
        s[u] = s[comp[u]];
        check(u + 1);
        return;
    }
    forn (i, 3)
    {
        if (used[i])
            continue;
        used[i] = true;
        s[u] = i + 'a';
        check(u + 1);
        used[i] = false;
    }
}

int solve()
{
    int m;
    cin >> n >> m;
    forn (i, m)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        a[u][v] = a[v][u] = true;
    }
    forn (i, n)
        a[i][i] = true;
    forn (i, n)
        forn (j, n)
        {
            eq[i][j] = true;
            forn (k, n)
                if (a[i][k] != a[j][k])
                    eq[i][j] = false, k = n;
        }
    forn (i, n)
    {
        for (int j = n - 1; j >= 0; --j)
            if (eq[i][j])
                comp[i] = j;
    }
    check(0);
    cout << "No\n";
    return 0;
}