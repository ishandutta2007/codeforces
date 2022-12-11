#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <cassert>

#include <iostream>

#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <utility>
#include <random>
#include <memory>
#include <bitset>
#include <string>
#include <tuple>
#include <functional>
using namespace std;

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
#define epb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

using LL = long long;
using ULL = unsigned long long;
//using LL = __int64;
//using ULL = unsigned __int64;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using pLL = pair<LL, LL>;

const double pi = acos(-1.0);
constexpr int INF = 0x3f3f3f3f;
constexpr LL LINF = 0x3f3f3f3f3f3f3f3f;
constexpr double DINF = 1e100;
constexpr double eps = 1e-8;
constexpr int e5 = 100000; // 1e5
constexpr int e6 = 1000000; //1e6;
constexpr int MOD_1e9 = 1000000007; //1e9 + 7
constexpr int MOD_998 = 998244353;
constexpr int MOD = MOD_1e9;

template< typename T > inline void get_min(T &x, T y) {if(y < x) x = y;}
template< typename T > inline void get_max(T &x, T y) {if(x < y) x = y;}
template< typename T > inline void get_unique(vector<T> &vec) {sort(all(vec)); vec.erase(unique(all(vec)), vec.end());}

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
template< typename T > inline LL fp(LL a, T n, int mod = MOD)
{
    if(n < 0) a = fp(a, mod - 2, mod), n = -n;
    LL res = 1;
    for(; n; n >>= 1, a = a * a % mod) if(n & 1) res = res * a % mod;
    return res;
}

template< int mod > class Mint
{
public:
    int x;
    Mint():x(0) {}
    Mint(int _x): x(_x) {if(x < 0 || x >= mod) x %= mod; if(x < 0) x += mod;}
    Mint(LL _x) {if(_x < 0 || _x >= mod) _x %= mod; if(_x < 0) _x += mod; x = _x;}
    Mint operator - () const {return Mint(x == 0 ? x : mod - x);}
    Mint operator + (const Mint &rhs) const {return Mint(x + rhs.x >= mod ? x + rhs.x - mod : x + rhs.x);}
    Mint operator - (const Mint &rhs) const {return Mint(x - rhs.x < 0 ? x - rhs.x + mod : x - rhs.x);}
    Mint operator * (const Mint &rhs) const {return Mint((LL)x * rhs.x % mod);}
    Mint operator / (const Mint &rhs) const {return Mint((LL)x * fp(rhs.x, -1, mod) % mod);}
    bool operator == (const Mint &rhs) const {return x == rhs.x;}
    bool operator != (const Mint &rhs) const {return x != rhs.x;}
    Mint &operator += (const Mint &rhs) {x += rhs.x; if(x >= mod) x -= mod; return *this;}
    Mint &operator -= (const Mint &rhs) {x -= rhs.x; if(x < 0) x += mod; return *this;}
    Mint &operator *= (const Mint &rhs) {x = (LL)x * rhs.x % mod; return *this;}
    Mint &operator /= (const Mint &rhs) {x = (LL)x * fp(rhs.x, -1, mod) % mod; return *this;}
    friend ostream &operator << (ostream &out, const Mint &rhs) {return out << to_string(rhs.x);}
    Mint inv() const {return Mint(fp(x, -1, mod));}
    template< typename T > Mint pow(T k) const {return Mint(fp(x, k, mod));}
};

class fast_reader
{
private:
    int buff_size;
    char *buff_ptr;
    char *ptr;
    char *tail;
    bool is_open;
    fast_reader(const fast_reader &) = delete;
    fast_reader &operator = (const fast_reader &) = delete;

    inline bool is_digit() const {return '0' <= *ptr && *ptr <= '9';}
    inline bool is_blank() const {return *ptr == ' ' || *ptr == '\n' || *ptr == '\r' || *ptr == '\0' || *ptr == '\t';}
    template <typename T> inline void read_i(T &x) {
        static bool f;
        for(f = false; ptr < tail && !is_digit(); ptr++) if(*ptr == '-') f = true;
        for(x = 0; ptr < tail && is_digit(); ptr++) x = (x << 1) + (x << 3) + (*ptr & 0xf);
        if(f) x = -x;
    }
    template <typename T> inline void read_f(T &x) {
        static char t_buff[512]; read(t_buff); x = atof(t_buff);
    }
public:
    fast_reader(): buff_size(0), buff_ptr(nullptr), ptr(nullptr), tail(nullptr), is_open(false) {}
    ~fast_reader() {if(is_open) free(buff_ptr);}
    template <typename T> fast_reader &operator >> (T &x) {read(x); return *this;}
    template <typename T, typename ...Args> inline void read(T &x, Args &...args) {read(x); read(args...);}
    inline bool is_end() {while(ptr < tail && is_blank()) ptr++; return ptr >= tail;}

    inline void open_alter(int call_size = 1 << 24) {
        if(is_open) throw runtime_error("fast reader is reopened!");
        buff_ptr = (char *) malloc(call_size);
        buff_size = fread(buff_ptr, sizeof(char), call_size, stdin);
        for(; feof(stdin) == 0; call_size <<= 1) {
            buff_ptr = (char *) realloc(buff_ptr, call_size << 1);
            buff_size += fread(buff_ptr + call_size, sizeof(char), call_size, stdin);
        }
        ptr = buff_ptr = (char *) realloc(buff_ptr, buff_size);
        tail = buff_ptr + buff_size;
        is_open = true;
    }

    inline void read(int &x) {read_i(x);}
    inline void read(unsigned int &x) {read_i(x);}
    inline void read(long long &x) {read_i(x);}
    inline void read(unsigned long long &x) {read_i(x);}
    inline void read(float &x) {read_f(x);}
    inline void read(double &x) {read_f(x);}
    inline void read(char *str) {
        while(ptr < tail && is_blank()) ptr++;
        for(; ptr < tail && !is_blank(); str++) *str = *ptr++;
        *str = '\0';
    }
    inline void read(string &s) {
        static char *pre;
        while(ptr < tail && is_blank()) ptr++;
        for(pre = ptr; ptr < tail && !is_blank(); ptr++) ;
        s = move(string(pre, ptr));
    }
}reader;

constexpr int maxn = (int) 2e5 + 5;
constexpr int maxm = (int) 1e7 + 5;

using mint = Mint<MOD_998>;

int n, m;
char s[11][11];

void work()
{
    reader >>n >>m;
    for(int i = 0; i < n; i++) reader >>s[i];

    int ans = 0;
    int x, y;
    x = 0, y = 0;
    while(1)
    {
        if(s[x][y] == '*') ans++;
        if(x == n - 1 && y == m - 1) break;

        set<pii> s;
        queue<pair<int, pii>> q;
        if(y + 1 < m) q.emplace(mk(0, mk(x, y + 1))), s.insert(mk(x, y + 1));
        if(x + 1 < n) q.emplace(mk(1, mk(x + 1, y))), s.insert(mk(x + 1, y));


        int mv = 0;
        while(q.size())
        {
            auto d = q.front().fi;
            auto loc = q.front().se;
            q.pop();

            if(::s[loc.fi][loc.se] == '*')
            {
                mv = d;
                break;
            }

            if(loc.se + 1 < m && s.count(mk(loc.fi, loc.se + 1)) == 0)
                q.emplace(mk(d, mk(loc.fi, loc.se + 1))), s.insert(mk(loc.fi, loc.se + 1));
            if(loc.fi + 1 < n && s.count(mk(loc.fi + 1, loc.se)) == 0)
                q.emplace(mk(d, mk(loc.fi + 1, loc.se))), s.insert(mk(loc.fi + 1, loc.se));
        }

//        cout <<x <<" " <<y <<" " <<mv <<endl;
        if(mv == 0 && y + 1 < m) y++;
        else x++;
    }

    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    reader.open_alter();

    int tc = 1;
//    reader >>tc;
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
//        printf("Case #%d:\n", ca);
        work();
    }
    return 0;
}