#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n,k;

int a[N],b[N],c[N];

int f[N],g[N*N];

void pre(int n)
{
    fill(f+1,f+n+1,n);
    f[1]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(i+i/j<=n)
                f[i+i/j]=min(f[i+i/j],f[i]+1);
}

int main()
{
    pre(1000);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        fill(g,g+k+1,0);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cnt+=f[b[i]];
            cnt=min(cnt,k);
            for(int j=cnt;j>=f[b[i]];j--)
                g[j]=max(g[j],g[j-f[b[i]]]+c[i]);
        }
        printf("%d\n",*max_element(g,g+cnt+1));
    }
}