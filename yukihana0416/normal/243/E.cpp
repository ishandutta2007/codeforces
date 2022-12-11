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

const int N = 500 + 5;
struct PQ_tree
{
    int n, tot;
    int fail;
    vector<int> G[N << 2];
    int ty[N << 2];
    int sz[N << 2];
    int szc[N << 2];
    bool s[N];

    inline int getstate(int u)
    {
        if(szc[u] == 0) return 0;
        if(szc[u] == sz[u]) return 2;
        return 1;
    }

    void addson(int x, int y) {if(y) G[x].pb(y);}
    void join(int x, int y) {for(auto v : G[y]) G[x].pb(v);}
    int mergeP(vector<int> &vec)
    {
        if(vec.size() == 0) return 0;
        if(vec.size() == 1) return vec[0];
        G[++tot] = vec;
        return tot;
    }

    void init(int _n)
    {
        n = _n;
        tot = n + 1;
        memset(ty, 0, sizeof(ty));
        for(int i = 1; i <= n; i++) G[n + 1].pb(i);
        fail = 0;
    }

    void dfs(int u)
    {
        sz[u] = u <= n;
        szc[u] = u <= n && s[u];
        for(auto v : G[u])
        {
            dfs(v);
            sz[u] += sz[v];
            szc[u] += szc[v];
        }
    }

    int check(int u, int t)
    {
        if(fail) return 0;

        vector<int> vec[3];
        for(auto v : G[u]) vec[getstate(v)].pb(v);

        if(vec[1].size() > 2 || (t && vec[1].size() > 1)) return fail = 1, 0;
        if(t == 0 && vec[1].size() == 1 && vec[2].size() == 0) return check(vec[1][0], 0);

        if(ty[u] == 0)
        {
            int p2 = mergeP(vec[2]);
            if(t == 0)
            {
                G[u] = vec[0];
                if(vec[1].size() == 0) addson(u, p2);
                else
                {
                    int tmp1 = check(vec[1][0], 2);
                    addson(tmp1, p2);
                    if(vec[1].size() == 2) join(tmp1, check(vec[1][1], 1));
                    addson(u, tmp1);
                }
                return u;
            }
            else
            {
                ty[u] = 1;
                G[u].clear();
                addson(u, p2);
                if(vec[1].size() == 1) join(u, check(vec[1][0], 1));
                addson(u, mergeP(vec[0]));

                if(t == 2) reverse(G[u].begin(), G[u].end());
            }
            return u;
        }
        else
        {
            if(getstate(G[u].front()) > getstate(G[u].back())) reverse(G[u].begin(), G[u].end());

            int flag = 0;

            vector<int> tG;
            for(auto v : G[u])
            {
                int sta = getstate(v);
                if(sta == 0)
                {
                    if(flag == 1) flag = 2;
                    tG.pb(v);
                }
                else if(sta == 2)
                {
                    if(flag == 0) flag = 1;
                    else if(flag == 2) return fail = 2, 0;
                    tG.pb(v);
                }
                else
                {
                    int p1;
                    if(flag == 0) flag = 1, p1 = check(v, 2);
                    else if(flag == 1) flag = 2, p1 = check(v, 1);
                    else return fail = 3, 0;
                    for(auto x : G[v]) tG.pb(x);
                }
            }

            if(t && flag == 2) return fail = 4, 0;
            if(t == 1) reverse(tG.begin(), tG.end());
            G[u] = tG;
            return u;
        }
    }

    void dfs_permutation(int u, vector<int> &per)
    {
        if(u <= n) per.pb(u);
        for(auto v : G[u])
            dfs_permutation(v, per);
    }

    vector<int> get_permutation()
    {
        vector<int> res;
        dfs_permutation(n + 1, res);
        return res;
    }

    void restrict(vector<int> res)
    {
        for(int i = 1; i <= n; i++) s[i] = 0;
        for(auto x : res) s[x] = 1;
        dfs(n + 1);
        check(n + 1, 0);
    }
};



void work()
{
    int n;
    cin >>n;
    PQ_tree *pq = new PQ_tree;
    pq->init(n);

    vector<string> s(n);

    for(int i = 0; i < n; i++)
    {
        cin >>s[i];
        vector<int> res;
        for(int j = 0; j < n; j++)
            if(s[i][j] == '1')
                res.pb(j + 1);
        pq->restrict(res);
    }
    if(pq->fail)
    {
        cout <<"NO" <<endl;
    }
    else
    {
        cout <<"YES" <<endl;
        vector<int> perm = pq->get_permutation();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout <<s[i][perm[j] - 1];
            cout <<endl;
        }
    }

    delete pq;
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