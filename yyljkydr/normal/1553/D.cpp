#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

char s[N],t[N];

int n,m;

int nx[N][2][26];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        scanf("%s",t+1);
        m=strlen(t+1);
        for(int j=0;j<2;j++)
            for(int k=0;k<26;k++)
                nx[n][j][k]=nx[n+1][j][k]=n+1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
                for(int k=0;k<26;k++)
                {
                    if(s[i+1]-'a'==k&&j==1)
                        nx[i][j][k]=i+1;
                    else
                        nx[i][j][k]=nx[i+1][j^1][k];
                }
        }
        int ok=0;
        int x=nx[0][0][t[1]-'a'];
        if(x<=n)
        {
            for(int i=2;i<=m;i++)
                x=nx[x][1][t[i]-'a'];
            if(x<=n&&(n-x)%2==0)
                ok=1;
        }
        x=nx[0][1][t[1]-'a'];
        if(x<=n)
        {
            for(int i=2;i<=m;i++)
                x=nx[x][1][t[i]-'a'];
            if(x<=n&&(n-x)%2==0)
                ok=1;
        }
        puts(ok?"YES":"NO");
    }
}
/*
oivgrzwppny
zhfyiuu
*/