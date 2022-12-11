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

#define endl '\n'
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
using pii = pair<int, int>;

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double DINF = 1e100;
const double eps = 1e-8;
const int MOD_1e9 = 1000000007;
const int MOD_998 = 998244353;

template< typename T > inline void get_min(T &x, T y) {if(y < x) x = y;}
template< typename T > inline void get_max(T &x, T y) {if(x < y) x = y;}
template< typename T > inline void get_unique(vector<T> &vec) {sort(all(vec)); vec.erase(unique(all(vec)), vec.end());}

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
template< typename T > inline LL fp(LL a, T n, int mod) {
    if(n < 0) a = fp(a, mod - 2, mod), n = -n;
    LL res = 1;
    for(; n; n >>= 1, a = a * a % mod) if(n & 1) res = res * a % mod;
    return res;
}

template< int mod > class Mint {
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
    friend ostream &operator << (ostream &out, const Mint &rhs) {return out <<to_string(rhs.x);}
    Mint inv() const {return Mint(fp(x, -1, mod));}
    template< typename T > Mint pow(T k) const {return Mint(fp(x, k, mod));}
};

class fast_reader {
private:
    int buff_size;
    char *buff_ptr, *ptr, *tail;
    bool is_open;
    fast_reader(const fast_reader &) = delete;
    fast_reader &operator = (const fast_reader &) = delete;
    inline bool is_digit() const {return '0' <= *ptr && *ptr <= '9';}
    inline bool is_blank() const {return *ptr <= ' ';}
    template <typename T> inline void read_i(T &x) {
        static bool f;
        for(f = false; ptr < tail && !is_digit(); ptr++) if(*ptr == '-') f = true;
        for(x = 0; ptr < tail && is_digit(); ptr++) x = (x << 1) + (x << 3) + (*ptr & 0xf);
        if(f) x = -x;
    }
    template <typename T> inline void read_f(T &x) {
        static char t_buff[64]; read(t_buff); x = atof(t_buff);
    }
public:
    fast_reader(): buff_size(0), buff_ptr(nullptr), ptr(nullptr), tail(nullptr), is_open(false) {}
    ~fast_reader() {if(is_open) free(buff_ptr), is_open = false;}
    template <typename T> fast_reader &operator >> (T &x) {read(x); return *this;}
    template <typename T, typename ...Args> inline void read(T &x, Args &...args) {read(x); read(args...);}
    inline bool is_end() {while(ptr < tail && is_blank()) ptr++; return ptr >= tail;}
    inline void open_alter(int call_size = 1 << 20) {
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

const int maxn = (int) 1e6 + 5;
const int maxm = (int) 5e5 + 5;


void work()
{
    int n, m;
    reader >>n >>m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            reader >>a[i][j];

    auto premax = a;
    auto premin = a;
    auto sufmax = a;
    auto sufmin = a;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            get_max(premax[i][j], premax[i][j - 1]);
            get_min(premin[i][j], premin[i][j - 1]);
        }
        for(int j = m - 2; j >= 0; j--)
        {
            get_max(sufmax[i][j], sufmax[i][j + 1]);
            get_min(sufmin[i][j], sufmin[i][j + 1]);
        }
    }

    for(int j = 0; j < m - 1; j++)
    {
        vector<vector<int>> msg(n);
        for(int i = 0; i < n; i++)
            msg[i] = vector<int> {premax[i][j], premin[i][j], sufmax[i][j + 1], sufmin[i][j + 1], i};
        sort(all(msg));

        vector<int> back_premin(n);
        vector<int> front_sufmin(n);
        vector<int> back_sufmax(n);

        for(int i = 0; i < n; i++)
        {
            if(i == 0) front_sufmin[i] = msg[i][3];
            else front_sufmin[i] = min(front_sufmin[i - 1], msg[i][3]);
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(i == n - 1)
            {
                back_premin[i] = msg[i][1];
                back_sufmax[i] = msg[i][2];
            }
            else
            {
                back_premin[i] = min(back_premin[i + 1], msg[i][1]);
                back_sufmax[i] = max(back_sufmax[i + 1], msg[i][2]);
            }
        }

        for(int i = 0; i < n - 1; i++)
        {
            if(msg[i][0] < back_premin[i + 1] && front_sufmin[i] > back_sufmax[i + 1])
            {
                string ans(n, 'R');
                for(int k = 0; k <= i; k++) ans[msg[k][4]] = 'B';
                cout <<"YES" <<endl;
                cout <<ans <<" " <<j + 1 <<endl;
                return ;
            }
        }
    }
    cout <<"NO" <<endl;
}


int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    reader.open_alter();
//    ios::sync_with_stdio(false);

    int tc = 1;
    reader >>tc;
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
//        printf("Case #%d:\n", ca);
        work();
    }
    return 0;
}