# include <cstdio>
const int MN = 111;
int u[MN];
int find(int a)
{
    if(u[a] == a)
        return a;
    else
        return u[a] = find(u[a]);
}
void unite(int a, int b)
{
    u[find(a)] = find(b);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (m != n)
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        u[i] = i;
    int cou = 0;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (find(x) == find(y))
            cou++;
        else
            unite(x, y);
    }
    if (cou == 1)
        printf("FHTAGN!\n");
    else
        printf("NO\n");
}