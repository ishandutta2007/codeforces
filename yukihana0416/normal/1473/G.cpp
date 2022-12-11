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
    inline bool is_blank() const {return *ptr == ' ' || *ptr == '\n' || *ptr == '\t' || *ptr == '\0';}
    template <typename T> inline void read_i(T &x)
    {
        bool f = false;
        x = 0;
        while(ptr < tail && !is_digit()) {if(*ptr == '-') f = true; ptr++;}
        while(ptr < tail && is_digit()) {x = (x << 1) + (x << 3) + (*ptr & 0xf); ptr++;}
        if(f) x = -x;
    }
    template <typename T> inline void read_f(T &x)
    {
        static char t_buff[1 << 6];
        read(t_buff);
        x = atof(t_buff);
    }
public:
    fast_reader(): buff_size(0), buff_ptr(nullptr), ptr(nullptr), tail(nullptr), is_open(false) {}
    ~fast_reader() {if(is_open) free(buff_ptr);}
    template <typename T> fast_reader &operator >> (T &x) {read(x); return *this;}
    template <typename T, typename ...Args> inline void read(T &x, Args &...args) {read(x); read(args...);}
    inline bool is_end() {while(ptr < tail && is_blank()) ptr++; return ptr >= tail;}

    inline void open_alter(int _base_size = 1 << 24) //2^24B = 16MB
    {
        if(is_open) throw runtime_error("fast reader is reopened!");

        int input_size = 0;
        int call_size = _base_size;
        buff_ptr = (char *) malloc(call_size);
        input_size += fread(buff_ptr, 1, call_size, stdin);
        while(feof(stdin) == 0)
        {
            int recall_size = call_size;
            buff_ptr = (char *) realloc(buff_ptr, call_size + recall_size);
            tail = buff_ptr + call_size;
            input_size += fread(tail, 1, recall_size, stdin);
            call_size += recall_size;
        }
        buff_ptr = (char *) realloc(buff_ptr, input_size);
        ptr = buff_ptr;
        tail = buff_ptr + input_size;
        buff_size = input_size;
        is_open = true;
    }

    inline void read(int &x) {read_i(x);}
    inline void read(unsigned int &x) {read_i(x);}
    inline void read(long long &x) {read_i(x);}
    inline void read(unsigned long long &x) {read_i(x);}
    inline void read(float &x) {read_f(x);}
    inline void read(double &x) {read_f(x);}
    inline void read(char *str)
    {
        while(ptr < tail && is_blank()) ptr++;
        while(ptr < tail && !is_blank()) *str = *ptr++, str++;
        *str = '\0';
    }
    inline void read(string &s)
    {
        while(ptr < tail && is_blank()) ptr++;
        char *pre = ptr;
        while(ptr < tail && !is_blank()) ptr++;
        s = move(string(pre, ptr)); //<utility>
    }
}reader;

constexpr int maxn = (int) 2e5 + 5;
constexpr int maxm = (int) 1e6 + 5;

using mint = Mint<MOD_998>;
const int P = MOD_998;
const mint yg = 3;
int bin[maxn << 2];
void NTT(mint *a, int n, int op)
{
    for(int i = 0; i < n; i++) bin[i] = (bin[i >> 1] >> 1) | ((i & 1) * (n >> 1));
    for(int i = 0; i < n; i++) if(i < bin[i]) swap(a[i], a[bin[i]]);
    for(int i = 1; i < n; i <<= 1) {
        mint wn = yg.pow(op == 1 ? (P - 1) / (2 * i) : (P - 1) - (P - 1) / (2 * i)), w, t;
        for(int j = 0; j < n; j += i << 1) {
            w = 1;
            for(int k = 0; k < i; k++) {
                t = a[i + j + k] * w; w = w * wn;
                a[i + j + k] = a[j + k] - t; a[j + k] = a[j + k] + t;
            }
        }
    }
    if(op == -1) {
        mint Inv = mint(n).inv();
        for(int i = 0; i < n; i++) a[i] = a[i] * Inv;
    }
}

mint fac[maxn];
mint ifac[maxn];

int n;
int l[1111], r[1111];
mint a[5555 * 8], b[5555 * 8], d[5555 * 8];

mint C(int n, int m)
{
    if(n < 0 || m < 0 || n - m < 0) return mint(0);
    return fac[n] * ifac[m] * ifac[n - m];
}

void work()
{
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i;
    ifac[maxn - 1] = fac[maxn - 1].inv();
    for(int i = maxn - 2; ~i; i--) ifac[i] = ifac[i + 1] * (i + 1);

    reader >>n;
    for(int i = 0; i < n; i++) reader >>l[i] >>r[i];

    int len = 1;
    d[0] = 1;
    for(int i = 0; i < n; i++)
    {
        int nlen = len + l[i] - r[i];

        int tot = 1;
        int alen = len;
        int blen = len + 1 + nlen;
        while(tot <= (alen + blen - 2)) tot <<= 1;

        for(int j = 0; j < tot; j++) a[j] = b[j] = 0;
        for(int j = 0; j < alen; j++) a[j] = d[j];
        for(int j = 0; j < blen; j++) b[j] = C(l[i] + r[i], r[i] + j - len);

//        cout <<tot <<endl;
//        for(int i = 0; i < tot; i++) cout <<a[i] <<" "; cout <<endl;
//        for(int i = 0; i < tot; i++) cout <<b[i] <<" "; cout <<endl;

        NTT(a, tot, 1);
        NTT(b, tot, 1);
        for(int i = 0; i < tot; i++) a[i] *= b[i];
        NTT(a, tot, -1);
//        for(int i = 0; i < tot; i++) cout <<a[i] <<" "; cout <<endl;

        for(int i = 0; i < nlen; i++) d[i] = a[i + len];
        len = nlen;
//        for(int i = 0; i < len; i++) cout <<d[i] <<" "; cout <<endl;
    }

    mint ans = 0;
    for(int i = 0; i < len; i++) ans += d[i];
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
//    reader >> tc;
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
//        printf("Case #%d:\n", ca);
        work();
    }
    return 0;
}