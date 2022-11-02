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

#define maxh 43
#define maxn 400050
#define modu 998244353
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

// COMMON FUNCTION
// min
template<class T>
T min(const vector<T>& v) { return *min_element(v.begin(),v.end()); }
// max
template<class T>
T max(const vector<T>& v) { return *max_element(v.begin(),v.end()); }

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
LL a[maxn];
LL t[maxn],b[maxn];

const LL lim=1e13;
int sz,rt;

vector<LL> X;

struct info {
    int cnt;
    LL sum,sum2;
    friend info operator + (const info& a,const info& b)    {
        return info{a.cnt+b.cnt,a.sum+b.sum,a.sum2+b.sum2+b.sum*a.cnt};
    }
};
struct node {
    info I;
} T[maxn<<2];

#define I(k) T[k].I
#define cnt(k) T[k].I.cnt
#define sum(k) T[k].I.sum
#define sum2(k) T[k].I.sum2

void update(int k)  {
    I(k)=I(k<<1)+I(k<<1|1);
}

void change(int k,LL l,LL r,LL p,int d) {
    if (l==r)   {
        I(k).cnt+=d;
        I(k).sum+=X[l]*d;
        I(k).sum2+=X[l]*d;
    } else {
        LL mid=(l+r)>>1;
        if (p<=mid)
            change(k<<1,l,mid,p,d);
        else
            change(k<<1|1,mid+1,r,p,d);
        update(k);
    }
    // dbg(k,l,r,X[p],d,cnt(k),sum(k),sum2(k));
}

LL query_first(int k,LL l,LL r,int c)   {
    if (c<=0) return 0;
    if (cnt(k)<=c) return I(k).sum;
    LL mid=(l+r)>>1;
    return query_first(k<<1,l,mid,c)+query_first(k<<1|1,mid+1,r,c-cnt(k<<1));
}
LL query_last(int k,LL l,LL r,int c)   {
    if (c<=0) return 0;
    if (cnt(k)<=c) return I(k).sum;
    LL mid=(l+r)>>1;
    return query_last(k<<1,l,mid,c-cnt(k<<1|1))+query_last(k<<1|1,mid+1,r,c);
}

inline LL f(int k) {
    return query_first(1,0,X.size()-1,k+1)-query_last(1,0,X.size()-1,k);
}

info query2_first(int k,LL l,LL r,int c)    {
    if (c<=0) return info{0,0,0};
    if (cnt(k)<=c) return I(k);
    LL mid=(l+r)>>1;
    return query2_first(k<<1,l,mid,c)+query2_first(k<<1|1,mid+1,r,c-cnt(k<<1));
}
info query2_last(int k,LL l,LL r,int c)    {
    if (c<=0) return info{0,0,0};
    if (cnt(k)<=c) return I(k);
    LL mid=(l+r)>>1;
    return query2_last(k<<1,l,mid,c-cnt(k<<1|1))+query2_last(k<<1|1,mid+1,r,c);
}

void calc() {
    int l=0,r=(n-1)/2;
    while (l<r) {
        int mid=(l+r+1)>>1;
        if (f(mid)>0)
            l=mid;
        else
            r=mid-1;
    }
    
    // rep(i,0,n)
    //     dbg(i,f(i));
    
    auto L=query2_first(1,0,X.size()-1,l+1),R=query2_last(1,0,X.size()-1,l);
    LL res=((L.sum*(l+2)-L.sum2)-R.sum2)*2;
    // rep(i,0,l+1)
    //     res+=f(i)*2;
    // dbg(l);
    // dbg(L.cnt,L.sum,L.sum2);
    // dbg(R.cnt,R.sum,R.sum2);
    // dbg(res);
    if ((n&1)&&f(n/2)>0)
        res-=f(n/2);
    //f(i)=(a[1]+...+a[i+1])-(a[n-i+1]+...+a[n])
    //sum[i=0...l] f(i)=sum 
    print(sum(1)-res);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    read(n,q);
    readarray(a,n);
    rep(i,0,q)
        read(t[i],b[i]);

    rep(i,0,n) X.push_back(a[i]);
    rep(i,0,q) X.push_back(b[i]);
    sort(X.begin(),X.end());
    X.resize(unique(X.begin(),X.end())-X.begin());

    auto id=[&](LL x)   {
        return lower_bound(X.begin(),X.end(),x)-X.begin();
    };

    rep(i,0,n)
        change(1,0,X.size()-1,id(a[i]),1);
    calc();
    rep(i,0,q) {
        if (t[i]==1)
            change(1,0,X.size()-1,id(b[i]),1),++n;
        else
            change(1,0,X.size()-1,id(b[i]),-1),--n;
        calc();
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/