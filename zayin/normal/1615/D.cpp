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

#define endl '\n'

int n,m;
vector<pair<int,int>> G[maxn],T[maxn];

void join(int u,int v,int w)    {
    // dbg(u,v,w);
    G[u].emplace_back(v,w);
    G[v].emplace_back(u,w);
}

#define bc __builtin_popcount

void dfs1(int i,int fa) {
    for (auto e:T[i])   {
        int j=e.first;
        if (fa==j) continue;
        if (~e.second)
            join(i,j,bc(e.second)&1);
        dfs1(j,i);
    }
}

int res[maxn];

bool dfs2(int i)    {
    // dbg(i,res[i]);
    for (auto e:G[i])   {
        int j=e.first;
        if (!~res[j])   {
            res[j]=res[i]^e.second;
            if (dfs2(j)) return 1;
        } else {
            if (res[i]^res[j]^e.second)
                return 1;
        }
    }
    return 0;
}

bool dfs3(int i,int fa)    {
    for (auto e:T[i])   {
        int j=e.first;
        if (fa==j) continue;
        if (~e.second)
            cout<<i<<" "<<j<<" "<<e.second<<endl;
        else
            cout<<i<<" "<<j<<" "<<(res[i]^res[j])<<endl;
        dfs3(j,i);
    }
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n>>m;
        for (int i=1;i<=n;++i) G[i].clear(),T[i].clear();
        for (int k=1;k<n;++k)   {
            int u,v,w;
            cin>>u>>v>>w;
            T[u].emplace_back(v,w);
            T[v].emplace_back(u,w);
        }
        dfs1(1,0);
        while (m--) {
            int u,v,w;
            cin>>u>>v>>w;
            join(u,v,w);
        }

        for (int i=1;i<=n;++i) res[i]=-1;

        bool flag=0;
        for (int i=1;i<=n;++i)
            if (!~res[i])    {
                res[i]=0;
                flag|=dfs2(i);
            }
        if (flag)
            cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            dfs3(1,0);
        }
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/