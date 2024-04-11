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
#define epb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
const int e5 = (int) 1e5 + 5;
const int MOD = (int) 1e9 + 7;
//const int MOD = 998244353;
//const int MOD = (int) 911451407;

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
    Mint():x(0) {}
    Mint(int _x): x(_x)
    {
        if(x >= MOD) x %= MOD;
        else if(x < 0) x = (x % MOD + MOD) % MOD;
    }
    Mint operator - () const{
        return Mint(MOD - x);
    }
    Mint operator + (const Mint &rhs) const{
        return Mint(x + rhs.x >= MOD ? x - MOD + rhs.x : x + rhs.x);
    }
    Mint operator - (const Mint &rhs) const{
        return Mint(x - rhs.x < 0 ? x - rhs.x + MOD : x - rhs.x);
    }
    Mint operator * (const Mint &rhs) const{
        return Mint((LL)x * rhs.x % MOD);
    }
    Mint operator / (const Mint &rhs) const{
        return Mint((LL)x * fp(rhs.x, -1) % MOD);
    }
    Mint& operator += (const Mint &rhs) {
        x += rhs.x; if(x >= MOD) x -= MOD; return *this;
    }
    Mint& operator -= (const Mint &rhs) {
        x -= rhs.x; if(x < 0) x += MOD; return *this;
    }
    Mint& operator *= (const Mint &rhs) {
        x = ((LL)x * rhs.x) % MOD; return *this;
    }
    Mint& operator /= (const Mint &rhs) {
        x = (LL)x * fp(rhs.x, -1) % MOD; return *this;
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

    Mint rev() {return Mint(fp(x, -1));}
    Mint pow(int k) {return Mint(fp(x, k));}
    Mint pow(const Mint &t) {return Mint(fp(x, t.x));}
};


const int maxn = (int) 1e6 + 20;
const int maxm = (int) 2e6 + 20;


void work()
{
    int n, m;
    cin >>n >>m;
    vector<string> S(n);
    for(int i = 0; i < n; i++) cin >>S[i];

    vector<int> dx({0, 0, 1, -1});
    vector<int> dy({1, -1, 0, 0});

    auto is_valid = [&](int i, int j)
    {
        return 0 <= i && i < n && 0 <= j && j < m;
    };

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(S[i][j] == 'B')
            {
                for(int k = 0; k < 4; k++)
                {
                    int p = i + dx[k];
                    int q = j + dy[k];
                        if(is_valid(p, q) && S[p][q] == '.')
                            S[p][q] = '#';
                }
            }
    vector< vector<int> > vis(n, vector<int> (m, 0));
    auto bfs = [&](int x, int y)
    {
        queue<pii> Q;

        Q.push(mk(x, y));
        vis[x][y] = 1;

        while(!Q.empty())
        {
            x = Q.front().fi;
            y = Q.front().se;
            Q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(is_valid(nx, ny) && S[nx][ny] != '#' && !vis[nx][ny])
                {
                    Q.push(mk(nx, ny));
                    vis[nx][ny] = 1;
                }
            }
        }
    };

    if(S[n - 1][m - 1] != '#') bfs(n - 1, m - 1);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(S[i][j] == 'G' && vis[i][j] == 0)
            {
                cout <<"No" <<endl;
                return ;
            }
            if(S[i][j] == 'B' && vis[i][j] == 1)
            {
                    cout <<"No" <<endl;
                    return ;
            }
        }
    cout <<"Yes" <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
//    get_prime();

    int tc = 1;
    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}