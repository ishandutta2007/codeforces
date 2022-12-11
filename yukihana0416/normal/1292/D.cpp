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
const int MOD = (int) 1e9 + 7;
//const int MOD = (int) 998244353;
const int maxn = (int) 1e5 + 20;
const int maxm = (int) 1e6 + 20;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL m = MOD) {LL res = 1; for(; n; n >>= 1, a = a * a % m) if(n & 1) res = res * a % m; return res;}

int n;
int a[5555];
int f[5555][5555];
int sum[5555][5555];

struct Node
{
    LL cnt;
    LL len;
    map<int, pair<int, Node *> > son;
    Node() {cnt = 0; len = 0;}
};

void dfs(Node *o)
{
    for(auto v : o->son)
    {
//        cout <<v.fi <<" " <<v.se.fi <<endl;
        dfs(v.se.se);
        o->cnt += v.se.se->cnt;
        o->len += v.se.se->cnt * v.se.fi + v.se.se->len;
    }
}

void dp(Node *o, LL tlen, LL tcnt, LL &ans)
{
    ans = min(ans, tlen + o->len);
    for(auto v : o->son)
        dp(v.se.se, tlen + o->len - v.se.se->len + (tcnt + o->cnt - v.se.se->cnt * 2) * v.se.fi, tcnt + o->cnt - v.se.se->cnt, ans);
}

void work()
{
    read(n);
    for(int i = 0; i < n; i++)
    {
        int x; read(x);
        if(x == 0) x = 1;
        a[x]++;
    }

    memset(f, 0, sizeof(f));

    for(int i = 2; i <= 5000; i++)
    {
        for(int j = 2; j <= i; j++)
            f[i][j] = f[i - 1][j];

        int tmp = i;
        for(int j = 2; j <= i && tmp != 1; j++)
        {
            while(tmp % j == 0)
            {
                tmp /= j;
                f[i][j]++;
            }
        }
    }


    Node *rt = new Node;

    for(int i = 1; i <= 5000; i++)
        if(a[i])
        {
            Node *o = rt;
            for(int j = i; j != 1; j--)
            {
                if(f[i][j] == 0) continue;
//                cout <<i <<" " <<j <<" " <<f[i][j] <<endl;
                int k = f[i][j];
                while(k)
                {
                    if(o->son.find(j) == o->son.end())
                        o->son[j] = make_pair(k, new Node);
                    if(k >= o->son[j].fi)
                    {
                        k -= o->son[j].fi;
                        o = o->son[j].se;
                    }
                    else
                    {
                        int kk = o->son[j].fi;
                        Node *p = o->son[j].se;
                        Node *q = new Node;

                        o->son[j] = make_pair(k, q);
                        q->son[j] = make_pair(kk - k, p);

                        o = q;
                        k = 0;
                    }
                }
            }
            o->cnt += a[i];
        }
    LL ans = 1e18;
    dfs(rt);
    dp(rt, 0, 0, ans);

    cout <<ans <<endl;
}


int main(int argc, char **argv)
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
//    get_prime();
    int tc = 1;
//    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}