# include <cstdio>
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n", m*(m-1)/2);
    for (int i=m-1; i>=0; --i)
        for (int x=0; x<i; ++x)
            printf("%d %d\n", x+1+k, x+2-k);
}