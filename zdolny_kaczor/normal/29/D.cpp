# include <cstdio>
# include <vector>
# include <cstdlib>
# include <algorithm>
using namespace std;
const int MN = 311;
vector <int> graph[MN];
int low[MN], high[MN];
int val[MN];
void err()
{
    printf("-1\n");
    exit(0);
}
void dfs1(int x, int y = -1)
{
    if (val[x])
        low[x] = high[x] = val[x];
    else
    {
        low[x] = MN;
        for (auto v : graph[x])
            if (v != y)
            {
                dfs1(v, x);
                low[x] = min(low[x], low[v]);
                high[x] = max(high[x], high[v]);
            }
    }
}
vector <int> ans;
void dfs2(int x, int y = -1)
{
    ans.push_back(x);
    vector <pair <pair <int, int>, int> > under;
    for (auto v : graph[x])
        if (v != y)
            under.push_back(make_pair(make_pair(low[v], high[v]), v));
    sort(under.begin(), under.end());
    for (int i = 0; i < (int)under.size() - 1; ++i)
        if (under[i].first.second >= under[i + 1].first.first)
            err();
    for (auto v : under)
    {
        dfs2(v.second, x);
        ans.push_back(x);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int cou = 0;
    for (int i = 2; i <= n; ++i)
        if (graph[i].size() == 1)
            cou++;
    for (int i = 1; i <= cou; ++i)
    {
        int x;
        scanf("%d", &x);
        val[x] = i;
    }
    dfs1(1);
    dfs2(1);
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
}