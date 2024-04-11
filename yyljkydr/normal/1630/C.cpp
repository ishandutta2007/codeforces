#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N];

int f[N],g[N],fir[N],las[N],vis[N];

vector<int>v;

int c[N];

void add(int x,int v)
{
    while(x)
    {
        c[x]=max(c[x],v);
        x-=x&-x;
    }
}

int qry(int x)
{
    int ret=-0x7fffffff;
    while(x<=n)
    {
        ret=max(ret,c[x]);
        x+=x&-x;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        g[i]=-0x7fffffff;
        c[i]=-0x7fffffff;
        if(!vis[a[i]])
            fir[a[i]]=i,vis[a[i]]=1;
        las[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        if(i==fir[a[i]]||i==las[a[i]])
            v.push_back(a[i]);
    fill(vis+1,vis+n+1,0);
    for(int i=1;i<=v.size();i++)
    {
        if(!vis[v[i-1]])
        {
            vis[v[i-1]]=i;
            f[i]=f[i-1];
            g[v[i-1]]=max(g[v[i-1]],f[i-1]-i+1);
        }
        else
        {
            f[i]=max(f[i-1],g[v[i-1]]+i-2);
            g[v[i-1]]=max(g[v[i-1]],f[i-1]-i+1);
            f[i]=max(f[i],qry(vis[v[i-1]]+1)+i-1);
            add(i,f[i]-i);
        }
    }
    printf("%d\n",n-(int)v.size()+*max_element(f+1,f+v.size()+1));
}