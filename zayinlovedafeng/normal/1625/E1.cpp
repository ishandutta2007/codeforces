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

int n,q;
char s[maxn];

int stk[maxn],tp;

int match[maxn];
int fa[maxn];
vector<int> G[maxn];

LL cnt[maxn];
int L[maxn],R[maxn],timestamp;
int pos[maxn],timestamp2;


int lowbit(int x)   {
    return x&-x;
}

void change(LL T[maxn],int i,LL d)    {
    for (;i<=n;i+=lowbit(i))
        T[i]+=d;
}

LL query(LL T[maxn],int i)    {
    LL ans=0;
    for (;i;i-=lowbit(i))
        ans+=T[i];
    return ans;
}

LL query(LL T[maxn],int l,int r)   {
    return query(T,r)-query(T,l-1);
}

LL T[maxn],T2[maxn];

LL C2(LL x) {
    return x*(x+1)/2;
}

void dfs(int i) {
    L[i]=++timestamp;
    for (int j:G[i]) {
        pos[j]=++timestamp2;
        change(T2,pos[j],1);
    }
    for (int j:G[i])    {
        dfs(j);
        ++cnt[i];
        if (L[i])   {
            // dbg(i,j,cnt[i]);
            change(T,L[i],cnt[i]);
        }
    }
    R[i]=timestamp;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q>>s+1;

    stk[tp=0]=0;
    for (int i=1;i<=n;++i)  {
        if (s[i]=='(')  {
            G[stk[tp]].push_back(i);
            fa[i]=stk[tp];
            stk[++tp]=i;
        } else {
            if (tp) {
                match[i]=stk[tp];
                // dbg(stk[tp],i);
                --tp;
            }
        }
    }

    timestamp=1;
    dfs(0);

    while (q--) {
        int t,l,r;
        cin>>t>>l>>r;
        if (t==1)   {
        } else {
            int i=l,j=match[r];
            // dbg(i,j);
            assert(fa[i]==fa[j]);

            int c=query(T2,pos[i],pos[j]);
            // dbg(c);
            cout<<query(T,L[i],R[j])+C2(c)<<endl;
        }
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/