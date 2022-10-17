#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=4e5+1e3+7,P=998244353;

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

int T,n,m;

int fac[N],inv[N];

void pre(int n)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}

int C(int n,int m)
{
    if(n<0||m<0||n<m)
        return 0;
    return fac[n]*inv[m]%P*inv[n-m]%P;
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii p[N];

set<int>s;

int c[N];

void add(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=x&-x;
    }
}

int qry(int x)
{
    int ret=0;
    while(x)
    {
        ret+=c[x];
        x-=x&-x;
    }
    return ret;
}

vector<int>del;

signed main()
{
    pre(4e5);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%lld%lld",&p[i].fs,&p[i].sd);
        s.clear();
        int cnt=0;
        del.clear();
        for(int i=m;i>=1;i--)
        {
            int l=0,r=n;
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(qry(mid)+p[i].sd<=mid)
                    r=mid;
                else
                    l=mid;
            }
            add(r,1);
            del.push_back(r);
            if(!s.count(r+1))
                cnt++;
            s.insert(r);
        }
        for(auto x:del)
            add(x,-1);
        printf("%lld\n",C(2*n-1-cnt,n));
    }
}