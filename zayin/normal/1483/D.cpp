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


#define maxn 605
#define maxm maxn*maxn
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

int n,m,q;
int U[maxm],V[maxm],W[maxm];
LL dis0[maxn][maxn],dis1[maxn][maxn];

const LL inf=1e18;

void chkmin(LL& x,LL y) {
    x=min(x,y);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    read(n,m);
    rep(i,1,n+1)
        rep(j,1,n+1)
            dis0[i][j]=dis1[i][j]=inf;
    rep(i,0,m)  {
        int u,v,w;
        read(u,v,w);
        dis0[u][v]=dis0[v][u]=min(dis0[u][v],(LL)w);
        U[i]=u,V[i]=v,W[i]=w;
    }
    read(q);
    while (q--) {
        int u,v,w;
        read(u,v,w);
        dis1[u][v]=dis1[v][u]=min(dis1[u][v],(LL)-w);
    }

    rep(k,1,n+1)
        rep(i,1,n+1)
            rep(j,1,n+1)    
                chkmin(dis0[i][j],dis0[i][k]+dis0[k][j]);

    rep(k,1,n+1)
        rep(i,1,n+1)
            rep(j,1,n+1)    {
                chkmin(dis1[i][j],dis1[i][k]+dis0[k][j]);
                chkmin(dis1[i][j],dis0[i][k]+dis1[k][j]);
            }

    int ans=0;
    rep(i,0,m)
        if (dis1[U[i]][V[i]]+W[i]<=0)
            ++ans;
    print(ans);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/