#include<bits/stdc++.h>
using namespace std;

const int N=4e2+1e1+7;

int T;

int n,m;

int f[N][N],ne[N][26];

char s[N],t[N];

int solve(int x)
{
    int y=m-x;
    for(int i=0;i<=x;i++)
        for(int j=0;j<=y;j++)
            f[i][j]=n+1;
    f[0][0]=0;
    for(int i=0;i<=x;i++)
        for(int j=0;j<=y;j++)
        {
            f[i+1][j]=min(f[i+1][j],ne[f[i][j]][t[i+1]-'a']);
            f[i][j+1]=min(f[i][j+1],ne[f[i][j]][t[j+1+x]-'a']);
        }
    return f[x][y]<=n;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s+1,t+1);
        m=strlen(t+1);
        n=strlen(s+1);
        for(int i=0;i<26;i++)
            ne[n+1][i]=n+1;
        for(int i=n;i>=0;i--)
            for(int j=0;j<26;j++)
                ne[i][j]=(s[i+1]-'a'==j)?i+1:ne[i+1][j];
        int ans=0;
        for(int i=1;i<=m;i++)
            ans|=solve(i);
        puts(ans?"YES":"NO");
    }
}