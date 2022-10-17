#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,f[N],g[N],a[N];

vector<int>v[N];

int main()
{
    for(int i=1;i<=200000;i++)
    {
        for(int j=1;j*j<=i;j++)
            if(i%j==0)
            {
                v[i].push_back(j);
                if(j*j!=i)
                    v[i].push_back(i/j);
            }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=200000;i++)
            g[i]=1e9;
        g[1]=0;
        for(int i=1;i<=n;i++)
        {
            f[i]=1e9;
            for(auto x:v[a[i]])
                f[i]=min(f[i],g[x]+i-1);
            g[a[i]]=min(g[a[i]],f[i]-i);
        }
        int ans=1e9;
        for(int i=1;i<=n;i++)
            ans=min(ans,n-i+f[i]);
        printf("%d\n",ans);
    }
}