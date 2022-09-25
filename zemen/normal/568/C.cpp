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

const int maxn = 409;

char type[maxn];

int n, m;

vector<int> g[maxn * 2];
vector<int> gr[maxn * 2];
int orig[maxn * 2][2];
char s[maxn];
int state[maxn];

bool used[maxn * 2];

vector<int> ord;

void dfs1(int u)
{
    used[u] = true;
    for (int v: g[u])
        if (!used[v])
            dfs1(v);
    ord.push_back(u);
}

int col[maxn * 2];
int COL;

void dfs2(int u)
{
    col[u] = COL;
    used[u] = true;
    for (int v: gr[u])
        if (!used[v])
            dfs2(v);
}

bool check()
{
//    forn (i, n)
//        cerr << state[i] << ' ';
//    cerr << '\n';
    int N = 2 * n + 2;
    forn (i, N)
        g[i].resize(orig[i][0]), gr[i].resize(orig[i][1]);

    g[n * 2].push_back(n * 2 + 1);
    gr[n * 2 + 1].push_back(n * 2);
    forn (i, n)
    {
        if (state[i] == -1)
            continue;
        g[n * 2 + 1].push_back(i * 2 + state[i]);
        g[i * 2 + !state[i]].push_back(n * 2);
        gr[i * 2 + state[i]].push_back(n * 2 + 1);
        gr[n * 2].push_back(i * 2 + !state[i]);
//        cerr << "true " << i * 2 + state[i] << '\n';
    }
    fill(used, used + N, false);
    ord.clear();
    forn (i, N)
        if (!used[i])
            dfs1(i);
    assert(sz(ord) == N);
    reverse(ord.begin(), ord.end());
    fill(used, used + N, false);
    for (int i: ord)
    {
        ++COL;
        if (!used[i])
            dfs2(i);
    }
    forn (i, n)
        if (col[i * 2] == col[i * 2 + 1])
            return false;
    return true;
}

int _state[maxn];

int solve()
{
    scanf("%s", type);
    int alpha = strlen(type);
    cin >> n >> m;
    forn (i, m)
    {
        int u, v;
        char tu, tv;
        cin >> u >> tu >> v >> tv;
        --u, --v;
        tu = (tu == 'C');
        tv = (tv == 'C');
        g[u * 2 + tu].push_back(v * 2 + tv);
        g[v * 2 + !tv].push_back(u * 2 + !tu);
        gr[v * 2 + tv].push_back(u * 2 + tu);
        gr[u * 2 + !tu].push_back(v * 2 + !tv);
    }
    forn (i, n * 2)
        orig[i][0] = sz(g[i]), orig[i][1] = sz(gr[i]);
    scanf("%s", s);

    forn (i, n)
    {
        state[i] = (type[int(s[i] - 'a')] == 'C');
        _state[i] = state[i];
    }

    if (check())
    {
        cout << s << '\n';
        return 0;
    }
    bool have[2] = {false, false};
    forn (i, alpha)
        have[type[i] == 'C'] = true;
    if (!have[0] || !have[1])
    {
        cout << -1 << '\n';
        return 0;
    }


    int start;
    for (start = n - 1; start >= 0; --start)
    {
        bool checked[2] = {false, false};
        bool ok = false;
//        forn (i, n)
//            state[i] = _state[i];
        for (int j = s[start] - 'a' + 1; j < alpha; ++j)
        {
            int t = (type[j] == 'C');
            if (checked[t])
                continue;
            state[start] = t;
            if (check())
            {
                s[start] = 'a' + j;
                ok = true;
                break;
            }
            else
                checked[t] = true;

//            forab (k, start, n)
//                state[k] = -1;
        }
        if (ok)
            break;
        state[start] = -1;
    }

    if (start == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int pos = start + 1; pos < n; ++pos)
    {
        bool checked[2] = {false, false};
        for (int j = 0; j < alpha; ++j)
        {
            int t = (type[j] == 'C');
            if (checked[t])
                continue;
            state[pos] = t;
            if (check())
            {
                s[pos] = 'a' + j;
                break;
            }
            else
                checked[t] = true;
        }
    }
    cout << s << '\n';
    return 0;
}