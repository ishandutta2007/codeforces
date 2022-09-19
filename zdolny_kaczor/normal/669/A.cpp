# include <cstdio>
# include <cassert>
int main()
{
    int n, m;
    scanf("%d", &n);
    rewind(stdin);
    scanf("%d", &m);
    assert(n == m);
    printf("%d\n", (n * 2 + 1) / 3);
}