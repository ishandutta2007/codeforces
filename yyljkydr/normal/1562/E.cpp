#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e2+7;

int T,n;

char s[N];

int f[N][N],g[N],lcp[N][N],tmp[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=n;i>=1;i--)
        {
            lcp[i+1][n+1]=0;
            for(int j=n;j>=1;j--)
                lcp[i][j]=(s[i]!=s[j]?0:lcp[i+1][j+1]+1);
        }
        for(int i=1;i<=n;i++)
            f[1][i]=i;
        g[1]=n;
        int ans=n;
        s[n+1]='a'-1;
        for(int i=2;i<=n;i++)
        {
            f[i][i]=1;
            for(int j=i;j<=n;j++)
                tmp[j]=0;
            for(int j=1;j<i;j++)
            {
                if(s[j]<s[i])
                    f[i][i]=max(f[i][i],g[j]+1);
                else if(s[j]==s[i])
                {
                    f[i][i]=max(f[i][i],f[j][j]);
                    int len=lcp[j][i];
                    if(s[i+len]>s[j+len])
                        tmp[i+len]=max(tmp[i+len],g[j]+1);
                }
            }
            for(int j=i+1;j<=n;j++)
                f[i][j]=max(f[i][j-1]+1,tmp[j]);
            g[i]=0;
            for(int j=i;j<=n;j++)
                g[i]=max(g[i],f[i][j]);
            ans=max(ans,g[i]);
        }
        printf("%d\n",ans);
    }
}