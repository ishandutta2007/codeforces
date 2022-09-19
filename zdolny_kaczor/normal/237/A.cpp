# include <cstdio>
int main()
{
    int res = 0;
    int last = -1;
    int curr = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int x = a * 7537 + b;
        if (x == last)
            curr ++;
        else
        {
            last = x;
            if (curr > res)
                res = curr;
            curr = 1;
        }
    }
    if (res < curr)
        res = curr;
    printf("%d\n", res);
}