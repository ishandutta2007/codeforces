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
const int maxm = (int) 1.5e7 + 20;


int fac[maxm];

int n;
int a[maxn];

int cnt[maxm];

void dfs(int x)
{
    if(x == 1) return ;
    int f = fac[x];
    while(x % f == 0) x /= f;
    cnt[f]++;
    dfs(x);
}

void work()
{
    for(int i = 2; i < maxm; i++) if(fac[i] == 0)
    {
        fac[i] = i;
        if((LL) i * i < maxm)
            for(int j = i * i; j < maxm; j += i)
                if(fac[j] == 0)
                    fac[j] = i;
    }

    read(n);
    int g = 0;
    for(int i = 0; i < n; i++)
    {
        read(a[i]);
        g = __gcd(g, a[i]);
    }

    for(int i = 0; i < n; i++)
        dfs(a[i] / g);

    int ans = n - *max_element(cnt, cnt + maxm);

    if(ans == n) ans = -1;
    cout <<ans <<endl;
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