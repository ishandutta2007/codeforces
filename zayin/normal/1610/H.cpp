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

#define maxh 20
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
int dep[maxn];
int F[maxh][maxn],* const fa=F[0];
vector<int> G[maxn];

int pos[maxn];
int x[maxn],y[maxn],key[maxn];

int L[maxn],R[maxn],timestamp;

void dfs(int i) {
    L[i]=++timestamp;
    dep[i]=dep[fa[i]]+1;
    for (int j=1;j<maxh;++j)
        F[j][i]=F[j-1][F[j-1][i]];
    for (int j:G[i]) 
        dfs(j);
    R[i]=timestamp;
}

int keypoint(int x,int y)  {
    if (L[x]<=L[y]&&R[y]<=R[x]) {
        int d=dep[y]-dep[x]-1;
        for (int h=0;h<maxh;++h)
            if (d>>h&1)
                y=F[h][y];
        return y;
    } else {
        return 1;
        // dbg(x,y);
        // for (int h=maxh-1,d=dep[y]-dep[x];h>=0;--h)
        //     if (d>>h&1)
        //         y=F[h][y];
        // if (x==y) return x;
        // for (int h=maxh-1;h>=0;--h) {
        //     dbg(h,x,y,F[h][x],F[h][y]);
        //     if (F[h][x]==F[h][y]) continue;
        //     x=F[h][x];
        //     y=F[h][y];
        // }
        // return fa[x];
    }
}

int T[maxn],tot;

int lowbit(int x)   {
    return x&-x;
}

void ins(int i) {
    ++tot;
    for (;i<=n;i+=lowbit(i))
        ++T[i];
}

int query(int i)    {
    int ans=0;
    for (;i;i-=lowbit(i))
        ans+=T[i];
    return ans;
}

int query(int l,int r)  {
    return query(r)-query(l-1);
}

int calc(int i)   {
    if (L[x[i]]<=L[y[i]]&&R[y[i]]<=R[x[i]]) {
        return query(L[key[i]],R[key[i]])-query(L[y[i]],R[y[i]]);
    } else {
        return tot-query(L[x[i]],R[x[i]])-query(L[y[i]],R[y[i]]);
    }
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=2;i<=n;++i)  {
        cin>>fa[i];
        G[fa[i]].push_back(i);
    }

    dfs(1);
    
    for (int i=1;i<=m;++i)  {
        cin>>x[i]>>y[i];
        if (dep[x[i]]>dep[y[i]])
            swap(x[i],y[i]);
        if (fa[y[i]]==x[i])
            return cout<<"-1"<<endl,0;
        key[i]=keypoint(x[i],y[i]);
        pos[i]=i;
    }

    sort(pos+1,pos+m+1,[&](int i,int j){
        return dep[key[i]]>dep[key[j]];
    });

    int ans=0;
    for (int k=1;k<=m;++k)  {
        int i=pos[k];
        // cout<<i<<" "<<x[i]<<" "<<y[i]<<" "<<key[i]<<endl;
        if (calc(i)) continue;
        // dbg(key[i]);
        ++ans;
        ins(L[key[i]]);
    }
    cout<<ans<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/