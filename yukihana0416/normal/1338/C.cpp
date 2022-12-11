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
const int e5 = (int) 1e5 + 5;
const int maxn = (int) 1e5 + 20;
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

//void work()
//{
//    set<int> s;
//
//    for(int t = 1; t <= 30; t++)
//    {
//        int x = 1;
//        while(s.find(x) != s.end()) x++;
//
//        int y = x + 1;
//        while(s.find(y) != s.end() || s.find(x ^ y) != s.end()) y++;
//
//        int z = x ^ y;
//        cout <<"t : " <<t <<endl;
//
//
//        s.insert(x);
//        s.insert(y);
//        s.insert(z);
//        cout <<x <<" " <<y <<" " <<z <<endl;
//
//        stack<int> st;
//        while(x != 0) st.push(x & 1), x >>= 1;
//        while(!st.empty()) cout <<st.top(), st.pop(); cout <<" ";
//
//        while(y != 0) st.push(y & 1), y >>= 1;
//        while(!st.empty()) cout <<st.top(), st.pop(); cout <<" ";
//
//        while(z != 0) st.push(z & 1), z >>= 1;
//        while(!st.empty()) cout <<st.top(), st.pop(); cout <<endl;
//    }
//}

void work()
{
    LL x; read(x);

    LL y = (x - 1) / 3 + 1;
    int d = (x - 1) % 3;

    LL cc = 1;
    int cnt = 0;
    while(y > cc)
    {
        y -= cc;
        cc *= 4;
        cnt++;
    }

    LL a = 0, b = 0, c;
    a |= 1LL << (cnt * 2);
    b |= 2LL << (cnt * 2);

    y--;

    for(int i = 0; i < cnt; i++)
    {
        if(y % 4 == 0)
        {
            ;
        }
        else if(y % 4 == 1)
        {
            a |= 1LL << (i * 2);
            b |= 2LL << (i * 2);
        }
        else if(y % 4 == 2)
        {
            a |= 2LL << (i * 2);
            b |= 3LL << (i * 2);
        }
        else
        {
            a |= 3LL << (i * 2);
            b |= 1LL << (i * 2);
        }
        y /= 4;
    }

    c = a ^ b;

    if(d == 0) cout <<a <<endl;
    else if(d == 1) cout <<b <<endl;
    else cout <<c <<endl;
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