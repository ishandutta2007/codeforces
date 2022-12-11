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
//const int MOD = (int) 998244353;
int MOD = 998244353;
const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1e6 + 20;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL mod = MOD)
{
    if(n < 0) a = fp(a, mod - 2, mod), n = -n;
    LL res = 1; for(; n; n >>= 1, a = a * a % mod) if(n & 1) res = res * a % mod; return res;
}

struct Mint
{
    LL x;
    Mint() {x = 0;}
    Mint(int _x): x(_x) {}
    Mint(LL _x): x(_x) {}
    Mint operator - () const{
        return Mint(MOD - x);
    }
    Mint operator + (const Mint &rhs) const{
        LL res = x + rhs.x; if(res >= MOD) res -= MOD; return Mint(res);
    }
    Mint operator - (const Mint &rhs) const{
        LL res = x - rhs.x; if(res < 0) res += MOD; return Mint(res);
    }
    Mint operator * (const Mint &rhs) const{
        return Mint(x * rhs.x % MOD);
    }
    Mint operator / (const Mint &rhs) const{
        return Mint(x * fp(rhs.x, -1) % MOD);
    }
    Mint& operator += (const Mint &rhs) {
        x += rhs.x; if(x >= MOD) x -= MOD; return *this;
    }
    Mint& operator *= (const Mint &rhs) {
        x = (x * rhs.x) % MOD; return *this;
    }
    bool operator == (const Mint &rhs) const{
        return x == rhs.x;
    }
    bool operator != (const Mint &rhs) const{
        return x != rhs.x;
    }
    friend ostream& operator << (ostream &out, const Mint &rhs){
        return out << rhs.x;
    }
    friend istream& operator >> (istream &in, Mint &rhs){
        return in >> rhs.x;
    }
};

int a[4][4] = {
    {4, 3, 6, 12},
    {7, 5, 9, 15},
    {14, 1, 11, 10},
    {13, 8, 16, 2},
};

int n;
int b[555][555];

void work()
{
    cin >>n;


    if(n < 3)
    {
        cout <<-1 <<endl;
        return ;
    }
    if(n == 3)
    {
        puts("1 7 9\n3 2 5\n4 8 6");
        return ;
    }

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            b[i][j] = a[i][j] - 16 + n * n;

    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        if(i & 1)
            for(int j = 4; j < n; j++)
                b[i][j] = ++cnt;
        else
            for(int j = n - 1; j >= 4; j--)
                b[i][j] = ++cnt;
    }
    for(int i = 4; i < n; i++)
    {
        if(i & 1)
            for(int j = 0; j < n; j++)
                b[i][j] = ++cnt;
        else
            for(int j = n - 1; j >= 0; j--)
                b[i][j] = ++cnt;
    }

    if(n != 4){
    if(n & 1) swap(b[n - 1][1], b[n - 1][0]);
    else swap(b[n - 1][1], b[n - 1][n - 1]);}

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j) printf(" ");
            printf("%d", b[i][j]);
        }
        printf("\n");
    }
}



int main(int argc, char **argv)
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
//    get_prime();
//    pre();
    int tc = 1;
//    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}