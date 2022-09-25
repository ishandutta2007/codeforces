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
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 300300;

int extra[maxn];
ll dif[maxn];

char s[maxn];
vector<int> g[maxn];

struct Node
{
    Node *to[26];

    Node()
    {
        memset(to, 0, sizeof(to));
    }
};

typedef pair<int, Node *> Tree;

void merge(Tree &a, Tree &b, Node *au, Node *bu)
{
    forn (i, 26)
    {
        if (bu->to[i] == 0)
            continue;
        if (au->to[i] == 0)
        {
            ++a.first;
            au->to[i] = new Node();
        }
        merge(a, b, au->to[i], bu->to[i]);
    }
    delete bu;
}

Tree dfs(int u, int prev = -1)
{
//    cerr << "DFS " << u << '\n';
    Tree cur = {1, new Node()};
    for (int v: g[u])
    {
        if (v == prev)
            continue;
        Tree x = dfs(v, u);
        if (x.first > cur.first)
            swap(cur, x);
        merge(cur, x, cur.second, x.second);
    }
    dif[u] = cur.first;
    Node *ch = new Node();
    ch->to[s[u] - 'a'] = cur.second;
    return Tree(cur.first + 1, ch);
}

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        scanf("%d", extra + i);
    scanf("%s", s);
    forn (i, n - 1)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
//    forn (i, n)
//        cerr << i + 1 << ' ' << dif[i] << '\n';
    pair<ll, int> best = {-INFL, 0};
    forn (i, n)
    {
        if (best.first < dif[i] + extra[i])
            best = {dif[i] + extra[i], 1};
        else if (best.first == dif[i] + extra[i])
            best.second++;
    }
    cout << best.first << '\n' << best.second << '\n';
    return 0;
}