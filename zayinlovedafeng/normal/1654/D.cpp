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

LL I[maxn];

int mnp[maxn];


// a[j]=a[i]*x/y;
struct edge {
    int j,x,y;
};
vector<edge> G[maxn];

int n;
int mne[maxn],e[maxn];

LL ans;

void dfs(int i,int fa,LL sum) {
    // dbg(i,sum,e[2],mne[2]);
    ans=(ans+sum)%modu;
    for (auto [j,x,y]:G[i])   {
        if (fa==j) continue;
        // dbg(i,j,x,y);
        for (int t=x;t>1;t/=mnp[t]) ++e[mnp[t]];
        for (int t=y;t>1;t/=mnp[t]) mne[mnp[t]]=min(mne[mnp[t]],--e[mnp[t]]);
        dfs(j,i,sum*x%modu*I[y]%modu);
        for (int t=y;t>1;t/=mnp[t]) ++e[mnp[t]];
        for (int t=x;t>1;t/=mnp[t]) mne[mnp[t]]=min(mne[mnp[t]],--e[mnp[t]]);
    }
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    for (int i=1;i<maxn;++i) I[i]=pw(i);
    for (int i=maxn-1;i>1;--i)
        for (int j=i;j<maxn;j+=i)
            mnp[j]=i;
    // for (int i=1;i<=10;++i) dbg(i,mp
    
    int _;
    read(_);
    while (_--) {
        cin>>n;
        for (int i=1;i<=n;++i) G[i].clear();
        vector<int> nums;
        for (int k=1;k<n;++k)   {
            int i,j,x,y;
            cin>>i>>j>>x>>y;
            nums.push_back(x);
            nums.push_back(y);
            G[i].push_back(edge{j,y,x});
            G[j].push_back(edge{i,x,y});
        }

        ans=0;
        dfs(1,0,1);

        LL q=1;
        for (int x:nums)
            for (int t=x;t>1;t/=mnp[t]) {
                q=q*pw(mnp[t], -mne[mnp[t]])%modu;
                e[mnp[t]]=mne[mnp[t]]=0;
            }
        ans=ans*q%modu;
        cout<<ans<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/