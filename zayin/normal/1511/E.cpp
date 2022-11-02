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

int n,m;
string s[maxn];

LL pw2[maxn];

int main()  {
    for (int i=pw2[0]=1;i<maxn;++i) pw2[i]=pw2[i-1]*2%modu;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    read(n,m);
    readarray(s,n);


    int tot=0;
    rep(i,0,n)
        rep(j,0,m)
            tot+=s[i][j]=='o';

    LL ans=0;
    rep(i,0,n)  {
        LL dp0=0,dp1=1,cnt=0;
        rep(j,0,m)
            if (s[i][j]=='*')
                tie(dp0,dp1)=mp(0,(dp0+dp1)%modu);
            else {
                ++cnt;
                ans=(ans+dp0*pw2[tot-cnt])%modu;
                //ok dp1 dp0
                //sb 0   dp0+dp1
                tie(dp0,dp1)=mp(dp1,(2*dp0+dp1)%modu);

            }
    }
    rep(j,0,m)  {
        LL dp0=0,dp1=1,cnt=0;
        rep(i,0,n)
            if (s[i][j]=='*')
                tie(dp0,dp1)=mp(0,(dp0+dp1)%modu);
            else {
                ++cnt;
                ans=(ans+dp0*pw2[tot-cnt])%modu;
                //ok dp1 dp0
                //sb 0   dp0+dp1
                tie(dp0,dp1)=mp(dp1,(2*dp0+dp1)%modu);

            }
    }

    print(ans);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/