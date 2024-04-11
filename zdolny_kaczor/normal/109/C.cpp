# include <cstdio>
const int MN = 1e5 + 44;
int u[MN];
int r[MN];
int size[MN];
int find(int x)
{
    if (u[x] == x)
        return x;
    else
        return find(u[x]);
}
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (r[a] > r[b])
        u[b] = a;
    else if (r[a] == r[b])
    {
        r[a]++;
        u[b] = a;
    }
    else
        u[a] = b;
    if (u[b] == a)
        size[a] += size[b];
    else
        size[b] += size[a];
}
bool islucky(int a)
{
    while (a)
    {
        if (a % 10 != 4 && a % 10 != 7)
            return false;
        a /= 10;
    }
    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        u[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (!islucky(c))
            unite(a, b);
    }
    long long res = n * (n - 1ll) * (n - 2);
    for (int i = 1; i <= n; ++i)
        if (find(i) == i)
            res -= size[i] * (size[i] - 1ll) * (n - 2) * 2 - size[i] * (size[i] - 1ll) * (size[i] - 2);
    
    printf("%I64d\n", res);
}