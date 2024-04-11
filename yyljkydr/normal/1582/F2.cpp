#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,M=1e4;

int n,a[N];

int f[N],g[N];

vector<int>p[M];

vector<int>ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),p[a[i]].push_back(i);
    fill(f+1,f+8191+1,n+1);
    for(int i=1;i<=5000;i++)
    {
        if(!p[i].size())
            continue;
        for(int j=0;j<=min(i*2,8191);j++)
            g[j]=f[j];
        for(int j=0;j<=min(i*2,8192);j++)
        {
            if(f[j]==n+1)
                continue;
            auto it=lower_bound(p[i].begin(),p[i].end(),f[j]);
            if(it==p[i].end())
                continue;
            g[i^j]=min(g[i^j],*it);
        }
        for(int j=0;j<=min(i*2,8191);j++)
            f[j]=g[j];
    }
    for(int i=0;i<8192;i++)
        if(f[i]<=n)
            ans.push_back(i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
}