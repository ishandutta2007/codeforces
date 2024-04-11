#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define rep(i,begin,end) for (__typeof(begin) i=(begin),_end=(end),_step=1-2*((begin)>(end));i!=_end;i+=_step)

// OUTPUT
template<class a, class b>
ostream& operator << (ostream& os, const pair<a,b>& p)  {
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}
template<class T>
ostream& operator << (ostream& os, const vector<T>& v)  {
    os<<"[";
    if (!v.size()) 
        os<<"]"; 
    else
        for (int i=0;i<v.size();++i)
            os<<v[i]<<",]"[i==v.size()-1];
    return os;
}
template<class T>
ostream& operator << (ostream& os, const set<T>& s)  {
    os<<"{";
    if (!s.size()) 
        os<<"}"; 
    else
        for (auto x:s)
            os<<x<<",}"[x==*s.rbegin()];
    return os;
}

void printr(ostream& os){os<<'\n';}
template<class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args){
    os<<t; if (sizeof...(args)) os<<" ";
    printr(os,args...);
}
#define print(args...) printr(cout,##args)

// INPUT
template<class T>
void read(T& x) {cin>>x;}
template<class T, class... Args>
void read(T& t, Args&... args){
    read(t),read(args...);
}
template<class T>
void readarray(T* A,int n)  {
    rep(i,0,n) read(A[i]);
}


// DEBUG
void dbgr(ostream& os) { os<<endl; }
template<class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
    os<<t; if (sizeof...(args)) os<<", ";
    dbgr(os,args...); 
}
#define dbg(args...) cout<<#args<<" = ", dbgr(cout,##args) //cout can be changed


#define maxn 500050
#define modu 998244353
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

// COMMON FUNCTION
// random LL
LL randll(LL a,LL b)    {
    uniform_int_distribution<int> u(a,b);
    static mt19937 e(time(0));
    return u(e);
}

LL pw(LL a,LL k=modu-2) {
    LL ans=1;
    for (a%=modu;k;k>>=1)   {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int n,m,q;
LL a[maxn],b[maxn];

struct node {
    LL tag;
    LL sum,mn,mx;
} T[maxn<<2];

#define sum(k) T[k].sum
#define mn(k) T[k].mn
#define mx(k) T[k].mx
#define tag(k) T[k].tag

void renew(int k,int l,int r,LL d)  {
    tag(k)+=d;
    sum(k)+=(r-l+1)*d;
    mn(k)+=d;
    mx(k)+=d;
}

void godown(int k,int l,int r)  {
    int mid=(l+r)>>1;
    renew(k<<1,l,mid,tag(k));
    renew(k<<1|1,mid+1,r,tag(k));
    tag(k)=0;
}

void update(int k)  {
    sum(k)=sum(k<<1)+sum(k<<1|1);
    mn(k)=min(mn(k<<1),mn(k<<1|1));
    mx(k)=max(mx(k<<1),mx(k<<1|1));
}

void change(int k,int l,int r,int p,LL d)   {
    if (r<p) return ;
    if (p<=l)
        renew(k,l,r,d);
    else {
        godown(k,l,r);
        int mid=(l+r)>>1;
        change(k<<1,l,mid,p,d);
        change(k<<1|1,mid+1,r,p,d);
        update(k);
    }
}

LL travel(int k,int l,int r,LL x)   {
    // dbg(k,l,r,mn(k),mx(k));
    if (x>=mx(k)) return 0;
    if (x<=mn(k)) {
        // dbg(l,r);
        return (r-l+1)*x-sum(k);
    }
    godown(k,l,r);
    int mid=(l+r)>>1;
    return travel(k<<1,l,mid,x)+travel(k<<1|1,mid+1,r,x);
}

LL C2(LL x) {
    return x*(x+1)/2;
}

void build(int k,int l,int r)   {
    if (l==r)
        sum(k)=mn(k)=mx(k)=b[l];
    else {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        update(k);
    }
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin>>n>>m>>q;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=m;++i) cin>>b[i];

    for (int i=n;i;--i) a[i]-=a[i-1];
    for (int i=m;i;--i) b[i]-=b[i-1];

    LL base=0;
    for (int i=2;i<=m;++i)
        base+=(m-i+1)*b[i];
    
    build(1,2,m);

    while (q--) {
        int op,k,d;
        cin>>op>>k>>d;
        if (op==1) {
            for (int i=n-k+1;i<=n;++i)
                a[i]+=d;
        } else {
            if (k==m)
                b[1]+=d,--k;
            base+=d*C2(k);
            change(1,2,m,m-k+1,d);
        }

        LL ans=base+(a[1]+b[1])*(n+m-1);
        // dbg(base,ans,sum(1));
        for (int i=n;i>1;--i)   {
            LL t=sum(1)+travel(1,2,m,a[i]);
            // dbg(i,a[i],t);
            ans+=(n-i+1)*a[i]+t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/