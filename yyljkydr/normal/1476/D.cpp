#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T,n,f[N],g[N];

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        f[0]=1;
        f[1]=2;
        for(int i=2;i<=n;i++)
            if(s[i]!=s[i-1])
                f[i]=f[i-1]+1;
            else
                f[i]=2;
        g[n]=1;
        g[n-1]=2;
        for(int i=n-2;i>=0;i--)
            if(s[i+1]!=s[i+2])
                g[i]=g[i+1]+1;
            else
                g[i]=2;
        for(int i=1;i<=n;i++)
            if(s[i]=='L')
                g[i-1]=1;
            else
                f[i]=1;
        for(int i=0;i<=n;i++)
        {
            if(i==0)
                printf("%d ",g[i]);
            if(i==n)
                printf("%d ",f[i]);
            if(i>=1&&i<=n-1)
                printf("%d ",f[i]+g[i]-1);
        }
        puts("");
    }
}