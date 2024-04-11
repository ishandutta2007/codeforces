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


#define maxn 20000050
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

int n,a[maxn];
LL dp[maxn],cnt[maxn];

int p[maxn],pnum;
int noprime[maxn];
int mnp[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    for (int i=2;i<maxn;++i)    {
        if (!noprime[i])
            p[pnum++]=i,mnp[i]=i;
        for (int j=0;j<pnum&&i*p[j]<maxn;++j)   {
            int k=i*p[j];
            noprime[k]=1;
            mnp[k]=p[j];
            if (i%p[j]==0)
                break;
        }
    }

    cin>>n;
    for (int i=1;i<=n;++i)  {
        cin>>a[i];
        auto fac=[&](int x)  {
            vector<pair<int,int>> F;
            while (x>1)   {
                int p=mnp[x];
                if (F.size()&&F.back().first==p)
                    ++F.back().second;
                else
                    F.emplace_back(p,1);
                x/=p;
            }
            return F;
        };
        auto F=fac(a[i]);
        // dbg(i,a[i],F);
        function<void(int,int)> dfs=[&](int j,int x) {
            if (j==F.size())    {
                // cout<<x<<" ";
                ++cnt[x];
            } else {
                for (int e=0;e<=F[j].second;++e)
                    dfs(j+1,x),x*=F[j].first;
            }
        };
        dfs(0,1);
        // cout<<endl;
    }

    LL ans=0,CNT=0;
    for (int i=maxn-1;i;--i)    {
        dp[i]=max(dp[i],i*cnt[i]);
        ans=max(ans,dp[i]);

        // dbg(i,dp[i],cnt[i]);

        int last=0;
        for (int t=i;t>1;t/=mnp[t]) {
            ++CNT;
            if (last==mnp[t]) continue;
            int j=i/(last=mnp[t]);
            dp[j]=max(dp[j],dp[i]+(cnt[j]-cnt[i])*j);
        }
    }

    cout<<ans<<endl;
    // cerr<<clock()<<" "<<CNT<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/