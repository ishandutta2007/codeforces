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

int sz,rt;
struct node {
    int mn,mx;
    int tag;
    int ls,rs;
} T[maxn*maxh];

#define ls(k) T[k].ls
#define rs(k) T[k].rs
#define tag(k) T[k].tag
#define mx(k) T[k].mx
#define mn(k) T[k].mn

int newnode(int l,int r)    {
    // dbg(l,r);
    int k=++sz;
    mn(k)=l,mx(k)=r;
    tag(k)=0;
    ls(k)=rs(k)=0;
    return k;
}

void renew(int k,int d) {
    tag(k)+=d;
    mn(k)+=d;
    mx(k)+=d;
}

void godown(int k,int l,int r)  {
    int mid=(l+r)>>1;
    if (!ls(k)) ls(k)=newnode(l,mid);
    if (!rs(k)) rs(k)=newnode(mid+1,r);
    renew(ls(k),tag(k));
    renew(rs(k),tag(k));
    tag(k)=0;
}

void update(int k)  {
    mn(k)=min(mn(ls(k)),mn(rs(k)));
    mx(k)=max(mx(ls(k)),mx(rs(k)));
}

void change(int k,int l,int r,int x)    {
    // dbg(k,l,r);
    if (mn(k)==x&&mx(k)==x) return ;
    if (mx(k)<x) return renew(k,1);
    if (mn(k)>x) return renew(k,-1);
    godown(k,l,r);
    int mid=(l+r)>>1;
    change(ls(k),l,mid,x);
    change(rs(k),mid+1,r,x);
    update(k);
}

int query(int k,int l,int r,int p)  {
    // dbg("query",k,l,r,p,tag(k));
    if (p<l||p>r) return 0;
    if (!k) return p;
    if (l==r) return tag(k)+p;
    int mid=(l+r)>>1;
    return query(ls(k),l,mid,p)+query(rs(k),mid+1,r,p)+tag(k);
}

const int lim=1e9;

int n,q,x,a[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;

    int ans=0;
    rt=newnode(0,lim);
    for (int i=1;i<=n;++i)  {
        cin>>a[i];
        // dbg(i,a[i]);
        change(rt,0,lim,a[i]);
        cin>>q;
        while (q--) {
            cin>>x;
            x=(ans+x)%(lim+1);
            // dbg(x);
            cout<<(ans=query(rt,0,lim,x))<<endl;
        }
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/