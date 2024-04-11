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
const int MOD = (int) 1e9 + 7;
//const int MOD = (int) 998244353;
const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1000000 + 20;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL m = MOD) {LL res = 1; for(; n; n >>= 1, a = a * a % m) if(n & 1) res = res * a % m; return res;}

const int N=(int) 500+20;
struct MCMF
{
    struct Edge
    {
        int from,to,cap,flow,cost;
        Edge() {}
        Edge(int _from,int _to,int _cap,int _flow,int _cost):
            from(_from),to(_to),cap(_cap),flow(_flow),cost(_cost) {}
    };
    int n,m,s,t;
    vector<Edge> edge;
    vector<int> G[N];
    bool inq[N];
    int d[N],p[N],fc[N];

    void init(int _n,int _s,int _t)
    {
        n=_n; s=_s; t=_t; m=0;
        edge.clear();
        for(int i=0;i<=n;i++) G[i].clear();
    }

    void add_edge(int from,int to,int cap,int cost)
    {
        edge.push_back(Edge(from,to,cap,0,cost));
        edge.push_back(Edge(to,from,0,0,-cost));
        m+=2;
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool spfa(int &flow,int &cost)
    {
        for(int i=0;i<=n;i++) d[i]=0x3f3f3f3f;
        memset(inq,0,sizeof(inq));
        queue<int> Q;
        d[s]=0; inq[s]=1; p[s]=0; fc[s]=0x3f3f3f3f;
        Q.push(s);

        while(!Q.empty())
        {
            int x=Q.front(); Q.pop();
            inq[x]=0;
            for(int i=0;i<G[x].size();i++)
            {
                Edge &e=edge[G[x][i]];
                if(e.cap>e.flow && d[e.to]>d[x]+e.cost)
                {
                    d[e.to]=d[x]+e.cost;
                    p[e.to]=G[x][i];
                    fc[e.to]=min(fc[x],e.cap-e.flow);
                    if(!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==0x3f3f3f3f) return 0;
        if(d[t] >= 0) return 0;
        flow+=fc[t];
        cost+=fc[t]*d[t];
        int x=t;
        while(x!=s)
        {
            edge[p[x]].flow+=fc[t];
            edge[p[x]^1].flow-=fc[t];
            x=edge[p[x]].from;
        }

        return 1;
    }

    int Mincost()
    {
        int flow=0, cost=0;
        while(spfa(flow,cost)) ;
        return cost;
    }
}mcf;


int n1, n2, m, r, b;
string L, R;
int isR[222], isB[222];

void work()
{
    cin >>n1 >>n2 >>m >>r >>b;
    cin >>L >>R;

    int oo = 1e5;
    int S = n1 + n2 + 1, T = n1 + n2 + 2;
    mcf.init(n1 + n2 + 2, S, T);

    for(int i = 0; i < L.size(); i++)
    {
        if(L[i] == 'R') mcf.add_edge(S, i, 1, -oo);
        if(L[i] == 'B') mcf.add_edge(i, T, 1, -oo);

        if(L[i] != 'B') mcf.add_edge(S, i, oo, 0);
        if(L[i] != 'R') mcf.add_edge(i, T, oo, 0);
    }

    for(int i = 0; i < R.size(); i++)
    {
        if(R[i] == 'R') mcf.add_edge(n1 + i, T, 1, -oo);
        if(R[i] == 'B') mcf.add_edge(S, n1 + i, 1, -oo);

        if(R[i] != 'B') mcf.add_edge(n1 + i, T, oo, 0);
        if(R[i] != 'R') mcf.add_edge(S, n1 + i, oo, 0);
    }

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >>x >>y;
        x--, y--;

        mcf.add_edge(x, n1 + y, 1, r);
        isR[i] = mcf.m - 2;
        mcf.add_edge(n1 + y, x, 1, b);
        isB[i] = mcf.m - 2;
    }


    int f = mcf.Mincost();

    for(int i = 0; i < L.size(); i++)
    {
        if(L[i] != 'U') f += oo;
    }
    for(int i = 0; i < R.size(); i++)
    {
        if(R[i] != 'U') f += oo;
    }

    if(f >= oo)
    {
        cout <<-1 <<endl;
        return ;
    }

    cout <<f <<endl;

    for(int i = 0; i < m; i++)
    {

        if(mcf.edge[isR[i]].flow == 1)
        {
            cout <<'R';
        }
        else if(mcf.edge[isB[i]].flow == 1)
        {
            cout <<'B';
        }
        else
        {
            cout <<'U';
        }
    }
    cout <<endl;
}


int main()
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