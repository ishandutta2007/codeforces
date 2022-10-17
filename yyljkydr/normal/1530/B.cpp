#include<bits/stdc++.h>
using namespace std;

const int N=101;

int T,n,m;

int ans[N][N];

bool chk(int x,int y)
{
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if(ans[x+i][y+j])
                return 0;
    return 1;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
                ans[i][j]=0;
        for(int i=1;i<=m;i++)
            if(chk(1,i))
                ans[1][i]=1;
        for(int i=1;i<=n;i++)
            if(chk(i,m))
                ans[i][m]=1;
        for(int i=m;i>=1;i--)
            if(chk(n,i))
                ans[n][i]=1;
        for(int i=n;i>=1;i--)
            if(chk(i,1))
                ans[i][1]=1;
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%d",ans[i][j]);
    }
}