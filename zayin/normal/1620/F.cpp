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

int n,p[maxn];
int dp[2][maxn][2];
pair<int,int> prt[2][maxn][2];
auto f=dp[0],g=dp[1];
auto pf=prt[0],pg=prt[1];
// max, second mx

void chkmin(int &a,int b)   {
    a=min(a,b);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n;
        for (int i=1;i<=n;++i)
            cin>>p[i];
        for (int i=1;i<=n;++i)
            for (int c=0;c<=1;++c)
                f[i][c]=g[i][c]=maxn;
        f[1][0]=f[1][1]=-maxn;
        for (int i=1;i<n;++i)
            for (int c=0;c<=1;++c)  {
                int a=c?-p[i]:p[i];
                for (int nc=0;nc<=1;++nc)   {
                    int na=nc?-p[i+1]:p[i+1];
                    if (f[i][c]<na&&na<a&&g[i+1][nc]>a) 
                        g[i+1][nc]=a,pg[i+1][nc]=mp(0,c);
                    if (a<na&&f[i+1][nc]>f[i][c]) 
                        f[i+1][nc]=f[i][c],pf[i+1][nc]=mp(0,c);

                    if (a<na&&na<g[i][c]&&g[i+1][nc]>g[i][c]) 
                        g[i+1][nc]=g[i][c],pg[i+1][nc]=mp(1,c);
                    if (g[i][c]<na&&f[i+1][nc]>a)
                        f[i+1][nc]=a,pf[i+1][nc]=mp(1,c);
                }
            }
        int k=0,c=0;
        for (int x=0;x<=1;++x)
            for (int y=0;y<=1;++y)
                if (dp[x][n][y]<=n)
                    k=x,c=y;
        if (dp[k][n][c]>n)
            cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            function<void(int,int,int)> pr=[&](int k,int i,int c)  {
                if (i>1)
                    pr(prt[k][i][c].first,i-1,prt[k][i][c].second);
                cout<<(c?-p[i]:p[i])<<" \n"[i==n];
            };
            pr(k,n,c);
        }
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/