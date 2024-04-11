#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=4e5+1e3+7;

int n,m,Q;

int a[N],b[N];

int s[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii v[N],val[N],q[N];

int Ans[N];

int fa[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

map<int,int>d;

int r[N];

bool cmp(int x,int y)
{
    return v[x+1].fs-v[x].fs<v[y+1].fs-v[y].fs;
}

int calc(int x,int y)
{
    return s[x]-s[x-y];
}

signed main()
{
    scanf("%lld%lld%lld",&n,&m,&Q);
    int ans=0;
    for(int i=1;i<=n+m;i++)
    {
        scanf("%lld",&v[i].fs);
        v[i].sd=(i<=n);
    }
    sort(v+1,v+n+m+1);
    for(int i=1;i<=n+m;i++)
    {
        val[i]=v[i];
        val[i].fs*=val[i].sd;
        ans+=val[i].fs;
        s[i]=s[i-1]+v[i].fs;
        fa[i]=i;
    }
    for(int i=1;i<n+m;i++)
        r[i]=i;
    sort(r+1,r+n+m,cmp);
    for(int i=1;i<n+m;i++)
    {
        int x=r[i],y=x+1;
        int fx=find(x),fy=find(y);
        fa[fx]=fy;
        int nk=val[fx].sd+val[fy].sd;
        int ns=calc(fy,nk);
        d[v[y].fs-v[x].fs]+=ns-val[fx].fs-val[fy].fs;
        val[fy]={ns,nk};
    }
    for(int i=1;i<=Q;i++)
    {
        int k;
        scanf("%lld",&k);
        q[i]={k,i};
    }
    sort(q+1,q+Q+1);
    auto it=d.begin();
    for(int i=1;i<=Q;i++)
    {
        while(it!=d.end()&&it->fs<=q[i].fs)
        {
            ans+=it->sd;
            it++;
        }
        Ans[q[i].sd]=ans;
    }
    for(int i=1;i<=Q;i++)
        printf("%lld\n",Ans[i]);
}