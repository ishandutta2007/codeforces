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


#define maxn 7000050
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

int n,a[maxn];

int sz=0;
int num[maxn];
map<int,int> id,pos;
vector<int> G[maxn];

int ispoint[maxn];

int getid(int x)    {
    if (!id.count(x))   {
        num[++sz]=x;
        return id[x]=sz;
    }
    return id[x];
}

int getfa(int x)  {
    int pw2=1;
    while (pw2<x) pw2<<=1;
    assert(pw2-x<x);
    return pw2-x;
}

void build(int a)   {
    ispoint[getid(a)]=1;
    while (a)   {
        int fa=getfa(a);
        G[getid(fa)].push_back(getid(a));
        a=fa;
    }
}

int ans=0,ansp,ansq;

int mx[maxn],mxp[maxn];

void dfs(int i) {
    if (ispoint[i])
        mx[i]=0,mxp[i]=i;
    else
        mx[i]=-1e9;
    sort(G[i].begin(),G[i].end());
    G[i].resize(unique(G[i].begin(),G[i].end())-G[i].begin());
    // cout<<"dfs:"<<i<<endl;
    for (int j:G[i])    {
        dfs(j);
        if (mx[i]+mx[j]+1>ans)  {
            ans=mx[i]+mx[j]+1;
            ansp=mxp[i];
            ansq=mxp[j];
        }
        if (mx[j]+1>mx[i])  {
            mx[i]=mx[j]+1;
            mxp[i]=mxp[j];
        }
    }
    // cout<<"dfs:"<<i<<" "<<mx[i]<<endl;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i],build(a[i]),pos[a[i]]=i;
    
    dfs(getid(0));
    cout<<pos[num[ansp]]<<" "<<pos[num[ansq]]<<" "<<ans<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/