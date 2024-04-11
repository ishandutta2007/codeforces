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
const int e5 = (int) 1e5 + 5;
const int MOD = (int) 1e9 + 7;
//const int MOD = (int) 998244353;
//int MOD = 998244353;

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
    vector< vector<int> > seg(n - 1);

    for(auto &s : seg)
    {
        int k; read(k);
        s = vector<int> (k);
        for(auto &x : s)  read(x);
    }

//    for(auto s : seg)
//    {
//        for(auto x : s) cout <<x <<" ";
//        cout <<endl;
//    }

    vector<int> p(n + 1), idx(n + 1);

    for(p[1] = 1; p[1] <= n; p[1]++)
    {
        fill(idx.begin(), idx.end(), 0);
        idx[p[1]] = 1;

        int flag = 1;
        for(int i = 2; i <= n; i++)
        {
            p[i] = 0;

            flag = 0;
            for(auto s : seg)
            {
                if(s.size() > i) continue;
                int cnt = 0, q, mi = i;

                for(auto x : s)
                {
                    if(idx[x] == 0) cnt++, q = x;
                    else Min(mi, idx[x]);
                }

                if(cnt == 1 && mi == i + 1 - s.size())
                {
                    flag = 1;
                    p[i] = q;
                    idx[q] = i;
                    break;
                }
            }


            if(flag == 0) break;
        }

        if(flag) break;
    }

    for(int i = 1; i <= n; i++)
        cout <<p[i] <<" \n"[i == n];
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
    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}