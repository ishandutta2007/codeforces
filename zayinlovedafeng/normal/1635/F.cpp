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

LL T[maxn<<2];

void change(int k,int l,int r,int p,LL x)  {
    T[k]=min(T[k],x);
    if (l==r) return ;
    int mid=(l+r)>>1;
    if (p<=mid)
        change(k<<1,l,mid,p,x);
    else
        change(k<<1|1,mid+1,r,p,x);
}

LL query(int k,int l,int r,int a,int b)    {
    if (a<=l&&r<=b) return T[k];
    if (a>r||l>b) return 1e18;
    int mid=(l+r)>>1;
    return min(query(k<<1,l,mid,a,b),query(k<<1|1,mid+1,r,a,b));
}

int n,q;
LL a[maxn],w[maxn];

vector<int> G[maxn];

int stk[maxn],tp;

LL ans[maxn];
vector<pair<int,int>> Q[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>w[i];
    
    tp=0;
    for (int i=1;i<=n;++i)  {
        while (tp&&w[stk[tp]]>w[i]) --tp;
        if (tp)
            G[i].push_back(stk[tp]);
        stk[++tp]=i;
    }
    
    tp=0;
    for (int i=n;i;--i)  {
        while (tp&&w[stk[tp]]>w[i]) --tp;
        if (tp)
            G[stk[tp]].push_back(i);
        stk[++tp]=i;
    }

    memset(T,0x3f,sizeof(T));
    for (int i=1;i<=q;++i)  {
        int l,r;
        cin>>l>>r;
        Q[r].emplace_back(l,i);
    }

    for (int i=1;i<=n;++i)  {
        for (int j:G[i])    {
            change(1,1,n,j,(a[i]-a[j])*(w[i]+w[j]));
        }
        for (auto pr:Q[i])
            ans[pr.second]=query(1,1,n,pr.first,i);
    }

    for (int i=1;i<=q;++i)
        cout<<ans[i]<<endl;

    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/