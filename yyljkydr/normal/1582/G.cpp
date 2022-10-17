#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int cnt;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define make_pair

struct T{
    int l,r,ls,rs;
    pii mn;
    int tag;
}t[N*2+1];

void add(int x,int v)
{
    t[x].mn.fs+=v;
    t[x].tag+=v;
}

void pushdown(int x)
{
    if(t[x].tag)
    {
        add(t[x].ls,t[x].tag);
        add(t[x].rs,t[x].tag);
        t[x].tag=0;
    }
}

void update(int x)
{
    t[x].mn=min(t[t[x].ls].mn,t[t[x].rs].mn);
}

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    t[x].tag=0;
    if(l==r)
    {
        t[x].mn={1e9,l};
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

void change(int x,int l,int r,int v)
{
    if(l<=t[x].l&&t[x].r<=r)
    {
        add(x,v);
        return;
    }
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(l<=mid)
        change(t[x].ls,l,r,v);
    if(r>mid)
        change(t[x].rs,l,r,v);
    update(x);
}

multiset<int>s;

vector<int>ins[N],del[N];

vector<pii>fac[N],pos[N];

int n,a[N];

char b[N];

void pre(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(fac[i].size())
            continue;
        for(int j=i;j<=x;j+=i)
        {
            fac[j].push_back({i,0});
            int k=j;
            while(k%i==0)
                fac[j].back().sd++,k/=i;
        }
    }
}

int sgn(char ch)
{
    return ch=='*'?1:-1;
}

vector<pii>seg;

int main()
{
    pre(1e6);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        for(auto p:fac[a[i]])
            pos[p.fs].push_back({i,p.sd});
    }
    scanf("%s",b+1);
    for(int i=1;i<=1000000;i++)
    {
        if(!pos[i].size())
            continue;
        // cnt=0;
        // build(1,pos[i].size());
        seg.clear();
        int tag=0;
        seg.push_back({tag,0});
        for(int j=0;j<pos[i].size();j++)
        {
            int x=a[pos[i][j].fs],y=sgn(b[pos[i][j].fs]);
            int tm=pos[i][j].sd;
            tag+=tm*y;
            // change(1,j+1,j+1,-1e9+tm*y);
            // if(j)
            //     change(1,1,j,tm*y);
            int p=-1,q=-1;
            while(!seg.empty()&&tag<seg.back().fs)
            {
                if(q==-1)
                    q=seg.back().sd+1;
                p=seg.back().sd+1;
                seg.pop_back();
            }
            if(p!=-1)
            {
                int R=pos[i][q-1].fs,L=p==1?1:pos[i][p-2].fs+1;
                ins[L].push_back(pos[i][j].fs-1);
                del[R+1].push_back(pos[i][j].fs-1);
            }
            seg.push_back({tag,j+1});
        }
    }
    long long ans=0;
    s.insert(n);
    for(int i=1;i<=n;i++)
    {
        for(auto x:ins[i])
            s.insert(x);
        for(auto x:del[i])
            s.erase(s.find(x));
        ans+=*s.begin()-i+1;
    }
    printf("%lld\n",ans);
}