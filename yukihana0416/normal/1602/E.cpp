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

template< typename T = int > struct Fenwick_tree {
    int n;
    vector<T> a;
    Fenwick_tree(int _n): n(_n) {a = vector<T> (n + 1, 0);}
    void add(int pos, T val) {
        for(int i = pos; i <= n; i += lowbit(i)) a[i] += val;
    }
    T sum(int pos) {
        T res = 0;
        for(int i = min(pos, n); i > 0; i -= lowbit(i)) res += a[i];
        return res;
    }
    T ask(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int n, m;
int a[maxn];
int b[maxn];

pii p[maxn];

int flag[maxn << 2];
int mx[maxn << 2];

void build(int l, int r, int id)
{
    mx[id] = 0;
    flag[id] = 0;
    if(l == r) return ;
    int mid = MID(l, r);
    build(lson);
    build(rson);
}

inline void push(int v, int id)
{
    mx[id] += v;
    flag[id] += v;
}

inline void lazy(int id)
{
    if(flag[id] == 0) return ;
    push(flag[id], ls);
    push(flag[id], rs);
    flag[id] = 0;
}

void upd(int v, int L, int R, int l, int r, int id)
{
    if(L <= l && r <= R)
    {
        push(v, id);
        return ;
    }
    lazy(id);
    int mid = MID(l, r);
    if(L <= mid) upd(v, L, R, lson);
    if(mid < R) upd(v, L, R, rson);
    mx[id] = min(mx[ls], mx[rs]);
}

void dfs(int l, int r, int id)
{
    if(l == r)
    {
        cout <<l <<" -> " <<mx[id] <<endl;
        return ;
    }
    lazy(id);
    int mid = MID(l, r);
    dfs(lson);
    dfs(rson);
}

void work()
{
    reader >>n >>m;
    for(int i = 1; i <= n; i++)
    {
        reader >>a[i];
        p[i] = mk(a[i], i);
    }
    for(int i = 1; i <= m; i++) reader >>b[i];
    sort(p + 1, p + 1 + n);
    sort(b + 1, b + 1 + m);

    LL ans = 0;
    Fenwick_tree<int> ft(n);

    for(int i = 1, j; i <= n; i = j)
    {
        for(j = i; j <= n && p[i].fi == p[j].fi; j++);
        for(int k = i; k < j; k++) ans += ft.ask(p[k].se, n);
        for(int k = i; k < j; k++) ft.add(p[k].se, 1);
    }
//    cout <<ans <<endl;

    build(0, n, 1);
    for(int i = 1; i <= n; i++) upd(1, i, n, 0, n, 1);

//    dfs(0, n, 1);

    LL pre_ans = 0;

    int vp = 1;
    for(int i = 1; i <= m; i++)
    {
        if(i > 1 && b[i - 1] == b[i])
        {
            ans += pre_ans;
            continue;
        }
        while(vp <= n && p[vp].fi < b[i])
        {
            upd(-1, p[vp].se, n, 0, n, 1);
            upd(1, 0, p[vp].se - 1, 0, n, 1);
            vp++;
        }
        int r = vp;
        for(; r <= n && p[r].fi == b[i]; r++) ;
        for(int k = vp; k < r; k++) upd(-1, p[k].se, n, 0, n, 1);

//        dfs(0, n, 1);

        pre_ans = 0;
        pre_ans = mx[1];
//        cout <<"addition answer : " <<pre_ans <<endl;
        ans += pre_ans;

        for(int k = vp; k < r; k++) upd(1, 0, p[k].se - 1, 0, n, 1);
        vp = r;
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