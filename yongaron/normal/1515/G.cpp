#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int L = 2e5 + 5;

int n, m;

vector<int> graf[L];
vector<int> delky[L];
vector<int> st;

bool onstack[L];
int lowlink[L];
int inde = 0;
int comp[L];
int c = 0;

vector<int> compgraf[L];
vector<int> incomp[L];

bool was[L];
ll dist[L];

ll comp_gcd[L];

void dfs2(int v)
{
    was[v] = true;
    for (int i = 0; i < graf[v].size(); i++)
    {
        if (comp[v] == comp[graf[v][i]] && !was[graf[v][i]])
        {
            dist[graf[v][i]] = dist[v] + delky[v][i];
            dfs2(graf[v][i]);
        }
    }
}

void dfs(int v)
{
    int ind = inde;
    lowlink[v] = inde++;
    st.push_back(v);
    onstack[v] = true;
    for (int i = 0; i < graf[v].size(); i++)
    {
        if (lowlink[graf[v][i]] == n)
            dfs(graf[v][i]);
        if (onstack[graf[v][i]])
            lowlink[v] = min(lowlink[v], lowlink[graf[v][i]]);
    }
    if (lowlink[v] == ind)
    {
        while (onstack[v])
        {
            comp[st.back()] = c;
            onstack[st.back()] = false;
            incomp[c].push_back(st.back());
            st.pop_back();
        }
        c++;
    }
}

ll gcd(ll a, ll b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (a && b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int a, b, l;
    for (int i = 1; i <= n; i++)
        lowlink[i] = n;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> l;
        graf[a].push_back(b);
        delky[a].push_back(l);
    }
    for (int i = 1; i <= n; i++)
        if (lowlink[i] == n)
            dfs(i);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < graf[i].size(); j++)
            compgraf[comp[i]].push_back(comp[graf[i][j]]);

    for (int i = 1; i <= n; i++)
        if (!was[i])
            dfs2(i);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < graf[i].size(); j++)
        {
            if (comp[i] == comp[graf[i][j]])
            {
                comp_gcd[comp[i]] = gcd(comp_gcd[comp[i]], dist[graf[i][j]] - dist[i] - delky[i][j]);
            }
        }
    }
    int q;

    cin >> q;
    ll v, s, t;
    for (int i = 0; i < q; i++)
    {
        cin >> v >> s >> t;
        if (((t - s) % gcd(t, comp_gcd[comp[v]])) == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}