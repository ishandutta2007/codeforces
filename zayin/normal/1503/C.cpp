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
#define maxn 500050
#define modu 998244353
#define inf 1e18
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

int n,a[maxn],c[maxn];
int pos[maxn];

LL mn[maxn];

LL Log2[maxn];
LL ST[maxh][maxn],* const dp=ST[0];

int main()  {
    Log2[0]=1;
    rep(i,1,maxn) Log2[i]=Log2[i>>1]+1;

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    read(n);
    rep(i,1,n+1)
        read(a[i],c[i]),pos[i]=i;
    sort(pos+1,pos+n+1,[&](int i,int j) {
        return a[i]>a[j]||(a[i]==a[j]&&i>j);
    });


    auto Min=[&](int l,int r)->LL {
        int d=r-l+1,offset=r;
        LL ans=inf;
        rep(i,0,maxh)
            if (d>>i&1) {
                ans=min(ans,ST[i][offset]);
                offset-=1<<i;
            }
        return ans;
    };

        auto find=[&](int x)    {
            int l=0,r=n;
            while (l<r) {
                int mid=(l+r+1)>>1;
                if (a[pos[mid]]<=x)
                    r=mid-1;
                else
                    l=mid;
            }
            return l;
        };

        mn[0]=inf;
        rep(i,1,n+1)    {
            // dbg(pos[i],a[pos[i]],c[pos[i]]);
            int j=find(a[pos[i]]+c[pos[i]]);
            if (!j)
                dp[i]=0;
            else
                dp[i]=min(Min(j+1,i-1),mn[j]-a[pos[i]]-c[pos[i]]);
            rep(j,1,Log2[i]+1)
                ST[j][i]=min(ST[j-1][i],ST[j-1][i-(1<<j-1)]);
            mn[i]=min(mn[i-1],dp[i]+a[pos[i]]);
            // dbg(dp[i]);
            // print("\n");
        }

    LL C=0;
    rep(i,1,n+1) C+=c[i];
    print(dp[n]+C);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/