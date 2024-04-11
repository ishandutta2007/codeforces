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
int a[maxn];

struct BitTree
{
    int N;
    int T[maxn];

    void init(int n)
    {
        N = n;
        for(int i = 1; i <= N; i++) T[i] = 0;
    }
    void add(int pos, int val)
    {
        for(int i = pos; i <= N; i += lowbit(i))
            T[i] += val;
    }
    int sum(int pos)
    {
        int res = 0;
        for(int i = pos; i; i -= lowbit(i))
            res += T[i];
        return res;
    }
}vis, pre;

int precnt[maxn];
int prepos[maxn];
int ans[maxn][2];


void work()
{
    read(n), read(m);
    for(int i = 1; i <= m; i++)
        read(a[i]);

    vis.init(n);
    pre.init(m + 1);

    for(int i = 1; i <= n; i++)
    {
        precnt[i] = 0;
        prepos[i] = 0;
        ans[i][0] = ans[i][1] = i;
    }

    for(int i = 1; i <= m; i++)
    {
        int x = a[i];

        if(prepos[x])
        {
            int t = pre.sum(prepos[x] + 1);
            ans[x][1] = max(ans[x][1], t - precnt[x] + 1);

            pre.add(prepos[x] + 1, 1);
            prepos[x] = i;
            precnt[x] = pre.sum(i + 1);
        }
        else
        {
            pre.add(prepos[x] + 1, 1);
            prepos[x] = i;
            precnt[x] = pre.sum(i + 1);

            vis.add(x, 1);
            ans[x][0] = 1;
            ans[x][1] = vis.sum(n) - vis.sum(x) + x;

        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(prepos[i])
        {
            int t = pre.sum(prepos[i] + 1);

            ans[i][1] = max(ans[i][1], t - precnt[i] + 1);
        }
        else
        {
            ans[i][1] = vis.sum(n) - vis.sum(i) + i;
        }
    }

    for(int i = 1; i <= n; i++)
        printf("%d %d\n", ans[i][0], ans[i][1]);
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