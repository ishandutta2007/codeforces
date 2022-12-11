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
constexpr int INF = 0x3f3f3f3f;
constexpr LL LINF = 0x3f3f3f3f3f3f3f3f;
constexpr double DINF = 1e100;
constexpr double eps = 1e-8;
constexpr int MOD_1e9 = 1000000007;
constexpr int MOD_998 = 998244353;
constexpr int MOD = MOD_998;

template< typename T > inline void get_min(T &x, T y) {if(y < x) x = y;}
template< typename T > inline void get_max(T &x, T y) {if(x < y) x = y;}
template< typename T > inline void get_unique(vector<T> &vec) {sort(all(vec)); vec.erase(unique(all(vec)), vec.end());}

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
template< typename T > inline LL fp(LL a, T n, int mod = MOD) {
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

constexpr int maxn = (int) 1e6 + 5;
constexpr int maxm = (int) 1e7 + 5;

int n, m, w;
int a[2002][2002];
LL dis[2002][2002];
int vis[2002][2002];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


void work()
{
    srand(233);
    reader >>n >>m >>w;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            reader >>a[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dis[i][j] = LINF, vis[i][j] = 0;

    LL tmp = LINF;

    priority_queue<pair<LL, pii>> pq;

    pq.emplace(mk(0, mk(1, 1)));
    dis[1][1] = 0;
    while(!pq.empty())
    {
        LL d;
        int x, y;
        auto pr = pq.top();
        pq.pop();

        d = -pr.fi;
        x = pr.se.fi;
        y = pr.se.se;

        if(vis[x][y]) continue;
        vis[x][y] = 1;

        if(a[x][y] > 0) get_min(tmp, d + a[x][y]);

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] != -1)
            {
                if(dis[nx][ny] > d + w)
                {
                    dis[nx][ny] = d + w;
                    pq.emplace(mk(-dis[nx][ny], mk(nx, ny)));
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            vis[i][j] = 0;
            if(a[i][j] > 0)
            {
                if(dis[i][j] > tmp + a[i][j])
                {
                    dis[i][j] = tmp + a[i][j];
                    pq.emplace(mk(-dis[i][j], mk(i, j)));
                }
            }
        }

    while(!pq.empty())
    {
        LL d;
        int x, y;
        auto pr = pq.top();
        pq.pop();

        d = -pr.fi;
        x = pr.se.fi;
        y = pr.se.se;

        if(vis[x][y]) continue;
        vis[x][y] = 1;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] != -1)
            {
                if(dis[nx][ny] > d + w)
                {
                    dis[nx][ny] = d + w;
                    pq.emplace(mk(-dis[nx][ny], mk(nx, ny)));
                }
            }
        }
    }

    LL res = dis[n][m];
    if(res >= LINF) res = -1;
    cout <<res <<endl;
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