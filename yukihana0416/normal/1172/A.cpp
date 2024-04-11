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

const int MOD = (int) 1e9 + 7;
const int inf = (int) 1e9;
const int maxn = (int) 2e5 + 20;
const int maxm = (int) 5e5 + 20;

int n;
int a[maxn], b[maxn];

int check()
{
    int pos = -1;
    for(int i = 1; i <= n; i++)
    {
        if(b[i] == 1)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1) return 0;

    for(int i = 0; i + pos <= n; i++)
    {
        if(b[i + pos] != i + 1) return 0;
    }

    return 1;
}


void work()
{
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);
    for(int i = 1; i <= n; i++) read(b[i]);

    if(check())
    {
        int mn = 0;
        int last = b[n];
        for(int i = 1; i <= n; i++)
        {
            if(b[i] == 1) break;
            if(b[i] == 0) continue;

            Min(mn, b[i] - last - i - 1);
        }

        if(mn == 0)
        {
            cout <<(n - last) <<endl;
            return ;
        }
    }

    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        if(b[i] == 0) continue;
        Max(mx, i - b[i] + 1);
    }

    cout <<mx + n <<endl;
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