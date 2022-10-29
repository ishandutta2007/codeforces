#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long      LL;
typedef long double    ld;
typedef pair<int,int>  pii;
typedef pair<LL,LL>    pLL;
typedef vector<int>    vint;
typedef vector<LL>     vLL;
typedef vector<pii>    vpii;
typedef vector<pLL>    vpLL;

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back

#define Si(x) scanf("%d",&(x));
#define Sii(x,y) scanf("%d %d",&(x),&(y));
#define Siii(x,y,z) scanf("%d %d %d",&(x),&(y),&(z));
#define Siiii(x,y,z,w) scanf("%d %d %d %d",&(x),&(y),&(z),&(w));
#define Siiiii(x,y,z,w,a) scanf("%d %d %d %d %d",&(x),&(y),&(z),&(w),&(a));
#define Siiiiii(x,y,z,w,a,b) scanf("%d %d %d %d %d %d",&(x),&(y),&(z),&(w),&(a),&(b));
#define SL(x) scanf("%lld",&(x));
#define SLL(x,y) scanf("%lld %lld",&(x),&(y));
#define SLLL(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
#define SLLLL(x,y,z,w) scanf("%lld %lld %lld %lld",&(x),&(y),&(z),&(w));
#define SLLLLL(x,y,z,w,a) scanf("%lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a));
#define SLLLLLL(x,y,z,w,a,b) scanf("%lld %lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a),&(b));

#define Pi(x) printf("%d\n",(x));
#define Pii(x,y) printf("%d %d\n",(x),(y));
#define Piii(x,y,z) printf("%d %d %d\n",(x),(y),(z));
#define Piiii(x,y,z,w) printf("%d %d %d %d\n",(x),(y),(z),(w));
#define Piiiii(a,b,c,d,e) printf("%d %d %d %d %d\n",(a),(b),(c),(d),(e));
#define Piiiiii(a,b,c,d,e,f) printf("%d %d %d %d %d %d\n",(a),(b),(c),(d),(e),(f));
#define PL(x) printf("%lld\n",(x)*1LL);
#define PLL(x,y) printf("%lld %lld\n",(x)*1LL,(y)*1LL);
#define PLLL(x,y,z) printf("%lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL);
#define PLLLL(x,y,z,w) printf("%lld %lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL,(w)*1LL);
#define PLLLLL(a,b,c,d,e) printf("%lld %lld %lld %lld %lld\n",(a)*1LL,(b)*1LL,(c)*1LL,(d)*1LL,(e)*1LL);
#define PLLLLLL(a,b,c,d,e,f) printf("%lld %lld %lld %lld %lld %lld\n",(a)*1LL,(b)*1LL,(c)*1LL,(d)*1LL,(e)*1LL,(f)*1LL);

#define Pi1(x) printf("%d",  (x));
#define PL1(x) printf("%lld",(x));
#define Pspace putchar(' ');
#define Pendl  puts("");

#define MEM0(x) memset( (x), 0, sizeof( (x) ) )
#define MEM1(x) memset( (x),-1, sizeof( (x) ) )
#define REP1(i,n)  for (int i = 1; (n) >= i ; ++i)
#define REP0(i,n)  for (int i = 0; (n) >  i ; ++i)

#define IOS ios::sync_with_stdio(0); cin.tie(0);

int myRnd() {
    return abs(  ((rand()<<15) ^ rand()) );
}

int myRnd(int L,int R) {
    return abs(( (rand()<<15)^rand() ) ) % (R-L+1) + L;
}

void Parr(LL *arr,int L,int R) {
    for (int i=L;R>=i;i++) {
        printf("%lld%c",arr[i]," \n"[i==R]);
    }
}

void Pvec(vint v) {
    for (int i=0;SZ(v)>i;i++) {
        printf("%d%c",v[i]," \n"[i==SZ(v)-1]);
    }
}

void Sarr(int *arr,int L,int R) {
    for (int i=L;R>=i;i++)
    {
        Si(arr[i]);
    }
}

const int N = 5000 + 16;
const int INF_int = 0x3f3f3f3f;
const int mod = 1000000000 + 7;
const LL INF = (1LL<<50);

int a[N];
LL dp[N][N];
LL mx[N][N];
LL ans[N];

int main () {
    srand(time(NULL));
    int n;
    Si(n);
    Sarr(a,1,n);
    int tar=((n+1)>>1);
    a[0] = INF_int;
    a[n+1] = 0;
    for (int i=0;n>=i;i++)
    {
        for (int j=1;tar+1>=j;j++)
        {
            mx[i][j] =INF;
        }
        ans[i] = INF;
    }
    REP1(i,n)
    {
        REP1(j,tar)
        {
            if (i < j*2-1)
            {
                dp[i][j] = INF;
                continue;
            }
            if (i == 1 && j == 1)
            {
                dp[1][1] = 0;
                if (i == n)
                {
                    ans[j] = min(ans[j],dp[i][j]);
                }
                else
                {
                    ans[j] = min(ans[j],dp[i][j]+max(0,a[i+1]-a[i]+1));
                }
                mx[i+1][j] = min(mx[i][j], dp[i][j]+max(0,a[i+1]-a[i]+1) );
                continue;
            }
            dp[i][j] = dp[i-2][j-1] + max(0,a[i-1]- (min(  a[i-2]  ,a[i])-1) );
            dp[i][j] = min(dp[i][j],mx[i-2][j-1] + max(0,a[i-1]-a[i]+1));
            mx[i+1][j] = min(mx[i][j], dp[i][j]+max(0,a[i+1]-a[i]+1) );
            if (i == n)
            {
                ans[j] = min(ans[j],dp[i][j]);
            }
            else
            {
                ans[j] = min(ans[j],dp[i][j]+max(0,a[i+1]-a[i]+1));
            }
        }
    }
    ans[0] = 0;
    for (int i=tar;i>=1;i--)
    {
        assert(ans[i]>=ans[i-1]);
        ans[i-1] = min(ans[i-1],ans[i]);
    }
    Parr(ans,1,tar);
}