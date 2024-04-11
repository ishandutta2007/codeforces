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


#define maxh 19
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

int sz;
int up[maxn],dep[maxn];
int F[maxh][maxn],* const fa=F[0];
int ch[maxn][2];

LL base1=3,modu1=998244353;
LL base2=31,modu2=1e9+7;
LL pw1[maxn],pw2[maxn];
LL h1[maxh][maxn],h2[maxh][maxn];

int ins(int k,int c)    {
    if (!ch[k][c])  {
        int &s=ch[k][c];
        s=++sz;
        fa[s]=k;
        up[s]=c;
        dep[s]=dep[k]+1;
        h1[0][s]=h2[0][s]=c;
        for (int j=1;j<maxh;++j)    {
            F[j][s]=F[j-1][F[j-1][s]];
            h1[j][s]=(h1[j-1][s]*pw1[1<<j-1]+h1[j-1][F[j-1][s]])%modu1;
            h2[j][s]=(h2[j-1][s]*pw2[1<<j-1]+h2[j-1][F[j-1][s]])%modu2;
        }
    }
    return ch[k][c];
}

void pr(int k)  {
    for (;k;k=fa[k])
        cout<<"()"[up[k]];
    cout<<endl;
}

bool issmaller(int u,int v) {
    // pr(u);
    // pr(v);
    for (int h=maxh-1;h>=0;--h) {
        if ((1<<h)>dep[u]||(1<<h)>dep[v]) continue;
        if (h1[h][u]==h1[h][v]&&h2[h][u]==h2[h][v]) {
            // dbg(h,h1[h][u],h1[h][v]);
            u=F[h][u],v=F[h][v];
        }
    }
    // dbg(u,v,up[u],up[v]);
    // pr(u);
    // pr(v);
    return up[u]<up[v];
}

int n;
char s[maxn];

int stk[maxn],tp;
int dp[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    for (int i=pw1[0]=1;i<maxn;++i) pw1[i]=pw1[i-1]*base1%modu1;
    for (int i=pw2[0]=1;i<maxn;++i) pw2[i]=pw2[i-1]*base2%modu2;
    up[0]=-1;

    cin>>s+1;
    n=strlen(s+1);
    for (int i=n;i;--i) {
        dp[i]=ins(dp[i+1],s[i]-'(');
        if (s[i]=='(')    {
            if (tp) {
                int j=stk[tp--]+1;
                // dbg(i,j);
                if (issmaller(dp[j],dp[i]))
                    dp[i]=dp[j];
            }
        } else {
            stk[++tp]=i;
        }
        // dbg(i,tp,dp[i]);
        // pr(dp[i]);
    }
    pr(dp[1]);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/