#include<bits/stdc++.h>
using namespace std;

int T,n,m;

const int N=1e3+1e2+7;

int ans[N][N];

int main()
{
    ans[0][0]=1;ans[0][1]=0;
    ans[1][0]=0;ans[1][1]=1;
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
            ans[i][j]=ans[i%2][j%2]^((i/2)&1)^((j/2)&1);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                printf("%d%c",ans[i][j]," \n"[j+1==m]);
    }
}