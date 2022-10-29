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

void Parr(int *arr,int L,int R) {
    for (int i=L;R>=i;i++) {
        printf("%d%c",arr[i]," \n"[i==R]);
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

const int N = 2e5 + 6;
const int INF = 0x3f3f3f3f;
const int mod = 1000000000 + 7;

int a[N];

vint G[N];

bool dp[2][N];

void dfs(int now,int par)
{
    vector<int> child;
    for (int i:G[now])
    {
        if (i!=par)
        {
            child.PB(i);
            dfs(i,now);
        }
    }
    if (SZ(child) == 0)
    {
        dp[1][now] = true;
        dp[0][now] = false;
    }
    else
    {
        int _1L = 0,_1R = 0;
        for (int i:child)
        {
            if (dp[0][i] && dp[1][i])
            {
                _1R++;
            }
            else if (dp[1][i])
            {
                _1L++;
                _1R++;
            }
        }
        //cout << "now = " << now << " , _L = " << _1L << " , _R = " << _1R << endl;
        if (_1R == _1L)
        {
            if (_1L % 2 == 0)
            {
                dp[1][now] = true;
                dp[0][now] = false;
            }
            else
            {
                dp[0][now] = true;
                dp[1][now] = false;
            }
        }
        else
        {
            dp[0][now] = dp[1][now] = true;
        }
    }
    //cout << "i = " << now << " , dp0 = " << dp[0][now] << " , dp1 = " << dp[1][now] << endl;
}

vint ans[2][N];

int lc[N] , rc[N];

int head[2][N], tail[2][N];

void dfs2(int now,int par)
{
    vector<int> child;
    for (int i:G[now])
    {
        if (i != par)
        {
            child.PB(i);
            dfs2(i,now);
        }
    }
    if (SZ(child) == 0)
    {
        head[1][now] = tail[1][now] = now;
        //ans[1][now].PB(now);
    }
    else
    {
        int _1L = 0,_1R = 0;
        for (int i:child)
        {
            if (dp[0][i] && dp[1][i])
            {
                _1R++;
            }
            else if (dp[1][i])
            {
                _1L++;
                _1R++;
            }
        }
        //cout << "now = " << now << " , _L = " << _1L << " , _R = " << _1R << endl;
        if (_1R == _1L)
        {
            //cout << "_1L = " << _1L << endl;
            if (_1L % 2 == 0)
            {
                /*
                dp[1][now] = true;
                dp[0][now] = false;
                */
                int last = -1;
                for (int i:child)
                {
                    if (!dp[1][i])
                    {
                        if (last == -1)
                        {
                            head[1][now] = head[0][i];
                            last = tail[0][i];
                        }
                        else
                        {
                            int _ = head[0][i];
                            rc[last] = _;
                            lc[_] = last;
                            last = tail[0][i];
                        }
                        //for (int j:ans[0][i]) ans[1][now].PB(j);
                    }
                }
                if (last == -1)
                {
                    head[1][now] = now;
                    last = now;
                }
                else
                {
                    int _ = now;
                    rc[last] = now;
                    lc[_] = last;
                    last = now;
                }
                //ans[1][now].PB(now);
                for (int i:child)
                {
                    if (dp[1][i])
                    {
                        int _ = head[1][i];
                        rc[last] = _;
                        lc[_] = last;
                        last = tail[1][i];
                        //for (int j:ans[1][i]) ans[1][now].PB(j);
                    }
                }
                tail[1][now] = last;
            }
            else
            {
                /*
                dp[0][now] = true;
                dp[1][now] = false;
                */
                /*
                for (int i:child)
                {
                    if (!dp[1][i])
                    {
                        for (int j:ans[0][i]) ans[0][now].PB(j);
                    }
                }
                ans[0][now].PB(now);
                for (int i:child)
                {
                    if (dp[1][i])
                    {
                        for (int j:ans[1][i]) ans[0][now].PB(j);
                    }
                }
                */
                int last = -1;
                for (int i:child)
                {
                    if (!dp[1][i])
                    {
                        if (last == -1)
                        {
                            head[0][now] = head[0][i];
                            last = tail[0][i];
                        }
                        else
                        {
                            int _ = head[0][i];
                            rc[last] = _;
                            lc[_] = last;
                            last = tail[0][i];
                        }
                        //for (int j:ans[0][i]) ans[1][now].PB(j);
                    }
                }
                if (last == -1)
                {
                    head[0][now] = now;
                    last = now;
                }
                else
                {
                    int _ = now;
                    rc[last] = now;
                    lc[_] = last;
                    last = now;
                }
                //ans[1][now].PB(now);
                for (int i:child)
                {
                    if (dp[1][i])
                    {
                        int _ = head[1][i];
                        rc[last] = _;
                        lc[_] = last;
                        last = tail[1][i];
                        //for (int j:ans[1][i]) ans[1][now].PB(j);
                    }
                }
                tail[0][now] = last;
            }
        }
        else
        {
            vint child1,child2;
            vint choice;
            for (int i:child)
            {
                if (dp[0][i] && dp[1][i])
                {
                    choice.PB(i);
                }
                else if (dp[1][i])
                {
                    child1.PB(i);
                    child2.PB(i);
                }
            }
            if (SZ(child1) % 2 == 1)
            {
                child1.PB(choice[0]);
            }
            else if (SZ(child1) % 2 == 0)
            {
                child2.PB(choice[0]);
            }
            //child2 --> odd
            //dp[0][now] = dp[1][now] = true;
            /*
            for (int i:child2)
            {
                if (!dp[1][i])
                {
                    for (int j:ans[0][i]) ans[1][now].PB(j);
                }
            }
            ans[1][now].PB(now);
            for (int i:child2)
            {
                if (dp[1][i])
                {
                    for (int j:ans[1][i]) ans[0][now].PB(j);
                }
            }
            */
            int last = -1;
            for (int i:child2)
            {
                if (!dp[1][i])
                {
                    if (last == -1)
                    {
                        head[1][now] = head[0][i];
                        last = tail[0][i];
                    }
                    else
                    {
                        int _ = head[0][i];
                        rc[last] = _;
                        lc[_] = last;
                        last = tail[0][i];
                    }
                    //for (int j:ans[0][i]) ans[1][now].PB(j);
                }
            }
            if (last == -1)
            {
                head[1][now] = now;
                last = now;
            }
            else
            {
                int _ = now;
                rc[last] = now;
                lc[_] = last;
                last = now;
            }
            //ans[1][now].PB(now);
            for (int i:child2)
            {
                if (dp[1][i])
                {
                    int _ = head[1][i];
                    rc[last] = _;
                    lc[_] = last;
                    last = tail[1][i];
                    //for (int j:ans[1][i]) ans[1][now].PB(j);
                }
            }
            tail[1][now] = last;
            /*
            for (int i:child1)
            {
                if (!dp[1][i])
                {
                    for (int j:ans[0][i]) ans[0][now].PB(j);
                }
            }
            ans[0][now].PB(now);
            for (int i:child1)
            {
                if (dp[1][i])
                {
                    for (int j:ans[1][i]) ans[0][now].PB(j);
                }
            }
            */
            last = -1;
            for (int i:child1)
            {
                if (!dp[1][i])
                {
                    if (last == -1)
                    {
                        head[0][now] = head[0][i];
                        last = tail[0][i];
                    }
                    else
                    {
                        int _ = head[0][i];
                        rc[last] = _;
                        lc[_] = last;
                        last = tail[0][i];
                    }
                    //for (int j:ans[0][i]) ans[1][now].PB(j);
                }
            }
            if (last == -1)
            {
                head[0][now] = now;
                last = now;
            }
            else
            {
                int _ = now;
                rc[last] = now;
                lc[_] = last;
                last = now;
            }
            //ans[1][now].PB(now);
            for (int i:child1)
            {
                if (dp[1][i])
                {
                    int _ = head[1][i];
                    rc[last] = _;
                    lc[_] = last;
                    last = tail[1][i];
                    //for (int j:ans[1][i]) ans[1][now].PB(j);
                }
            }
            tail[0][now] = last;
        }
    }
    /*cout << "now = " << now << " , dp0 = " << dp[0][now] << " , dp1 = " << dp[1][now] << endl;
    cout << "ans[0] --> "; Pvec(ans[0][now]); cout << endl;
    cout << "ans[1] --> "; Pvec(ans[1][now]); cout << endl;*/
    /*
    for (int i:child)
    {
        vint ().swap(ans[0][i]);
        vint ().swap(ans[1][i]);
    }
    */
}

int main () {
    srand(time(NULL));
    int n;
    Si(n);
    REP1(i,n)
    {
        int p;
        Si(p);
        if (p)
        {
            G[i].PB(p);
            G[p].PB(i);
        }
    }
    dfs(1,1);
    if (!dp[1][1])
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i=1;n>=i;i++)
    {
        lc[i] = rc[i] = i;
    }
    dfs2(1,1);
    int start = -1;
    for (int i=1;n>=i;i++)
    {
        if (lc[i] == i)
        {
            start=i;
            break;
        }
    }
    /*
    for (int i=1;n>=i;i++)
    {
        cout << "i = " << i << " , lc = " << lc[i] << " , rc = " << rc[i] << endl;
    }
    */
    assert(start != -1);
    for (int i=1;n>=i;i++)
    {
        printf("%d\n",start);
        start = rc[start];
    }
    /*
    for (int i:ans[1][1])
    {
        printf("%d\n",i);
    }
    */
    //cout << dp[1][1] << endl;
}