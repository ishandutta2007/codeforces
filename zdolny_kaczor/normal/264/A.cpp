# include <cstdio>
# include <cstring>
const int MN = 1e6 + 44;
char in[MN];
int ans[MN];
int main()
{
    int n;
    scanf("%s", in + 1);
    n = strlen(in + 1);
    int pos = 0;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 'r')
            ans[pos++] = i;
    for (int i = n; i; --i)
        if (in [i] == 'l')
            ans[pos++] = i;
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
}