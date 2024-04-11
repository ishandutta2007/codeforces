#include <bits/stdc++.h>
using namespace std;

#define LL long long
//#define LL __int64
typedef pair<int, int> pii;
typedef pair<LL, LL> pLL;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;

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
template < typename T, typename ...Args > inline void read(T &x, Args &...args) {read(x); read(args...);}

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
#define mt make_tuple
#define pb push_back
#define all(a) a.begin(),a.end()

const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
const int e5 = (int) 1e5 + 5;
//const int MOD = (int) 1e9 + 7;
const int MOD = (int) 1000000007;
//const int MOD = 998244353;

template< typename T0, typename T1 > inline void depair(T0 &x, T1 &y, pair<T0, T1> &p) {x = p.fi, y = p.se;}
inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL mod = MOD)
{
    if(n < 0) a = fp(a, mod - 2, mod), n = -n;
    LL res = 1; for(; n; n >>= 1, a = a * a % mod) if(n & 1) res = res * a % mod; return res;
}

struct Mint
{
    int x;
    Mint() {x = 0;}
    Mint(int _x): x(_x) {if(x < 0 || x >= MOD) x = (x % MOD + MOD) % MOD;}
    Mint(LL _x): x(_x) {if(x < 0 || x >= MOD) x = (x % MOD + MOD) % MOD;}
    Mint operator - () const{
        return Mint(MOD - x);
    }
    Mint operator + (const Mint &rhs) const{
        return Mint(x + rhs.x >= MOD ? x + rhs.x - MOD : x + rhs.x);
    }
    Mint operator - (const Mint &rhs) const{
        return Mint(x - rhs.x < 0 ? x - rhs.x + MOD : x - rhs.x);
    }
    Mint operator * (const Mint &rhs) const{
        return Mint((LL)x * rhs.x % MOD);
    }
    Mint operator / (const Mint &rhs) const{
        return Mint(x * fp(rhs.x, -1) % MOD);
    }
    Mint& operator += (const Mint &rhs) {
        x += rhs.x; if(x >= MOD) x -= MOD; return *this;
    }
    Mint& operator *= (const Mint &rhs) {
        x = ((LL)x * rhs.x) % MOD; return *this;
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


const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1e6 + 20;

void work()
{
    int n;
    cin >>n;
    vector<LL> a(n), b(n);

    for(int i = 0; i < n; i++) cin >>a[i];
    for(int i = 0; i < n; i++) cin >>b[i];

    if(a == b)
    {
        cout <<"SMALL" <<endl;
        cout <<0 <<endl;
        cout <<endl;
        return ;
    }

    vector<LL> c(b);
    reverse(all(c));

    if(a == c)
    {
        cout <<"SMALL" <<endl;
        cout <<1 <<endl;
        cout <<"R" <<endl;
        return ;
    }

    string ans = "";
    c = b;
    if(!is_sorted(all(c)))
    {
        reverse(all(c));
        ans += 'R';
    }

    if(!is_sorted(all(c)))
    {
        cout <<"IMPOSSIBLE" <<endl;
        return ;
    }

    int rf = 0;
    if(!is_sorted(all(a)))
    {
        reverse(all(a));
        rf = 1;
    }

    for(int ti = 1; n > 3 || ti < 2e6; ti++)
    {
        for(int j = n - 1; j; j--)
            c[j] -= c[j - 1];
        ans += 'P';

//        for(auto x : c) cout <<x <<" "; cout <<endl;

        for(int j = 0; j < n; j++)
        {
            if(c[j] <= 0)
            {
                cout <<"IMPOSSIBLE" <<endl;
                return ;
            }
        }

        if(c == a)
        {
            if(rf) ans += 'R';

            if(ti <= 200000)
            {
                cout <<"SMALL" <<endl;
                reverse(all(ans));
                cout <<ans.size() <<endl;
                cout <<ans <<endl;
                return ;
            }
            else
            {
                cout <<"BIG" <<endl;
                cout <<ti <<endl;
                return ;
            }
        }

        if(!is_sorted(all(c)))
        {
            reverse(all(c));
            ans += 'R';
        }

        if(c == a)
        {
            if(rf) ans.pop_back();

            if(ti <= 200000)
            {
                cout <<"SMALL" <<endl;
                reverse(all(ans));
                cout <<ans.size() <<endl;
                cout <<ans <<endl;
                return ;
            }
            else
            {
                cout <<"BIG" <<endl;
                cout <<ti <<endl;
                return ;
            }
        }

        if(!is_sorted(all(c)))
        {
            cout <<"IMPOSSIBLE" <<endl;
            return ;
        }
    }

    if(n == 2)
    {
        LL cnt = 0;
        sort(all(a));
        sort(all(b));

        while(b[0] > a[0])
        {
            cnt += b[1] / b[0];
            b[1] %= b[0];
            swap(b[0], b[1]);
        }

    //    cout <<b[0] <<" " <<b[1] <<" " <<a[0] <<" " <<a[1] <<endl;

        if(b[0] != a[0] || b[1] < a[1] || (b[1] - a[1]) % a[0] != 0)
        {
            cout <<"IMPOSSIBLE" <<endl;
            return ;
        }

        cnt += (b[1] - a[1]) / a[0];
        cout <<"BIG" <<endl;
        cout <<cnt <<endl;
    }
    else
    {
        cout <<"IMPOSSIBLE" <<endl;
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