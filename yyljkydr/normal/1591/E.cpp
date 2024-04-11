#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,M=1<<20;

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int T,n,a[N],Q;

unordered_set<int>s[N];

vector<int>g[N];

struct Qr{
    int l,k,id;
};

vector<Qr>q[N];

int c[M+11];

void add(int x,int v)
{
    x++;
    while(x<=M)
    {
        c[x]+=v;
        x+=x&-x;
    }
}

int qry(int x)
{
    x++;
    int ret=0;
    while(x)
    {
        ret+=c[x];
        x-=x&-x;
    }
    return ret;
}

int qpos(int k)
{
    int ret=0;
    for(int i=19;i>=0;i--)
        if(c[ret+(1<<i)]<k)
            ret+=(1<<i),k-=c[ret];
    return ret;
}

int cnt[N];

void ins(int x,int v)
{
    s[cnt[x]].erase(x);
    add(cnt[x],-1);
    cnt[x]+=v;
    s[cnt[x]].insert(x);
    add(cnt[x],1);
}

int ans[N];

void dfs(int x)
{
    ins(a[x],1);
    for(auto [l,k,id]:q[x])
    {
        int num=qry(l-1);
        if(num+k>n)
            ans[id]=-1;
        else
        {
            int ps=qpos(num+k);
            ans[id]=*s[ps].begin();
        }
    }
    for(auto v:g[x])
        dfs(v);
    ins(a[x],-1);
}

int main()
{
    T=read();
    while(T--)
    {
        n=read(),Q=read();
        for(int i=1;i<=n;i++)
            a[i]=read(),q[i].clear(),g[i].clear();
        for(int i=2;i<=n;i++)
        {
            int p;
            p=read();
            g[p].push_back(i);
        }
        for(int i=1;i<=Q;i++)
        {
            int v,l,k;
            v=read(),l=read(),k=read();
            q[v].push_back({l,k,i});
        }
        for(int i=1;i<=n;i++)
            add(0,1),s[0].insert(i);
        dfs(1);
        for(int i=1;i<=n;i++)
            add(0,-1),s[0].erase(i);
        for(int i=1;i<=Q;i++)
            printf("%d%c",ans[i]," \n"[i==Q]);
    }
}