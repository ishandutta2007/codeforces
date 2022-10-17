#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,L=1e6;

int n,m;

struct OP{
    int x,y,t;
};

vector<OP>v;

#define TYPE_INS 1000000007
#define TYPE_DEL 998244353

int c[N];

void add(int x,int v)
{
    while(x<=L)
        c[x]+=v,x+=x&-x;
}

int qry(int x)
{
    int ret=0;
    while(x)
        ret+=c[x],x-=x&-x;
    return ret;
}

bool cmp(OP a,OP b)
{
    return a.x<b.x||(a.x==b.x&&a.t>b.t);
}

int main()
{
    scanf("%d%d",&n,&m);
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        int y,l,r;
        scanf("%d%d%d",&y,&l,&r);
        v.push_back(OP{l,y,TYPE_INS});
        v.push_back(OP{r+1,y,TYPE_DEL});
        if(l==0&&r==L)
            ans++;
    }
    for(int i=1;i<=m;i++)
    {
        int x,l,r;
        scanf("%d%d%d",&x,&l,&r);
        v.push_back(OP{x,max(l,1),r});
        if(l==0&&r==L)
            ans++;
    }
    sort(v.begin(),v.end(),cmp);
    for(auto op:v)
    {
        if(op.t==TYPE_INS)
            add(op.y,1);
        else if(op.t==TYPE_DEL)
            add(op.y,-1);
        else
            ans+=qry(op.t)-qry(op.y-1);
    }
    printf("%lld\n",ans);
}