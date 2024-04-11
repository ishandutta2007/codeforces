# include <cstdio>
const int MN = 5e3 + 44;
bool found[MN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        found[x] = true;
    }
    int result = 0;
    for (int i = 1; i <= n; ++i)
        if (!found[i])
            result ++;
    printf("%d\n", result);
}