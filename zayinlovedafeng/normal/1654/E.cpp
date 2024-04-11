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


#define maxn 120050
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

const int lim=90;

int n;
LL a[maxn],b[maxn];

int solveSmall()   {
    int ans=0;
    for (int d=-lim;d<=lim;++d)    {
        for (int i=1;i<=n;++i)
            b[i]=a[i]-(LL)i*d;
        sort(b+1,b+n+1);
        for (int i=1,j=1;i<=n;i=j)  {
            while (j<=n&&b[i]==b[j]) ++j;
            ans=max(ans,j-i);
        }
    }
    return ans;
}

const int M=maxn;
int cnt[maxn*2];

int solveBig()   {
    int ans=0,len=maxn/lim+10;
    for (int i=1;i<=n;++i)  {
        vector<int> ds;
        int l=max(i-len,1),r=min(i+len,n);
        for (int j=l;j<=r;++j)  {
            if (j==i) continue;
            if ((a[i]-a[j])%(i-j)) continue;
            int d=(a[i]-a[j])/(i-j);
            assert(-M<d&&d<M);
            ++cnt[d+M];
            ans=max(ans,1+cnt[d+M]);
            ds.push_back(d);
        }
        for (int d:ds)
            cnt[d+M]=0;
    }
    return ans;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];

    int ans1=solveSmall();
    int ans2=solveBig();
    int ans=max(ans1,ans2);
    cout<<n-ans<<endl;
    cerr<<clock()<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/