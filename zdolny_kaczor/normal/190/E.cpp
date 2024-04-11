# include <cstdio>
# include <vector>
using namespace std;
const int MN = 5e5 + 44;
vector <int> graph[MN];
int u[MN];
int list[MN];
int pos[MN];
int size_[MN];
int cou;
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        u[i] = list[i] = pos[i] = i;
        size_[i] = 1;
    }
    cou = n;
}
int find(int a)
{
    if (u[a] == a)
        return a;
    else
        return u[a] = find(u[a]);
}
int size(int a)
{
    return size_[find(a)];
}
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        size_[b] += size_[a];
        u[a] = b;
        list[pos[a]] = list[cou];
        pos[list[cou]] = pos[a];
        cou--;
    }
}
vector <int> getcomponents()
{
    vector <int> ans;
    for (int i = 1; i <= cou; ++i)
        ans.push_back(list[i]);
    return ans;
}
int to[MN];
vector <int> ans[MN];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        vector <int> components = getcomponents();
        for (auto v : components)
            to[v] = size(v);
        for (auto x : graph[i])
            to[find(x)] --;
        for (auto v : components)
            if (to[v] != 0)
                unite(v, i);
    }
    for (int i = 1; i <= n; ++i)
        ans[find(i)].push_back(i);
    printf("%d\n", cou);
    for (int i = 1; i <= n; ++i)
        if (ans[i].size() > 0)
        {
            printf("%d", (int)ans[i].size());
            for (auto x : ans[i])
                printf(" %d", x);
            printf("\n");
        }
}