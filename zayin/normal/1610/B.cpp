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

template<LL base,LL modu>
struct SegT {
    struct node {
        LL tag_mul,tag_add;
    } T[maxn<<2];

    #define tag_mul(k) T[k].tag_mul
    #define tag_add(k) T[k].tag_add

    void renew(int k,LL x,LL y) {
        tag_mul(k)=tag_mul(k)*x%modu;
        tag_add(k)=(tag_add(k)*x+y)%modu;
    }

    void godown(int k)  {
        renew(k<<1,tag_mul(k),tag_add(k));
        renew(k<<1|1,tag_mul(k),tag_add(k));
        tag_mul(k)=1,tag_add(k)=0;
    }

    void change(int k,int l,int r,int p)    {
        if (l==p&&r==p) return;
        if (p<l||p>r)   {
            renew(k,base,p);
        } else {
            godown(k);
            int mid=(l+r)>>1;
            change(k<<1,l,mid,p);
            change(k<<1|1,mid+1,r,p);
        }
        // dbg(k,l,r,tag_mul(k),tag_add(k));
    }

    LL query(int k,int l,int r,int p)   {
        if (l==r) return tag_add(k);
        godown(k);
        int mid=(l+r)>>1;
        if (p<=mid)
            return query(k<<1,l,mid,p);
        else
            return query(k<<1|1,mid+1,r,p);
    }

    void build(int k,int l,int r)   {
        tag_mul(k)=1,tag_add(k)=0;
        if (l==r) return;
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
    }
};

SegT<998244353,1000000007> T1;
SegT<1000000007,1000000009> T2;

int n,a[maxn];

LL h1[maxn],h2[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n;
        for (int i=1;i<=n;++i)
            cin>>a[i];
        auto check=[&](int x)   {
            vector<int> A,B;
            for (int i=1;i<=n;++i)
                if (a[i]!=x)
                    A.push_back(a[i]);
            for (int i=n;i;--i)
                if (a[i]!=x)
                    B.push_back(a[i]);
            // dbg(x,A,B);
            return A==B;
        };

        bool flag=check(0);
        for (int i=1;i<=n;++i)
            if (a[i]!=a[n-i+1]) {
                flag|=check(a[i]);
                flag|=check(a[n-i+1]);
                break;
            }
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/