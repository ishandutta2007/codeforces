#include <iostream>
#include <cstring>
#include <cmath>
#define MAXNODES 200000
#define MAXLVL 19
#define forn(i, n) for(int i=0; i<n; i++)
using namespace std;


long long dp[MAXNODES];
long long vec[MAXLVL][(1<<(MAXLVL+1))];
long long mn(int i, int j)
{
    int p=31-__builtin_clz(j-i);
    return min(vec[p][i], vec[p][j-(1<<p)]);
}

void mn_init(int n)
{
    int mp=31-__builtin_clz(n);
    forn(p, mp) forn(x, n-(1<<p)) vec[p+1][x] = min(vec[p][x], vec[p][x+(1<<p)]);
}

/*long long abs(long long x)
{
    return ((x<0)?-x:x);
}*/

int main()
{
    //freopen("C.in","r",stdin);
    long long n, m, d;
    cin >> n >> m >> d;

    memset(dp, 0, sizeof(dp));
    long long st=1, ans=0;
    for(int j=0; j<m; j++)
    {
        long long a, b, t;
        cin >> a >> b >> t;
        a--;
        ans+=b;
        for(int i=0; i<n; i++)
        {
            vec[0][i]=dp[i];
        }
        mn_init(n);
            //cerr << j << endl;

        for(long long i=0; i<n; i++)
        {
            //cout << max(i-(t-st)*d, 0LL) << " " << min(i+(t-st)*d+1LL,n) << endl;

            dp[i]=mn(max(i-(t-st)*d, 0LL), min(i+(t-st)*d+1LL,n))+abs(a-i);
        }
        st=t;
    }

    long long best=dp[0];
    for(int i=0; i<n; i++)
        best=min(best, dp[i]);
    cout << ans-best << endl;
}