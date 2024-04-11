#include<bits/stdc++.h>
using namespace std;

const int N=501;

int n,m,a[N][N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    int g=1;
    for(int i=2;i<=16;i++)
        g=g*i/__gcd(g,i);
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++,putchar(' '))
            printf("%d",(i+j)&1?g:g+(int)pow(a[i][j],4));
}