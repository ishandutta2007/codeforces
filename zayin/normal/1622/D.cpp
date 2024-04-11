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


#define maxn 5050
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

int n,m;
int sum[maxn];
char s[maxn];

LL F[maxn],FI[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    F[0]=FI[0]=FI[1]=1;
    for (int i=1;i<maxn;++i) F[i]=F[i-1]*i%modu;
    for (int i=2;i<maxn;++i) FI[i]=modu-modu/i*FI[modu%i]%modu;
    for (int i=2;i<maxn;++i) FI[i]=FI[i-1]*FI[i]%modu;
    for (int i=0;i<maxn;++i) assert(F[i]*FI[i]%modu==1);

    cin>>n>>m>>s+1;
    for (int i=1;i<=n;++i)
        sum[i]=sum[i-1]+s[i]-'0';
    
    LL ans=1;
    if (sum[n]>=m)  {
        for (int l=1;l<=n;++l)
            for (int r=l+1;r<=n;++r)  {
                if (sum[r]-sum[l-1]>m) continue;
                int cnt[2]={r-l+1-sum[r]+sum[l-1],sum[r]-sum[l-1]};
                --cnt['1'-s[l]];
                --cnt['1'-s[r]];
                if (cnt[0]<0||cnt[1]<0) continue;
                LL t=F[cnt[0]+cnt[1]]*FI[cnt[0]]%modu*FI[cnt[1]]%modu;
                // dbg(l,r,cnt[0],cnt[1],t);
                ans=(ans+t)%modu;
            }
    }
    cout<<ans<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/