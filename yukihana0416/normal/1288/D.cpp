#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define lowbit(x) ((x) & -(x))
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define MID(l, r) (((l)+(r))>>1)
#define fi first
#define se second

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int maxn = (int) 3e5 + 20;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const double eps = 1e-8;


template < typename T > inline void read(T &x)
{
    static bool f;
    static char ch;

    f = 0;
    x = 0;
    ch = getchar();

    while(ch < '0' || '9' < ch) {if(ch == '-') f = 1; ch = getchar();}
    while('0' <= ch && ch <= '9') {x = (x << 3) + (x << 1) + (ch & 15); ch = getchar();}

    if(f) x = -x;
}

LL gcd(LL a, LL b) {if(!b) return a; return gcd(b, a % b);}
LL fp(LL a, LL n, LL m = MOD) {LL res; for(res = 1; n; a = a * a % m, n >>= 1) if(n & 1) res = res * a % m; return res;}

template <typename T> inline T minx(T a, T b) {if(a < b) return a; return b;}
template <typename T> inline T maxx(T a, T b) {if(a < b) return b; return a;}

int n, m;
int a[maxn][8];

int tx, ty;

int b[1 << 8];

int func(int x)
{
    for(int i = 0; i < (1 << m); i++) b[i] = 0;

    for(int i = 1; i <= n; i++)
    {
        int s = 0;
        for(int j = 0; j < m; j++)
            s |= (a[i][j] >= x) << j;

        b[s] = i;
    }
    for(int i = 0; i < (1 << m); i++)
    {
        if(!b[i]) continue;
        for(int j = i; j < (1 << m); j++)
        {
            if(!b[j]) continue;
            if((i | j) == (1 << m) - 1)
            {
                tx = b[i];
                ty = b[j];
                return 1;
            }
        }
    }
    return 0;
}

void work()
{
    read(n), read(m);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            read(a[i][j]);

    int l = 0, r = 1e9, mid, res;
    while(l <= r)
    {
        mid = MID(l, r);
        if(func(mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout <<tx <<" " <<ty <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
#endif // yukihana0416

    int tc = 1;
//    read(tc);

    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}