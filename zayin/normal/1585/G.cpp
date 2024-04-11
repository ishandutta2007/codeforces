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

#define maxh 30
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

int n,fa[maxn],son[maxn];
int dep[maxn],*len=dep;

int pool[maxn],*ptr=pool,*sg[maxn];

vector<int> G[maxn];

int SG[maxn];
// #define SG(i) (*sg[i])

int sz,rt[maxn];
struct node {
    int cnt;
    int ls,rs;
} T[maxn*maxh];

#define ls(k) T[k].ls
#define rs(k) T[k].rs
#define cnt(k) T[k].cnt

int newnode()   {
    int k=++sz;
    ls(k)=rs(k)=cnt(k)=0;
    assert(sz<maxn*maxh);
    return k;
}

void change(int &k,int l,int r,int p)    {
    if (l>r||p<l||p>r) return;
    if (!k) k=newnode();
    // dbg("change",k,l,r,p);
    if (l==r)   {
        cnt(k)=1;
    } else {
        int mid=(l+r)>>1;
        change(ls(k),l,mid,p);
        change(rs(k),mid+1,r,p);
        cnt(k)=cnt(ls(k))+cnt(rs(k));
    }
}

int query(int k,int l,int r)  {
    if (cnt(k)==r-l+1) return -1;
    if (l==r) return l;
    int mid=(l+r)>>1;
    int t=query(ls(k),l,mid);
    if (!~t)
        t=query(rs(k),mid+1,r);
    return t;
}

void dfs1(int i) {
    dep[i]=1;
    son[i]=0;
    for (int j:G[i])    {
        dfs1(j);
        dep[i]=max(dep[i],dep[j]+1);
        if (dep[son[i]]<dep[j])
            son[i]=j;
    }
}

void dfs2(int i) {
    // dbg("dfs2",i,son[i]);
    sg[i]=ptr++;
    if (!son[i]) {
        len[i]=0;
        SG[i]=1;
        change(rt[i],0,n,sg[i][0]=0);
    } else  {
        dfs2(son[i]);
        len[i]=len[son[i]]+1;
        sg[i][0]=SG[son[i]];

        if (G[i].size()==1) {
            rt[i]=rt[son[i]];
            change(rt[i],0,n,SG[son[i]]);
        } else {
            for (int j:G[i])    {
                if (son[i]==j) continue;
                dfs2(j);
                len[i]=min(len[i],len[j]+1);

                sg[i][0]^=SG[j];
                for (int p=1;p<=len[i];++p)
                    sg[i][p]^=sg[j][p-1];
            }
            // for (int p=0;p<=len[i];++p) dbg(i,p,sg[i][p]);
            for (int p=0;p<=len[i];++p)
                change(rt[i],0,n,sg[i][p]);
        }
        SG[i]=query(rt[i],0,n);
    }
    // dbg(i,SG[i]);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n;
        for (int i=1;i<=n;++i) G[i].clear();
        for (int i=1;i<=n;++i)  {
            cin>>fa[i];
            if (fa[i])
                G[fa[i]].push_back(i);
        }

        ptr=pool,sz=0;
        for (int i=1;i<=n;++i)
            rt[i]=0;

        int ans=0;
        for (int i=1;i<=n;++i)
            if (!fa[i]) {
                dfs1(i);
                dfs2(i);
                ans^=SG[i];
            }
        cout<<(ans?"YES":"NO")<<'\n';
    }
    cerr<<clock()<<" "<<sz<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/