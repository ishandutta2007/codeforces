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

int n;
unordered_map<int,int> resp;

const int a[]={0,6,6,6,6,6,6};

int ask(int w)  {
    if (resp.count(w)) return resp[w];
    static int cnt=0;
    assert(cnt<n+30);
    ++cnt;
    cout<<"? "<<w<<endl;

    // int resp=0;
    // for (int i=1,j=1;i<=n;i=j)  {
    //     if (a[i]>w) return 0;
    //     int sum=a[i];
    //     for (j=i+1;j<=n&&sum+a[j]+1<=w;++j) sum+=a[j]+1;
    //     ++resp;
    // }
    // return resp;

    int h;
    cin>>h;
    return h;
}

bool noprime[maxn];

int divup(int a,int b)  {
    return (a+b-1)/b;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;

    int l=1,r=2000*n+n-1;
    while (l<r) {
        int mid=(l+r)>>1;
        if (ask(mid)!=1)
            l=mid+1;
        else
            r=mid;
    }
    // dbg(r);

    int ans=r;
    for (int i=n;i>1;--i)  {
        // if (noprime[i]) continue;
        // for (int j=i<<1;j<=n;j+=i)
        //     noprime[j]=1;
        int w=ask(r/i);
        if (w)
            ans=min(ans,w*(r/i));
    }
    cout<<"! "<<ans<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/