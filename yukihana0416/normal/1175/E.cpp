#include <bits/stdc++.h>
using namespace std;
#define LL long long

template< typename T > inline void read(T &x)
{
    static char _c;
    static bool _f;

    x = 0;
    _f = 0;
    _c = getchar();

    while(_c < '0' || '9' < _c) {if(_c == '-') _f = true; _c = getchar();}
    while('0' <= _c && _c <= '9') {x = x * 10 + _c - '0'; _c = getchar();}
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

const int MOD = (int) 1e9 + 7;
const int inf = (int) 1e9;
const int maxn = (int) 3e5 + 20;
const int maxm = (int) 5e5 + 20;


int n, m;
int dp[maxm][21];

void work()
{
    read(n), read(m);

    int inf = 5e5;

    for(int i = 0; i <= inf; i++) dp[i][0] = i;

    for(int i = 0; i < n; i++)
    {
        int l, r;
        read(l), read(r);
        Max(dp[l][0], r);
    }

    for(int i = 1; i <= inf; i++) Max(dp[i][0], dp[i - 1][0]);

    for(int j = 1; j <= 20; j++)
        for(int i = 0; i <= inf; i++)
            Max(dp[i][j], dp[dp[i][j - 1]][j - 1]);

    for(int i = 0; i < m; i++)
    {
        int l, r;
        read(l), read(r);

        if(dp[l][20] < r) puts("-1");
        else
        {
            int ans = 0;
            for(int j = 20; ~j; j--)
                if(dp[l][j] < r)
                    ans |= (1 << j), l = dp[l][j];
            printf("%d\n", ans + 1);
        }
    }
}


int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    int tc = 1;
//    cin >>tc;
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}