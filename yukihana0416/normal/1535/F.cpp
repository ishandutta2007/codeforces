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
    ~fast_reader() {if(is_open) free(buff_ptr), is_open = false;}
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
constexpr int maxm = (int) 5e6 + 5;

using mint = Mint<MOD_1e9>;

static int seed[3] = {233, 1337, 337};
struct string_hash
{
    int len;
    vector<mint> lh[3];
    vector<mint> rh[3];

    void init(const string &s)
    {
        len = s.size();
        for(int i = 0; i < 3; i++)
        {
            lh[i].assign(len, 0);
            rh[i].assign(len, 0);
        }

        for(int i = 0; i < 3; i++)
        {
            lh[i][0] = s[0];
            for(int j = 1; j < len; j++) lh[i][j] = lh[i][j - 1] * seed[i] + s[j];
            rh[i][len - 1] = s[len - 1];
            for(int j = len - 2; j >= 0; j--) rh[i][j] = rh[i][j + 1] * seed[i] + s[j];
        }
    }

    LL get_l(int l)
    {
        if(l < 0) return 0;
        l = min(l, len - 1);
        int tmp[3] = {lh[0][l].x, lh[1][l].x, lh[2][l].x};
        return (LL(tmp[0] ^ tmp[1]) + (tmp[0] + tmp[1])) * tmp[2];
    }
    LL get_r(int r)
    {
        if(r >= len) return 0;
        r = max(r, 0);
        int tmp[3] = {rh[0][r].x, rh[1][r].x, rh[2][r].x};
        return (LL(tmp[0] ^ tmp[1]) + (tmp[0] + tmp[1])) * tmp[2];
    }
};

int n;
string s[maxn];
LL tya, tyb, tyc;

void gao(const vector<int> &ss)
{
    int sz = ss.size();
    int len = s[ss[0]].size();

    vector<string_hash> hs(sz);
    vector<vector<int>> point(sz);

    for(int i = 0; i < sz; i++)
    {
        const auto &str = s[ss[i]];
        hs[i].init(str);

        for(int j = 1; j < len; j++)
            if(str[j - 1] > str[j])
                point[i].epb(j);
    }

    auto func = [](const vector<int> &p, int L, int R) -> int
    {
        int idx = upper_bound(all(p), L) - p.begin();
        if(idx >= p.size()) return 0;
        if(p[idx] <= R) return 1;
        return 0;
    };

    LL ta = 0, tb = 0;
    if(double(sz) * sz < (double) sz * len * len * 4)
    {
        for(int x = 0; x < sz; x++)
            for(int y = x + 1; y < sz; y++)
            {
                int SL = -1, SR = len;
                {
                    int l = 0, r = len - 1;
                    while(l <= r)
                    {
                        int mid = MID(l, r);
                        if(hs[x].get_l(mid) == hs[y].get_l(mid)) SL = mid, l = mid + 1;
                        else r = mid - 1;
                    }
                }
                {
                    int l = 0, r = len - 1;
                    while(l <= r)
                    {
                        int mid = MID(l, r);
                        if(hs[x].get_r(mid) == hs[y].get_r(mid)) SR = mid, r = mid - 1;
                        else l = mid + 1;
                    }
                }

                SL++;
                SR--;

//                cout <<SL <<" " <<SR <<endl;

                if(SL > SR) continue;

                if(func(point[x], SL, SR) == 0 || func(point[y], SL, SR) == 0) ta++;
                else tb++;
            }
    }
    else
    {
        map<LL, int> mp;
        map<pair<LL, LL>, int> mp2;

        pair<LL, LL> pr;
        for(int i = 0; i < sz; i++)
        {
            mp[hs[i].get_l(len - 1)]++;
            int tmp = 0;
            for(int l = 0; l < len; l++)
            {
                while(tmp < point[i].size() && point[i][tmp] <= l) tmp++;
                if(tmp >= point[i].size()) break;

                for(int r = point[i][tmp]; r < len; r++)
                {
//                    if(func(point[i], l, r) == 0) continue;
                    LL lv = hs[i].get_l(l - 1);
                    LL rv = hs[i].get_r(r + 1);
                    pr.fi = lv, pr.se = rv;
                    mp2[pr]++;
                }
            }
        }

        for(int i = 0; i < sz; i++)
        {
            int tmp = 0;
            for(int l = 0, r; l < len; l = r)
            {
                if(tmp >= point[i].size()) r = len;
                else r = point[i][tmp++];
                LL lv = hs[i].get_l(l - 1);
                LL rv = hs[i].get_r(r);
                pr.fi = lv, pr.se = rv;
                ta += mp2[pr];
            }
        }

        tb = LL(sz) * (sz - 1) / 2 - ta;
        for(auto pr : mp)
            tb -= LL(pr.se) * (pr.se - 1) / 2;
    }

//    cout <<sz <<" " <<len <<" " <<ta <<" " <<tb <<endl;

    tya += ta;
    tyb += tb;
    tyc += LL(n - sz) * sz;
}

void work()
{
    reader >>n;
    map<vector<int>, vector<int>> mp;
    for(int i = 0; i < n; i++)
    {
        reader >>s[i];
        vector<int> cnt(26, 0);
        for(auto x : s[i]) cnt[x - 'a']++;
//        mint key = 0;
//        for(auto x : cnt) key = key * 337 + (x + 998);
        mp[cnt].epb(i);
    }

    tya = tyb = tyc = 0;
    for(const auto &pr : mp)
        gao(pr.se);

    tyc /= 2;
    LL ans = tya + tyb * 2 + tyc * 1337;
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