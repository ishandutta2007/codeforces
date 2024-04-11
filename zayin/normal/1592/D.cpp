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

int n;
vector<int> G[maxn];
vector<pii> seq;

void dfs(int i,int fa=0) {
    for (int j:G[i])
        if (fa!=j)  {
            seq.emplace_back(j,i);
            dfs(j,i);
            seq.emplace_back(j,i);
        }
}

int ask(int l,int r) {
    set<int> vert;
    for (int i=l;i<=r;++i)  {
        vert.insert(seq[i].first);
        vert.insert(seq[i].second);
    }

    cout<<"? "<<vert.size()<<" ";
    for (int i:vert) cout<<i<<" ";
    cout<<endl;

    int resp;
    cin>>resp;
    return resp;
}


int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    rep(_,1,n)  {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);

    int l=0,r=seq.size()-1;
    LL x=ask(l,r);
    while (l<r) {
        int mid=(l+r)>>1;
        if (ask(l,mid)==x)
            r=mid;
        else
            l=mid+1;
    }
    assert(l==r);
    cout<<"! "<<seq[l].first<<" "<<seq[r].second<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/