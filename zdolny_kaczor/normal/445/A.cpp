# include <cstdio>
char get()
{
    int c;
    while ((c=getchar())=='\n')
        ;
    return c;
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i=0; i<m; ++i)
    {
        for (int k=0; k<n; ++k)
            if (get()=='-')
                putchar('-');
            else
                putchar((i+k)%2?'W':'B');
        putchar(10);
    }
}