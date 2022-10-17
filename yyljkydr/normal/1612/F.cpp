#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e6+1e3+7;

int n,m,Q;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

map<pii,int>d;

set<pii>w;

queue<pii>q;

struct BIT{
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
        int ret=0;
        while(x<N)
        {
            ret=max(ret,c[x]);
            x+=x&-x;
        }
        return ret;
    }
}X,Y;

int mxs;

bool chk(int x,int y)
{
    if(X.qry(x)>y||Y.qry(y)>x)
        return 0;
    // if(x+y<min(n,m)&&mxs>x+y)
    //     return 0;
    return 1;
}

signed main()
{
    scanf("%lld%lld",&n,&m);
    scanf("%lld",&Q);
    while(Q--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        w.insert({x,y});
    }
    d[{1,1}]=0;
    q.push({1,1});
    X.add(1,1),Y.add(1,1);
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        if(x==n&&y==m)
            break;
        int mx=x+y+w.count({x,y});
        mx=min(mx,n);
        if(!d.count({mx,y})&&chk(mx,y))
        {
            q.push({mx,y}),d[{mx,y}]=d[{x,y}]+1;
            X.add(mx,y);
            Y.add(y,mx);
            mxs=max(mxs,mx+y);
        }
        mx=x+y+w.count({x,y});
        mx=min(mx,m);
        if(!d.count({x,mx})&&chk(x,mx))
        {
            q.push({x,mx}),d[{x,mx}]=d[{x,y}]+1;
            X.add(x,mx);
            Y.add(mx,x);
            mxs=max(mxs,mx+y);
        }
    }
    printf("%lld\n",d[{n,m}]);
}