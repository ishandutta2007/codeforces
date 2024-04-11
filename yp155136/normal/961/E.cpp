#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int a[N];

struct Event
{
    int pos,val;
    Event(){}
    Event(int _pos,int _val) : pos(_pos),val(_val){}
};

struct Q
{
    int l,r,k;
    Q(){}
    Q(int _l,int _r,int _k) : l(_l) , r(_r) , k(_k){}
};

struct BIT
{
    static const int N = 200006;
    int a[N];
    int n;
    void init(int _n)
    {
        n = _n;
        memset(a,0,sizeof(a));
    }
    void update(int pos,int val)
    {
        for (int i=pos;n>=i;i+=i&(-i))
        {
            a[i] += val;
        }
    }
    int query(int pos)
    {
        int ret=0;
        for (int i=pos;i>=1;i-=i&(-i))
        {
            ret += a[i];
        }
        return ret;
    }
    int queryLR(int l,int r)
    {
        return query(r) - query(l-1);
    }
} bit;

long long ans=0;

void solve(vector<Event> e,vector<Q> q,int L,int R)
{
    if (L==R)
    {
        for (Event ee:e)
        {
            bit.update(ee.pos,1);
        }
        for (Q qq:q)
        {
            ans += bit.queryLR(qq.l,qq.r);
        }
        for (Event ee:e)
        {
            bit.update(ee.pos,-1);
        }
        return;
    }
    vector<Event> re,le;
    vector<Q> rq,lq;
    int mid = (L+R)>>1;
    for (Event ee:e)
    {
        if (ee.val <= mid) le.push_back(ee);
        else re.push_back(ee);
    }
    for (Q qq:q)
    {
        if (qq.k <= mid) lq.push_back(qq);
        else rq.push_back(qq);
    }
    solve(le,lq,L,mid);
    solve(re,rq,mid+1,R);
    for (Event ee:re)
    {
        bit.update(ee.pos,1);
    }
    for (Q qq:lq)
    {
        ans += bit.queryLR(qq.l,qq.r);
    }
    for (Event ee:re)
    {
        bit.update(ee.pos,-1);
    }
}

int main ()
{
    int n;
    scanf("%d",&n);
    vector<Event> e;
    vector<Q> q;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        a[i] = min(a[i],n);
        e.push_back(Event(i,a[i]));
        if (a[i] > i)
        {
            q.push_back(Q(i+1,a[i],i)); //>=k
        }
    }
    bit.init(n);
    solve(e,q,1,n);
    printf("%lld\n",ans);
}