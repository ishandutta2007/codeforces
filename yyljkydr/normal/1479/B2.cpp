#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],nxt[N],to[N],last[N];

vector<int>v[2],g[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        g[a[i]].push_back(i);
    for(int i=0;i<=n;i++)
        g[i].push_back(n+1);
    v[0].push_back(0);
    v[1].push_back(0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=v[0].back(),y=v[1].back();
        if(x==a[i])
            v[0].push_back(a[i]);
        else if(y==a[i])
            v[1].push_back(a[i]);
        else
        {
            last[x]=*lower_bound(g[x].begin(),g[x].end(),i);
            last[y]=*lower_bound(g[y].begin(),g[y].end(),i);
            if(last[x]<last[y])
                v[1].push_back(a[i]),ans++;
            else
                v[0].push_back(a[i]),ans++;
        }
    }
    printf("%d\n",ans);
}