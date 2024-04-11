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
// min
template<class T>
T min(const vector<T>& v) { return *min_element(v.begin(),v.end()); }
// max
template<class T>
T max(const vector<T>& v) { return *max_element(v.begin(),v.end()); }

LL pw(LL a,LL k=modu-2) {
    LL ans=1;
    for (a%=modu;k;k>>=1)   {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int n,a[maxn];

LL f[maxn],g[maxn],h[maxn];
// x+1,x-1,x+1

int main()  {
    // cout<<(2<3?1:(0==1?2:3))<<endl;
    // cout<<(2<3?1:0==1?2:3)<<endl;

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        read(n);
        readarray(a,n);
        rep(i,0,n+10) f[i]=g[i]=h[i]=0;
        LL ans=0;
        rep(i,0,n)  {
            LL fi=f[a[i]]+(a[i]?f[a[i]-1]:1);
            LL gi=g[a[i]]+(a[i]>1?f[a[i]-2]+h[a[i]-2]:a[i]==1?1:0);
            LL hi=h[a[i]]+g[a[i]+2];
            f[a[i]]=(f[a[i]]+fi)%modu;
            g[a[i]]=(g[a[i]]+gi)%modu;
            h[a[i]]=(h[a[i]]+hi)%modu;
            // cerr<<i<<":"<<a[i]<<" "<<fi<<" "<<gi<<" "<<hi<<endl;
            ans=(ans+fi+gi+hi)%modu;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/