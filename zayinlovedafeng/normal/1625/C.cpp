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


#define maxn 505
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

int n,L,m;
LL a[maxn],d[maxn];
LL dp[2][maxn][maxn];

void chkmin(LL &a,LL b) {
    a=min(a,b);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>L>>m;
    for (int i=0;i<n;++i) cin>>d[i];
    for (int i=0;i<n;++i) cin>>a[i];
    d[n]=L;
    for (int i=n;i;--i) d[i]-=d[i-1];

    int now=0;
    memset(dp,0x3f,sizeof(dp));
    for (int i=0;i<=m;++i)
        dp[now][0][i]=0;
    for (int i=1;i<=n;++i)  {
        // dbg(i,d[i]);
        now^=1;
        memset(dp[now],0x3f,sizeof(dp[now]));
        for (int last=0;last<i;++last)
            for (int c=0;c<=m;++c)   {
                if (c<m)
                    chkmin(dp[now][last][c+1],dp[now^1][last][c]+a[last]*d[i]);
                chkmin(dp[now][i][c],dp[now^1][last][c]+a[last]*d[i]);
            }
        // for (int last=0;last<=i;++last)
        //     for (int c=0;c<=m;++c)
        //         if (dp[now][last][c]<=1e9)
        //             print("dp[",i,"][",last,"][",c,"]=",dp[now][last][c]);
    }
    cout<<dp[now][n][m]<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/