#include <bits/stdc++.h>
using namespace std;

#define LL long long
typedef pair<int, int> pii;

template< typename T > inline void read(T &x)
{
    static char _c;
    static bool _f;

    x = 0;
    _f = 0;
    _c = getchar();

    while(_c < '0' || '9' < _c) {if(_c == '-') _f = true; _c = getchar();}
    while('0' <= _c && _c <= '9') {x = (x << 1) + (x << 3) + (_c & 15); _c = getchar();}
    if(_f) x = -x;
}

template < typename T > inline void Min(T &x, T y) {if(y < x) x = y;}
template < typename T > inline void Max(T &x, T y) {if(x < y) x = y;}


#define lowbit(x) ((x) & -(x))
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(l,r) ((l)+(((r)-(l))>>1))
#define fi first
#define se second
#define mk make_pair
#define pb push_back

const int INF = 0x3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
//const int MOD = (int) 1e9 + 7;
const int MOD = (int) 998244353;
const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1e6 + 20;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL MOD)
{
    LL res = 1;
    if(n < 0) a = fp(a, MOD - 2, MOD), n = -n;
    for(; n; n >>= 1, a = a * a % MOD) if(n & 1) res = res * a % MOD;
    return res;
}

int n;
LL a[55], b[55];
LL c[111];
int tot;
int p[55], q[55];
LL dp[55][111];

LL fac[222], ifac[222];
//LL C(int n, int m) {return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;}
LL C(int n, int m)
{
    LL res = ifac[m];
    for(int i = 0; i < m; i++)
        res = res * (n - i) % MOD;
    return res;
}

void work()
{
    fac[0] = 1;
    for(int i = 1; i <= 150; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[150] = fp(fac[150], MOD - 2, MOD);
    for(int i = 149; ~i; i--) ifac[i] = ifac[i + 1] * (i + 1) % MOD;

    cin >>n;
    for(int i = 1; i <= n; i++) cin >>a[i] >>b[i];
    for(int i = 1; i <= n; i++) b[i]++;

    tot = 0;
    for(int i = 1; i <= n; i++)
    {
        c[++tot] = a[i];
        c[++tot] = b[i];
    }

    sort(c + 1, c + 1 + tot);
    tot = unique(c + 1, c + 1 + tot) - c - 1;

    for(int i = 1; i <= n; i++)
    {
        p[i] = lower_bound(c + 1, c + 1 + tot, a[i]) - c;
        q[i] = lower_bound(c + 1, c + 1 + tot, b[i]) - c;

//        cout <<i <<" " <<p[i] <<" " <<q[i] <<endl;
    }

    for(int i = 1; i <= tot; i++) dp[0][i] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= tot; j++)
            dp[i][j] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = p[i]; j < q[i]; j++)
        {
            for(int k = i; k; k--)
            {
                if(p[k] <= j && j < q[k])
                {
//                    cout <<"C: "<<c[j + 1] - c[j] + i - k <<" " <<i - k + 1 <<" " <<C(c[j + 1] - c[j] + i - k, i - k + 1) <<endl;
                    dp[i][j] = (dp[i][j] + C(c[j + 1] - c[j] + i - k, i - k + 1) * dp[k - 1][j + 1]) % MOD;
                }
                else
                {
                    break;
                }
            }
        }

//        for(int j = 1; j <= tot; j++) cout <<dp[i][j] <<" "; cout <<endl;

        for(int j = tot - 1; j; j--)
            dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
    }

    LL res = dp[n][1];
    for(int i = 1; i <= n; i++)
        res = res * fp(b[i] - a[i], MOD - 2, MOD) % MOD;

    cout <<res <<endl;
}

int main(int argc, char **argv)
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
//    get_prime();
    int tc = 1;
//    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}