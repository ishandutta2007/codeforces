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
const int maxn = (int) 2e5 + 20;
const int maxm = (int) 5e5 + 20;

int n, k;
int a[maxn];

void work()
{
    read(n);
    read(k);
    for(int i = 0; i < n; i++) read(a[i]);

    int ans = 2e9, pos = -1;
    for(int i = 0; i < n - k; i++)
    {
        int l = a[i], r = a[i + k];
        if(r - l < ans)
        {
            ans = r - l;
            pos = (l + r) >> 1;
        }
    }

    cout <<pos <<endl;
}


int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    int tc = 1;
    cin >>tc;
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}