#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e3+1e2+7,P=998244353;

char s[2][N];

int f[N][N][2];

signed main()
{
    for(int i=0;i<2;i++)
        scanf("%s",s[i]+1);
    int n=strlen(s[0]+1);
    int m=strlen(s[1]+1);
    f[0][0][0]=f[0][0][1]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
        f[i][0][0]=(f[i-1][0][0])*(s[0][i]!=s[0][i-1])+1;
    for(int i=1;i<=m;i++)
        f[0][i][1]=(f[0][i-1][1])*(s[1][i]!=s[1][i-1])+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(k==0)
                    f[i][j][k]=((f[i-1][j][0])*(s[0][i-1]!=s[0][i])+(f[i-1][j][1])*(s[1][j]!=s[0][i]))%P;
                else
                    f[i][j][k]=((f[i][j-1][0])*(s[0][i]!=s[1][j])+(f[i][j-1][1])*(s[1][j-1]!=s[1][j]))%P;
                f[i][j][k]++;
                ans=(ans+f[i][j][k]%P-1+P)%P;
            }
        }
    for(int j=1;j<=n;j++)
    {
        int last=s[0][j];
        for(int i=j+1;i<=n;i++)
        {
            if(s[0][i]==last)
                break;
            last=s[0][i];
            ans=(ans-m+P)%P;
        }
    }
    for(int j=1;j<=m;j++)
    {
        int last=s[1][j];
        for(int i=j+1;i<=m;i++)
        {
            if(s[1][i]==last)
                break;
            last=s[1][i];
            ans=(ans-n+P)%P;
        }
    }
    printf("%lld\n",ans);
}