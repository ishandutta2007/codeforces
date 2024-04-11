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

int n,q,a[maxn];
struct qry {
    int id,l,k;
};
vector<int> G[maxn];
vector<qry> Q[maxn];

int cnt[maxn];
set<int> num[maxn];

int T[maxn];


int lowbit(int x)  {
    return x&-x;
}

void change(int i,int d)  {
    for (;i<=n;i+=lowbit(i))
        T[i]+=d;
}

int query(int i)    {
    LL ans=0;
    for (;i;i-=lowbit(i))
        ans+=T[i];
    return ans;
}

void clr(int a) {
    if (!cnt[a]) return ;
    num[cnt[a]].erase(a);
    change(cnt[a],-1);
}

void ins(int a) {
    if (!cnt[a]) return ;
    num[cnt[a]].insert(a);
    change(cnt[a],1);
}

int get(int c) {
    if (query(n)<c) return -1;
    int i=0;
    for (int h=maxh-1;~h;--h)
        if (i+(1<<h)<=n&&T[i+(1<<h)]<c)
            i+=1<<h,c-=T[i];
    assert(num[i+1].size());
    return *num[i+1].begin();
}

int ans[maxn];

void dfs(int i) {
    // cout<<"dfs:"<<i<<endl;
    clr(a[i]);
    ++cnt[a[i]];
    ins(a[i]);

    for (auto q:Q[i])   {
        int t=query(q.l-1);
        // dbg(q.id,t);
        ans[q.id]=get(t+q.k);
        // dbg(ans[q.id]);
    }

    for (int j:G[i])    
        dfs(j);
    
    clr(a[i]);
    --cnt[a[i]];
    ins(a[i]);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n>>q;
        for (int i=1;i<=n;++i) G[i].clear();
        for (int i=1;i<=n;++i) Q[i].clear();
        for (int i=1;i<=n;++i) T[i]=0;
        for (int i=1;i<=n;++i)
            cin>>a[i];
        for (int i=2;i<=n;++i)   {
            int p;
            cin>>p;
            G[p].push_back(i);
        }
        for (int i=1;i<=q;++i)  {
            int v,l,k;
            cin>>v>>l>>k;
            Q[v].push_back(qry{i,l,k});
        }
        dfs(1);
        for (int i=1;i<=q;++i)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/