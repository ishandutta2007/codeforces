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
int deg[maxn];
vector<int> G[2][maxn];

bool del[maxn];

int tot;
int u[maxn],v[maxn],w[maxn];

int f[maxn],diff[maxn],res[maxn];

int getedge(vector<int> E)  {
    while (E.size()&&del[abs(E.back())]) {
        // dbg(E.back());
        E.pop_back();
    }
    return E.size()?E.back():0;
}

int getend(int k,int i) {
    return u[abs(k)]^v[abs(k)]^i;
}

int getnei(int i)  {
    for (int c=0;c<=1;++c)  {
        int t=getedge(G[c][i]);
        if (t) return t;
    }
    return 0;
}

int find(int i) {
    if (!~f[i]) return i;
    int t=find(f[i]);
    diff[i]^=diff[f[i]];
    res[i]=res[t]^diff[i];
    return f[i]=t;
}

int addedge(int u,int v,int w)   {
    ++tot;
    // dbg("addedge",tot,u,v,w);
    ::u[tot]=u,::v[tot]=v,::w[tot]=w;
    G[w-1][u].push_back(tot);
    G[w-1][v].push_back(-tot);
    return tot;
}

void link(int x,int y)  {
    // dbg("link",x,y);
    diff[abs(y)]=(LL)x*y<0;
    f[abs(y)]=abs(x);
}

void reduce()   {
    for (int c=0;c<=1;++c)  {
        for (int i=1;i<=n;++i)  {
            // dbg(i);
            while (1)   {
                int x=getedge(G[c][i]); del[abs(x)]=1;
                int y=getedge(G[c][i]); del[abs(y)]=1;
                // dbg(x,y);
                if (!x||!y) { 
                    if (x) G[c][i].push_back(x),del[abs(x)]=0;
                    if (y) G[c][i].push_back(y),del[abs(y)]=0;
                    break;
                }
                int a=getend(x,i),b=getend(y,i);
                // dbg(i,a,b);
                if (a==b)   {
                    res[abs(x)]=x<0;
                    res[abs(y)]=y>0;
                } else {
                    int k=addedge(a,b,c+1);
                    link(k,-x);
                    link(k,y);
                    // dbg(i,getend(x,i),getend(y,i));
                }
                deg[i]-=2;
                del[abs(y)]=1;
            }
        }
        // cout<<"=========="<<endl;
    }
}

bool vis[maxn];

void assign(int i)  {
    if (vis[i]) return ;
    vis[i]=1;
    int k=getnei(i);
    // dbg(i,k);
    if (!k) return ;
    del[abs(k)]=1;
    res[abs(k)]=k<0;
    // dbg(i,"->",getend(k,i));
    assign(getend(k,i));
}

void solve()    {
    for (int i=1;i<=n;++i)
        if (deg[i]==1)
            assign(i);
    for (int i=1;i<=n;++i)
        assign(i);

    for (int i=1;i<=m;++i)   {
        find(i);
        cout<<res[i]+1;
    }
    cout<<endl;
}

int sum[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    memset(f,-1,sizeof(f));

    cin>>n>>m;
    for (int i=1;i<=m;++i)   {
        int u,v,w;
        cin>>u>>v>>w;
        ++deg[u],++deg[v];
        sum[u]+=w,sum[v]+=w;
        addedge(u,v,w);
    }

    int ans=0;
    for (int i=1;i<=n;++i) {
        // dbg(i,sum[i]);
        ans+=(sum[i]&1);
    }
    cout<<ans<<endl;

    reduce();
    solve();

    // for (int i=1;i<=tot;++i)    {
    //     find(i);
    //     dbg(i,res[i],diff[i]);
    // }

    for (int i=1;i<=n;++i) sum[i]=0;
    for (int i=1;i<=m;++i)  {
        find(i);
        if (res[i])
            sum[v[i]]+=w[i],sum[u[i]]-=w[i];
        else
            sum[u[i]]+=w[i],sum[v[i]]-=w[i];
    }
    for (int i=1;i<=n;++i)  {
        // dbg(i,sum[i]);
        ans-=abs(sum[i])==1;
    }
    // dbg(ans);
    assert(!ans);

    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/