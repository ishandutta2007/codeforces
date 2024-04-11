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


#define maxn 1500050
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

struct node {
    int tag,val;
} T[maxn<<2];

#define tag(k) T[k].tag
#define val(k) T[k].val

void renew(int k,int d) {
    val(k)+=d;
    tag(k)+=d;
}

void godown(int k)    {
    renew(k<<1,tag(k));
    renew(k<<1|1,tag(k));
    tag(k)=0;
}

void update(int k)  {
    val(k)=min(val(k<<1),val(k<<1|1));
}

void change(int k,int l,int r,int a,int b,int d)    {
    // dbg(k,l,r,a,b,d);
    if (a<=l&&r<=b)
        renew(k,d);
    else {
        godown(k);
        int mid=(l+r)>>1;
        if (a<=mid)
            change(k<<1,l,mid,a,b,d);
        if (b>mid)
            change(k<<1|1,mid+1,r,a,b,d);
        update(k);
    }
}

int n,m;
int L[maxn],R[maxn],w[maxn];
int pos[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin>>n>>m; --m;
    rep(i,1,n+1)
        cin>>L[i]>>R[i]>>w[i],pos[i]=i,--R[i];
    sort(pos+1,pos+n+1,[&](int i,int j){
        return w[i]<w[j];
    });

    int ans=1e9;
    for (int i=1,j=1;i<=n;++i)  {
        for (j=max(j,i);!val(1)&&j<=n;++j)
            // dbg(i,j),
            // print("add",L[pos[j]],R[pos[j]]),
            change(1,1,m,L[pos[j]],R[pos[j]],1);
        if (!val(1)) break;
        // dbg(i,j,w[pos[j-1]]-w[pos[i]],val(1));
        ans=min(ans,w[pos[j-1]]-w[pos[i]]);
            // print("del",L[pos[i]],R[pos[i]]),
        change(1,1,m,L[pos[i]],R[pos[i]],-1);
        // dbg(val(1));
    }
    cout<<ans<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/