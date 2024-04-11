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

int n, k, s;
int a[1111];

void work()
{
    cin >>n >>k >>s;
    for(int i = 0; i < s; i++) cin >>a[i];

    set<int> st;
    for(int i = 0; i < s; i++) st.insert(a[i]);

    int ans = n;
    for(int i = max(1, k - 1001); i <= min(n, k + 1001); i++)
    {
        if(st.find(i) == st.end()) ans = min(ans, abs(k - i));
    }
    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
#endif // yukihana0416

    int tc = 1;
    read(tc);

    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}