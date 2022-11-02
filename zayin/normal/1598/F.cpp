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

#define maxn 21
#define maxs 2000050
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
int a[maxn],b[maxn];
vector<int> con[maxn];

int stk[maxs],tp;

int sum[maxs],dp[maxs];

int getcon(int i,int j) {
    if (j<con[i].size())
        return con[i][j];
    return 0;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin>>n;
    rep(i,0,n)  {
        string s;
        cin>>s;
        con[i].resize(s.size()+1);

        tp=0;
        rep(j,0,s.size())  {
            if (s[j]==')'&&tp&&s[stk[tp]]=='(')
                --tp;
            else
                stk[++tp]=j;
            if (tp&&s[stk[tp]]=='(') continue;
            // cout<<"add con["<<i<<"]["<<tp<<"] ~ "<<j<<endl;
            ++con[i][tp];
        }

        // cout<<s<<" ~ ";
        for (;tp;--tp)  {
            // cout<<s[stk[tp]];
            if (s[stk[tp]]=='(')
                ++b[i];
            else
                ++a[i];
        }
        // cout<<endl;
        // dbg(i,a[i],b[i]);
    }

    memset(dp,0xc0,sizeof(dp));
    dp[0]=sum[0]=0;

    int ans=0;
    for (int s=0;s<(1<<n);++s)  {
        for (int i=0;i<n;++i)   {
            if (~s>>i&1) continue;
            int t=s^(1<<i);
            sum[s]=sum[t]-a[i]+b[i];
            if (sum[t]<a[i]) continue;
            dp[s]=max(dp[s],dp[t]+getcon(i,sum[t]));
        }
        for (int i=0;i<n;++i)   
            if (~s>>i&1)    {
                ans=max(ans,dp[s]+getcon(i,sum[s]));
            }
    }

    cout<<ans<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/