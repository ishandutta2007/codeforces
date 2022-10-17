#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],vis[N];

int g=0;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),vis[i]=0;
        g=0;
        for(int i=1;i<=n;i++)
        {
            int p=-1;
            for(int j=1;j<=n;j++)
                if(!vis[j]&&(p==-1||__gcd(a[j],g)>__gcd(a[p],g)))
                    p=j;
            printf("%d ",a[p]);
            g=__gcd(g,a[p]);
            vis[p]=1;
        }
        puts("");
    }
}