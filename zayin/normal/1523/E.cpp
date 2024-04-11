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
#define modu 1000000007
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

int n,m;
LL F[maxn],I[maxn];

LL C(LL n,LL m) {
    return n<m?0:F[n]*I[m]%modu*I[n-m]%modu;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    F[0]=I[0]=I[1]=1;
    rep(i,1,maxn) F[i]=F[i-1]*i%modu;
    rep(i,2,maxn) I[i]=modu-modu/i*I[modu%i]%modu;
    rep(i,2,maxn) I[i]=I[i]*I[i-1]%modu;
    rep(i,0,maxn) assert(F[i]*I[i]%modu==1);

    int _;
    read(_);
    while (_--) {
        read(n,m);
        LL ans=F[n];
        rep(i,1,n+1)  {
            if ((i-1)*m+1>n) break;
            LL x=n-(i-1)*m-1,y=i+1;
            LL cnt=C(x+y-1,y-1);
            // print(i,cnt,F[i],F[n-i],cnt*F[i]%modu*F[n-i]%modu);
            ans=(ans+cnt*F[i]%modu*F[n-i]%modu)%modu;
        }
        ans=ans*I[n]%modu;
        print(ans);
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/