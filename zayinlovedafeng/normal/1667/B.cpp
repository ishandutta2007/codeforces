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
LL a[maxn],s[maxn];

int G[maxn],dp[maxn];

struct SegT {
    int T[maxn<<2];

    void build(int k,int l,int r)   {
        T[k]=-1e9;
        if (l==r) return ;
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
    }

    void change(int k,int l,int r,int p,int x)  {
        T[k]=max(T[k],x);
        if (l==r) return ;
        int mid=(l+r)>>1;
        if (p<=mid)
            change(k<<1,l,mid,p,x);
        else
            change(k<<1|1,mid+1,r,p,x);
    }

    int query(int k,int l,int r,int a,int b)    {
        if (a>r||l>b||a>b) return -1e9;
        if (a<=l&&r<=b) return T[k];
        int mid=(l+r)>>1;
        return max(query(k<<1,l,mid,a,b),query(k<<1|1,mid+1,r,a,b));
    }
} pre,suf;

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n;
        vector<LL> S;
        for (int i=1;i<=n;++i) {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
            S.push_back(s[i]);
        }

        S.push_back(s[0]);
        sort(S.begin(),S.end());
        S.resize(unique(S.begin(),S.end())-S.begin());

        for (int i=0;i<=n;++i) s[i]=lower_bound(S.begin(),S.end(),s[i])-S.begin()+1;

        for (int i=1;i<=S.size();++i) G[i]=-1e9;

        pre.build(1,1,S.size());
        suf.build(1,1,S.size());

        G[s[0]]=0;
        pre.change(1,1,S.size(),s[0],0);
        suf.change(1,1,S.size(),s[0],0);
        for (int i=1;i<=n;++i)  {
            int a=pre.query(1,1,S.size(),1,s[i]-1)+i;
            int b=suf.query(1,1,S.size(),s[i]+1,S.size())-i;
            int c=G[s[i]];
            dp[i]=max({a,b,c});
            G[s[i]]=max(G[s[i]],dp[i]);
            pre.change(1,1,S.size(),s[i],dp[i]-i);
            suf.change(1,1,S.size(),s[i],dp[i]+i);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/