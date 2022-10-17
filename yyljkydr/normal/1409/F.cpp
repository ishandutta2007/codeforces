#include<bits/stdc++.h>
using namespace std;

const int N=221;

int n,k;

char s[N],c[2];

int f[N][N][N];

void cmax(int &a,int b)
{
    a=max(a,b);
}

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    scanf("%s",c);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int t=0;t<=n;t++)
                f[i][j][t]=-n*n;
    f[0][0][0]=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int t=0;t<=i;t++)
            {
                cmax(f[i+1][j][t+(s[i+1]==c[0])],f[i][j][t]+(s[i+1]==c[1])*t);
                cmax(f[i+1][j+1][t+1],f[i][j][t]+t*(c[0]==c[1]));
                cmax(f[i+1][j+1][t+(c[0]==c[1])],f[i][j][t]+t);
            }
    int ans=0;
    for(int i=0;i<=k;i++)
        for(int t=0;t<=n;t++)
            cmax(ans,f[n][i][t]);
    printf("%d\n",ans);
}