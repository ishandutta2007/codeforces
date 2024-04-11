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

#define maxb 61
#define maxn 1000050
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

int n;
LL a[maxn];
LL mn[maxn],mx[maxn];

#define bc __builtin_popcountll

int cntx[maxb],cnty[maxb];

LL solve(int l,int r)   {
    if (l==r) return 1;
    int mid=(l+r)>>1;

    for (int i=l;i<=r;++i) mn[i]=mx[i]=a[i];
    for (int i=mid-1;i>=l;--i)  {
        mn[i]=min(mn[i],mn[i+1]);
        mx[i]=max(mx[i],mx[i+1]);
    }
    for (int i=mid+2;i<=r;++i)  {
        mn[i]=min(mn[i],mn[i-1]);
        mx[i]=max(mx[i],mx[i-1]);
    }

    // for (int i=l;i<=mid;++i) dbg("L",i,mn[i],mx[i]);
    // for (int i=mid+1;i<=r;++i) dbg("R",i,mn[i],mx[i]);

    LL ans=0;

    int x=mid,y=mid;
    for (int b=0;b<maxb;++b) cntx[b]=cnty[b]=0;
    for (int i=mid+1;i<=r;++i)  {
        for (;x>=l&&mx[x]<=mx[i];--x) ++cntx[bc(mn[x])];
        for (;y>=l&&mx[y]<=mx[i]&&mn[y]>=mn[i];--y) ++cnty[bc(mn[y])];
        if (bc(mn[i])==bc(mx[i])) // mn,mx in R
            ans+=mid-y;
        // dbg(i,ans,y);
        ans+=cntx[bc(mx[i])]-cnty[bc(mx[i])]; // mx in R, mn in L
        // dbg(i,ans);
    }
    

    x=mid+1,y=mid+1;
    for (int b=0;b<maxb;++b) cntx[b]=cnty[b]=0;
    for (int i=mid;i>=l;--i)  {
        for (;x<=r&&mx[x]<mx[i];++x) ++cntx[bc(mn[x])];
        for (;y<=r&&mx[y]<mx[i]&&mn[y]>mn[i];++y) ++cnty[bc(mn[y])];
        if (bc(mn[i])==bc(mx[i])) // mn,mx in L
            ans+=y-mid-1;
        ans+=cntx[bc(mx[i])]-cnty[bc(mx[i])]; // mx in L, mn in R
    }

    return solve(l,mid)+solve(mid+1,r)+ans;
}


int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    
    // for (int i=1;i<=n;++i) cout<<bc(a[i])<<" "; cout<<endl;

    LL ans=solve(1,n);
    cout<<ans<<endl;

    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/