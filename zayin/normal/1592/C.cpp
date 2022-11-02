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

int n,m;
LL a[maxn],sum[maxn],A;
vector<int> G[maxn];

int timestamp,L[maxn],R[maxn],seq[maxn];

void dfs(int i,int fa) {
    seq[L[i]=++timestamp]=i;
    for (int j:G[i])
        if (fa!=j)
            dfs(j,i);
    R[i]=timestamp;
}

bool solve2()   {
    return !A;
}

bool dfs2(int i,int fa,int flag)    {
    flag|=(sum[R[i]]==sum[L[i]-1]);
    if (flag&&(sum[R[i]]^sum[L[i]-1])==A) return 1;
    for (int j:G[i])
        if (fa!=j)
            if (dfs2(j,i,flag))
                return 1;
    return 0;
}

bool solve3()   {
    vector<pii> I;
    rep(i,2,n+1) {
        // dbg(i,sum[R[i]]^sum[L[i]-1]);
        if ((sum[R[i]]^sum[L[i]-1])==A)
            I.emplace_back(L[i],R[i]);
    }
    sort(I.begin(),I.end());

    int mnr=1e9;
    for (auto pr:I) {
        // dbg(pr);
        if (mnr<pr.first) return 1;
        mnr=min(mnr,pr.second);
    }
    return dfs2(1,0,0);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _;
    read(_);
    while (_--) {
        cin>>n>>m;
        A=0;
        rep(i,1,n+1) cin>>a[i],A^=a[i],G[i].clear();
        rep(_,1,n)  {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        timestamp=0;
        dfs(1,0);
        rep(i,1,n+1) sum[i]=sum[i-1]^a[seq[i]];
        if (solve2()||(m>2&&solve3()))
            print("YES");
        else
            print("NO");
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/