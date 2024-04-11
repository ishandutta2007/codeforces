# include <cstdio>
const int MN = 1e6 + 44;
char in[MN];
int main()
{
    int ans = 0, dep = 0;
    scanf("%s", in);
    for (int i = 0; in[i]; ++i)
        if (in[i] == '(')
        {
            ans++;
            dep++;
        }
        else
        {
            if (dep)
            {
                ans++;
                dep--;
            }
        }
    printf("%d\n", ans - dep);
}