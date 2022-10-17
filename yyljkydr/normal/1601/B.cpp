#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n,a[N],b[N],d[N],pre[N],sl[N];

int fa[N];

vector<int>g[N];

int find(int x)
{
    if(x==-1)
        return -1;
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

queue<int>q;

void inq(int x,int v)
{
    d[x]=v;
    q.push(x);
    for(auto p:g[x])
        fa[p]=find(p-1);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]),g[i+b[i]].push_back(i);
    g[0].push_back(0);
    for(int i=0;i<=n;i++)
        fa[i]=i;
    fill(d,d+n+1,-1);
    inq(n,0);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=find(x);i>=x-a[x];i=find(i-1))
            inq(i+b[i],d[x]+1),pre[i+b[i]]=x,sl[i+b[i]]=i;
    }
    if(d[0]==-1)
        puts("-1");
    else
    {
        printf("%d\n",d[0]);
        int x=0;
        vector<int>ans;
        while(x!=n)
            ans.push_back(x),x=pre[x];
        reverse(ans.begin(),ans.end());
        for(auto x:ans)
            printf("%d ",sl[x]);
        puts("");
    }
}