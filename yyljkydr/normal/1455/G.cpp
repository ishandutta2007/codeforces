#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7,INF=1e15;

struct OP{
    int t,x,y;
};

OP v[N];

int n,s;

struct STA{
    int add;
    map<int,int>f;
    multiset<int>s;
    STA(){add=0,f.clear(),s.clear();}
    void upd(int x,int y)
    {
        if(f.find(x)!=f.end())
            s.erase(s.find(f[x]));
        f[x]=y;
        s.insert(f[x]);
    }
};

STA dp(int l,int r,int o)
{
    STA ret;
    if(o!=s)
        ret.upd(o,0);
    else
    {
        ret.upd(o,INF);
        return ret;
    }
    for(int i=l,j;i<=r;i=j+1)
    {
        if(v[i].t==1)
        {
            int mn=*ret.s.begin()+ret.add;
            ret.add+=v[i].y;
            ret.upd(v[i].x,mn-ret.add);
            j=i;
        }
        else if(v[i].t==2)
        {
            int val=ret.f.find(v[i].x)==ret.f.end()?INF:ret.f[v[i].x];
            ret.upd(v[i].x,val);
            STA nr=dp(i+1,v[i].y-1,v[i].x);
            j=v[i].y;
            if(nr.f.size()<ret.f.size())
            {
                int ord=ret.f[v[i].x]+ret.add;
                for(auto [x,y]:nr.f)
                {
                    int val=ret.f.find(x)==ret.f.end()?INF:ret.f[x];
                    ret.upd(x,val);
                    if(x!=v[i].x)
                        ret.upd(x,min(ret.f[x]+ret.add,y+nr.add+ord)-ret.add);
                    else
                        ret.upd(x,y+nr.add+ord-ret.add);
                }
            }
            else
            {
                nr.add+=ret.f[v[i].x]+ret.add;
                for(auto [x,y]:ret.f)
                {
                    int val=nr.f.find(x)==nr.f.end()?INF:nr.f[x];
                    nr.upd(x,val);
                    if(x!=v[i].x)
                        nr.upd(x,min(nr.f[x]+nr.add,ret.f[x]+ret.add)-nr.add);
                    else
                        nr.upd(x,nr.f[x]+nr.add-nr.add);
                }
                swap(ret,nr);
            }
        }
        ret.upd(s,INF);
    }
    return ret;
}

stack<int>st;

signed main()
{
    scanf("%lld%lld",&n,&s);
    for(int i=1;i<=n;i++)
    {
        char s[10];
        scanf("%s",s);
        if(s[0]=='s')
        {
            scanf("%lld%lld",&v[i].x,&v[i].y);
            v[i].t=1;
        }
        if(s[0]=='i')
        {
            scanf("%lld",&v[i].x);
            v[i].t=2;
            st.push(i);
        }
        if(s[0]=='e')
        {
            v[st.top()].y=i;
            st.pop();
        }
    }
    STA ans=dp(1,n,0);
    printf("%lld\n",ans.add+*ans.s.begin());
}