#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e3+7;

int n;
int f[Maxn][Maxn];

int main()
{
    scanf("%d", &n);
    int num1 = 0;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &f[i][i]);
        num1 += (f[i][i] == 1);
    }
    if(num1)
    {
        printf("%d\n", n-num1);
        return 0;
    }
    for(int len = 2; len <= n; ++len)
    {
        for(int l = 1, r; (r=l+len-1) <= n; ++l)
        {
            f[l][r] = __gcd(f[l][r-1], f[r][r]);
            if(f[l][r] == 1)
            {
                printf("%d\n", (n-len)+2*(len-1));
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}