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

const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
const int e5 = (int) 1e5 + 5;
const int MOD = (int) 1e9 + 7;
//const int MOD = (int) 998244353;
//int MOD = 998244353;

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


const int maxn = (int) 1e5 + 20;
const int maxm = (int) 1e6 + 20;

const int BASE = 998244353;
int n, k;
int a[maxn];
LL po[maxn];
LL inv[maxn];

struct Block
{
    int fail;
    vector<int> arr;
    vector<int> Lpart, Rpart;
    vector<LL> Lhs, Rhs;
    int Ridx;

    void init(vector<int> _arr)
    {
        arr = _arr;
    }

    void build()
    {
        vector<int> s;
        for(auto x : arr)
        {
            if(s.size() != 0 && s.back() == -x && x < 0) s.pop_back();
            else s.push_back(x);
        }
        fail = 0;
        for(int i = 0; i < (int) s.size() - 1; i++)
        {
            if(s[i] > 0 && s[i + 1] < 0)
            {
                fail = 1;
                break;
            }
        }

        if(fail) return ;
        int i;
        for(i = 0; i < (int) s.size(); i++)
            if(s[i] > 0)
                break;

        Lpart = vector<int> (s.begin(), s.begin() + i);
        Rpart = vector<int> (s.begin() + i, s.end());
        reverse(Rpart.begin(), Rpart.end());
        for(auto &x : Lpart) x = -x;

        Lhs = vector<LL> (Lpart.size());
        Rhs = vector<LL> (Rpart.size());

        for(int i = 0; i < Lpart.size(); i++)
        {
            if(i) Lhs[i] = (Lhs[i - 1] + Lpart[i] * po[i]) % MOD;
            else Lhs[i] = Lpart[i];
        }
        for(int i = 0; i < Rpart.size(); i++)
        {
            if(i) Rhs[i] = (Rhs[i - 1] + Rpart[i] * po[i]) % MOD;
            else Rhs[i] = Rpart[i];
        }
    }

    void change(int pos, int val)
    {
        arr[pos] = val;
        build();
    }
};


void work()
{
    read(n, k);
    po[0] = 1;
    for(int i = 1; i <= n; i++) po[i] = po[i - 1] * BASE % MOD;
    inv[n] = fp(po[n], -1);
    for(int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * BASE % MOD;

    for(int i = 0; i < n; i++) read(a[i]);

    int B = min(n, (int) (sqrt(n) * 1.5 + 1));
    int nn = (n + B - 1) / B;

    vector<Block> bk(nn);
    for(int i = 0; i < nn; i++) bk[i].init(vector<int> (a + i * B, a + min((i + 1) * B, n)));
    for(int i = 0; i < nn; i++) bk[i].build();

    int Q;
    read(Q);
    while(Q--)
    {
        int op, l, r;
        read(op, l, r);
        l--; r--;

        int lb = l / B, lp = l % B, rb = r / B, rp = r % B;

        if(op == 1)
        {
            bk[lb].change(lp, r + 1);
            a[l] = r + 1;
            continue;
        }

        if(lb == rb)
        {
            Block tmp;

            tmp.init(vector<int> (a + l, a + r + 1));
            tmp.build();

            if(tmp.fail || (tmp.Lhs.size() != 0 && tmp.Lhs.back() != 0) || (tmp.Rhs.size() != 0 && tmp.Rhs.back() != 0)) cout <<"No" <<endl;
            else cout <<"Yes" <<endl;
        }
        else
        {
            Block L, R;
            L.init(vector<int> (a + l, a + (lb + 1) * B));
            R.init(vector<int> (a + rb * B, a + r + 1));

            L.build();
            R.build();

            if((L.Lhs.size() != 0 && L.Lhs.back() != 0) || (R.Rhs.size() != 0 && R.Rhs.back() != 0) || L.fail || R.fail)
            {
                cout <<"No" <<endl;
                continue;
            }

            int fail = 0;
            for(int i = lb + 1; i < rb; i++)
            {
                fail |= bk[i].fail;
                bk[i].Ridx = 0;
            }
            L.Ridx = 0;

            stack<Block *> stk;
            if(L.Rpart.size()) stk.push(&L);


            function<LL(vector<LL> &, int, int)> getHash = [&](vector<LL> &Hs, int L, int R) -> LL
            {
                LL res = Hs[R];
                if(L > 0) res = (res - Hs[L - 1] + MOD) * inv[L] % MOD;
                return res;
            };

            function<int(Block *)> add = [&](Block *t) -> int
            {
                int cur = 0;
                while(stk.size() && cur < t->Lpart.size())
                {
                    Block *o = stk.top();

                    int sz = min(t->Lpart.size() - cur, o->Rpart.size() - o->Ridx);

                    if(getHash(o->Rhs, o->Ridx, o->Ridx + sz - 1) == getHash(t->Lhs, cur, cur + sz - 1))
                    {
                        o->Ridx += sz;
                        cur += sz;
                    }
                    else
                    {
                        return -1;
                    }

                    if(o->Ridx == o->Rhs.size()) stk.pop();
                }

                if(cur != t->Lpart.size()) return -1;
                return 0;
            };

            for(int i = lb + 1; i < rb; i++)
            {
                if(add(&bk[i]) == -1)
                {
                    fail = 1;
                    break;
                }
                if(bk[i].Rpart.size()) stk.push(&bk[i]);
            }

            if(fail)
            {
                cout <<"No" <<endl;
                continue;
            }

            if(add(&R) == -1)
            {
                cout <<"No" <<endl;
            }
            else
            {
                if(stk.size()) cout <<"No" <<endl;
                else cout <<"Yes" <<endl;
            }
        }
    }
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