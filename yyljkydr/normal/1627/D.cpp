#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,a[N],vis[N];

int ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),vis[a[i]]=1;
    int m=1e6;
    for(int i=1;i<=m;i++)
    {
        int g=0;
        if(!vis[i])
        {
            for(int j=i;j<=m;j+=i)
            {
                if(!vis[j])
                    continue;
                g=__gcd(g,j);
                if(g==i)
                {
                    vis[i]=1;
                    break;
                }
            }
        }
        ans+=vis[i];
    }
    printf("%d\n",ans-n);
}