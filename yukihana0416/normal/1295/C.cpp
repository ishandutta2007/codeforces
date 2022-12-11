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
const int MOD = (int) 1e9 + 7;
//const int MOD = (int) 998244353;
const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1e6 + 20;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL m = MOD) {LL res = 1; for(; n; n >>= 1, a = a * a % m) if(n & 1) res = res * a % m; return res;}

int n, m;
char s[maxn], t[maxn];
vector<int> c[26];

void work()
{
    cin >>(s + 1) >>(t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);

    for(int i = 0; i < 26; i++) c[i].clear();

    for(int i = 1; i <= n; i++)
    {
        int ch = s[i] - 'a';
        c[ch].pb(i);
    }

    int ans = 1, pos = 1;
    for(int i = 1; i <= m; i++)
    {
        int ch = t[i] - 'a';

        if(c[ch].size() == 0)
        {
            cout <<-1 <<endl;
            return ;
        }

        auto ptr = lower_bound(c[ch].begin(), c[ch].end(), pos);
        if(ptr == c[ch].end())
        {
            pos = 1;
            ans++;
            i--;
        }
        else
        {
            pos = *ptr + 1;
        }
    }

    cout <<ans <<endl;
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