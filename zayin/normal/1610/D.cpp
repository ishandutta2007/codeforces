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

#define maxb 40
#define maxn 200050
#define modu 1000000007
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

int n,a[maxn];
LL dp[maxn][maxb][2];

LL Log2(LL x)   {
    return (x&1)?0:Log2(x>>1)+1;
}

void add(LL &a,LL b)    {
    a=(a+b)%modu;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;

    dp[0][maxb-1][0]=1;
    for (int i=1;i<=n;++i)  {
        cin>>a[i];
        int k=Log2(a[i]);
        // dbg(i,k);
        memcpy(dp[i],dp[i-1],sizeof(dp[i]));
        for (int b=0;b<maxb;++b)
            for (int c=0;c<=1;++c)  {
                if (b<k) add(dp[i][b][c],dp[i-1][b][c]);
                if (b==k) add(dp[i][b][c^1],dp[i-1][b][c]);
                if (b>k) add(dp[i][k][1],dp[i-1][b][c]);
            }
        // for (int b=0;b<=30;++b)
        //     for (int c=0;c<=1;++c)
        //         if (dp[i][b][c])
        //             print("dp[",i,"][",b,"][",c,"]=",dp[i][b][c]);
    }

    LL ans=dp[n][0][1];
    for (int b=0;b<=30;++b)
        add(ans,dp[n][b][0]);
    cout<<ans<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/