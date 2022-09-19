# include <cstdio>
# include <cstdlib>
const int MN = 111;
int x[MN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
        {
            int a;
            scanf("%d", &a);
            if (i != k)
                x[i] |= a;
        }
    for (int i = 0; i < n; ++i)
        printf("%d ", x[i]);
}