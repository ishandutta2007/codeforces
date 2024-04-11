#include<stdio.h>

const int c[15] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 33};
int id[15], a[1005], b[1005], cnt, t, n;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 1; i <= 11; ++i)
            id[i] = 0;
        cnt = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= 11; ++j)
            {
                if(a[i]%c[j] == 0)
                {
                    if(id[j] == 0) id[j] = ++cnt;
                    b[i] = id[j];
                    break;
                }
            }
        }
        printf("%d\n", cnt);
        for(int i = 1; i <= n; ++i) printf("%d ", b[i]);
        puts("");
    }
    return 0;
}