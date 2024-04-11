#include<bits/stdc++.h>
using namespace std;

int T,l,r;

int A[31],B[31];

long long f[31][2][2];

bool vis[31][2][2];

long long dp(int x,int a,int b)
{
    if(x==-1)
        return 1;
    if(vis[x][a][b])
        return f[x][a][b];
    vis[x][a][b]=1;
    long long &ret=f[x][a][b];
    ret=0;
    for(int i=0;i<=(a?A[x]:1);i++)
        for(int j=0;j<=(b?B[x]:1);j++)
        {
            if(i&&j)
                continue;
            int na=a&&i==A[x],nb=b&&j==B[x];
            ret+=dp(x-1,na,nb);
        }
    return ret;
}

long long calc(int n,int m)
{
    for(int i=0;i<=30;i++)
        A[i]=n>>i&1,B[i]=m>>i&1;
    memset(vis,0,sizeof(vis));
    return dp(30,1,1);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        long long ans=calc(r,r);
        if(l)
        {
            ans=(ans-calc(l-1,r)-calc(r,l-1)+calc(l-1,l-1));
        }
        printf("%lld\n",ans);
    }
}