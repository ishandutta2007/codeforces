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


int n,q,p[maxn];
bool vis[maxn];

namespace Splay   {
    #define ls(x) ch[x][0]
    #define rs(x) ch[x][1]

    int sz[maxn],val[maxn];
    int ch[maxn][2],fa[maxn],rev[maxn];

    void info() {
        for (int i=1;i<=n;++i) cout<<i<<":"<<fa[i]<<" ("<<ls(i)<<","<<rs(i)<<")"<<endl;
    }

    void init(int x) {
        val[x]=1;
        fa[x]=ls(x)=rs(x)=rev[x]=0;
    }

    int get(int x)  {   return ch[fa[x]][1]==x; }
    int isroot(int x)   {   return !(ch[fa[x]][0]==x||ch[fa[x]][1]==x); }

    void makerev(int x) {
        if (!x) return ;
        swap(ls(x),rs(x));
        rev[x]^=1;
    }

    void godown(int x)  {
        if (rev[x])
            makerev(ls(x)),makerev(rs(x)),rev[x]=0;
    }

    void update(int x)  {
        sz[x]=sz[ls(x)]+sz[rs(x)]+val[x];
    }

    void rotate(int x)  {
        int y=fa[x],z=fa[y],c=get(x);
        ch[y][c]=ch[x][c^1];
        if (ch[x][c^1]) fa[ch[x][c^1]]=y;
        if (!isroot(y)) ch[z][get(y)]=x;
        ch[x][c^1]=y,fa[x]=z,fa[y]=x;
        update(y),update(x);
    }

    void refresh(int x)    {
        if (!isroot(x)) refresh(fa[x]);
        godown(x);
    }
    void splay(int x)   {
        refresh(x);
        for (;!isroot(x);rotate(x))
            if (!isroot(fa[x]))
                rotate(get(fa[x])==get(x)?fa[x]:x);
    }
    
    void travel(int x)  {
        if (!x) return ;
        godown(x);
        travel(ls(x));
        cout<<x<<"("<<ls(x)<<","<<rs(x)<<") ";
        travel(rs(x));
    }

    void pr(int x)   {
        while (!isroot(x)) x=fa[x];
        cout<<"travel:"; travel(x); cout<<endl;
    }

    int rightmost(int k)   {
        while (rs(k)) k=rs(k);
        return k;
    }

    void shift(int x)   {
        splay(x);
        int y=rs(x);
        if (!y) return ;
        rs(x)=fa[y]=0;
        update(x);
        y=rightmost(y);
        splay(y);
        rs(y)=x,fa[x]=y;
        update(y);
        splay(x);
    }

    int pos(int k,int rk)  {
        if (rk==sz[ls(k)]+1) return k;
        if (rk<=sz[ls(k)])
            return pos(ls(k),rk);
        else
            return pos(rs(k),rk-sz[ls(k)]-1);
    }
}

using namespace Splay;

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>p[i],Splay::init(i);
    for (int i=1;i<=n;++i)  {
        if (vis[i]) continue;
        int last=0;
        for (int j=i;!vis[j];vis[last=j]=1,j=p[j]) {
            // dbg(j);
            ls(j)=last,fa[last]=j,update(j);
            // info();
        }
    }

    while (q--) {
        int op,x,y;
        cin>>op>>x>>y;
        // dbg(op,x,y);
        if (op==1)  {
            shift(x);
            splay(y);
            if (rightmost(y)==x)    {
                rs(y)=fa[rs(y)]=0;
                update(y);
            } else {
                shift(y);
                rs(x)=y,fa[y]=x;
                update(x);
            }
        } else {
            splay(x);
            int p=(y+sz[ls(x)])%sz[x]+1;
            cout<<pos(x,p)<<endl;
        }

        // for (int i=1;i<=n;++i) 
        //     if (isroot(i))
        //         pr(i);
        // dbg("--------------");
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/