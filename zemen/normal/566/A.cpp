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

const int maxn = 810000;

int to[maxn][26];
int nodes = 2;
const int root = 1;

char s[maxn];
vector<int> *p[maxn][2];
int pr[maxn];

vector<pair<int, int>> o;

void go(int &u, int c, int h)
{
    if (!to[u][c])
    {
        to[u][c] = nodes++;
        pr[nodes - 1] = u;
        p[nodes - 1][0] = new vector<int>();
        p[nodes - 1][1] = new vector<int>();
        o.emplace_back(h, nodes - 1);
    }
    u = to[u][c];
}

int ans[maxn];
ll res = 0;

void move_up(int u, int id)
{
    assert(u != root);
    int v = pr[u];
    if (p[u][id]->size() > p[v][id]->size())
        swap(p[v][id], p[u][id]);
    for (int x: *(p[u][id]))
        p[v][id]->push_back(x);
    p[u][id]->clear();
}

int solve()
{
    int n;
    cin >> n;
    o.emplace_back(0, root);
    p[root][0] = new vector<int>();
    p[root][1] = new vector<int>();
    forn (i, n)
    {
        scanf("%s", s);
        int u = root;
        for (int i = 0; s[i]; ++i)
            go(u, s[i] - 'a', i + 1);
        p[u][0]->push_back(i);
    }
    forn (i, n)
    {
        scanf("%s", s);
        int u = root;
        for (int i = 0; s[i]; ++i)
            go(u, s[i] - 'a', i + 1);
        p[u][1]->push_back(i);
    }
    sort(o.begin(), o.end());
    reverse(o.begin(), o.end());
    for (auto pa: o)
    {
        int u = pa.second;
        int h = pa.first;
        while (!p[u][0]->empty() && !p[u][1]->empty())
        {
            ans[p[u][0]->back()] = p[u][1]->back();
            res += h;
            p[u][0]->pop_back();
            p[u][1]->pop_back();
        }
        if (!p[u][0]->empty())
            move_up(u, 0);
        if (!p[u][1]->empty())
            move_up(u, 1);
    }
    cout << res << '\n';
    forn (i, n)
        cout << i + 1 << ' ' << ans[i] + 1 << '\n';
    return 0;
}