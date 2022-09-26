#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define FOREACH(i,t) FORE(i,t)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define wez(x) int x; CZ(x);
#define wez2(x,y) int x,y; CZ2(x,y);
#define wez3(x,y,z) int x,y,z; CZ3(x,y,z);
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
#define MOD 1000000007
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
inline void pisz (int x) { printf("%d\n", x); }

ll dp[3111][3111];

ll go(int K,int N)
{
    if (dp[K][N]!=-1) return dp[K][N];
    if (K==0)
    {
        if (N==0) return 1;
        return dp[0][N]=(N*go(0,N-1))%MOD;
    }
    if (K==1)
    {
        if (N==0) return 0;
        return dp[1][N]=(N*go(0,N))%MOD;
    }
    return dp[K][N]=(N*go(K-1,N)+(K-1)*go(K-2,N+1))%MOD;
}

bool used[3111];

int fast(vi v)
{
    int n=v.sz;
    REP(i,1,n)used[i]=0;
    FOR(i,n) if (v[i]!=-1) used[v[i]]=1;
    int K=0,N=0;
    REP(i,1,n) if (!used[i])
    {
        if (v[i-1]==-1) K++;
        else N++;
    }
    return go(K,N);
}


int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,2111)FOR(j,2111)dp[i][j]=-1;
    int n;cin>>n;
    vi v(n);
    FOR(i,n) cin>>v[i];
    cout<<fast(v);

    return 0;
}