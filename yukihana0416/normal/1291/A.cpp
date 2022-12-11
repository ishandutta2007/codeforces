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
char s[maxn];

void work()
{
    cin >>n >>s;

    while(n && s[n - 1] % 2 == 0) n--;

    if(n == 0)
    {
        cout <<-1 <<endl;
        return ;
    }

    int tot = 0;
    for(int i = 0; i < n; i++)
        tot ^= s[i] & 1;

    if(tot == 1)
    {
        int id = -1;
        for(int i = 0; i < n - 1; i++) if(s[i] & 1)
            if(i == 0)
            {
                if(s[i + 1] != '0')
                {
                    id = i;
                    break;
                }
            }
            else
            {
                id = i;
                break;
            }

        if(id == -1)
        {
            cout <<-1 <<endl;
            return ;
        }

        for(int i = 0; i < n; i++)
            if(i == id) continue;
            else cout <<s[i];
        cout <<endl;
    }
    else
    {
        s[n] = 0;
        cout <<s <<endl;
    }
}

int main(int argc, char **argv)
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
//    get_prime();
    int tc = 1;
    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}