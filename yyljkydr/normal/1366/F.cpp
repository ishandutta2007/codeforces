#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e3+1e2+7,P=1e9+7;

int n,m,q;

typedef pair<int,int> pii;

vector<pii>g[N];

int d[N][N];

struct E{
    int u,v,w;
};

vector<E>e;

int ans[N];

struct L{
    int k,b;
};

L l[N];

long double meet(L a,L b)
{
    long double Y=b.b-a.b;
    return Y/(a.k-b.k);
}

long long eval(L l,int a,int b)
{
    assert((a*l.k+l.b+b*l.k+l.b)>=0);
    return (a*l.k+l.b+b*l.k+l.b)%P*(b-a+1)%P*(P+1)/2%P;
}

signed main()
{
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        e.push_back({u,v,w});
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            d[j][i]=-1e18;  
    d[0][1]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(auto [v,w]:g[j])
                d[i][j]=max(d[i][j],d[i-1][v]+w);
            ans[i]=max(ans[i],d[i][j]);
        }
    }
    sort(e.begin(),e.end(),[&](const E &a,const E &b){return a.w<b.w;});
    map<int,int>B;
    for(auto [u,v,w]:e)
    {
        int mx=-1e18;
        for(int j=1;j<=m;j++)
        {
            if(d[j][u]>0)
                mx=max(mx,d[j][u]-j*w);
            if(d[j][v]>0)
                mx=max(mx,d[j][v]-j*w);
        }
        if(!B.count(w))
            B[w]=mx;
        else
            B[w]=max(B[w],mx);
    }
    //m+1,q
    int t=0;
    for(auto [k,b]:B)
    {
        while(t>1&&meet({k,b},l[t])<meet(l[t],l[t-1]))
            t--;
        l[++t]={k,b};
    }
    long long fans=0;
    for(int i=1;i<=m;i++)
        fans=(fans+ans[i])%P;
    int L=m+1;
    for(int i=1;i<=t;i++)
    {
        if(L>q)
            break;
        if(i==t)
            fans=(fans+eval(l[i],L,q))%P;
        else
        {
            if(meet(l[i],l[i+1])<=L)
                continue;
            int c=meet(l[i],l[i+1]);
            while(eval(l[i],c+1,c+1)>eval(l[i+1],c+1,c+1))
                c++;
            while(eval(l[i],c,c)<eval(l[i+1],c,c))
                c--;
            if(c>q)
                c=q;
            fans=(fans+eval(l[i],L,c))%P;
            L=c+1;
        }
    }
    printf("%lld\n",fans);
}
/*
2+2+2+2+2
  3 3 3 3 3 3 3 3 3 3
*/