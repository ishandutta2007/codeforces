#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

#define LL long long

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define itr iterator
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;

template< typename T > inline void read(T &x) {
    bool f; char ch; f=0; x=0; ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 2e5+20;
const int maxm=(int) 1e5+20;
const int maxk=(int) 5e2+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

const int N=(int) 1e2+20;
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

int n;
char str[105];
int a[105];

int cnt[26];

void work()
{
    read(n);
    scanf("%s",str+1);

    for(int i=1;i<=n;i++) cnt[str[i]-'a']++;
    for(int i=1;i<=n;i++) read(a[i]);

    mcf.init(n/2+28,0,n/2+28);

    for(int i=0;i<26;i++) mcf.add_edge(0,n/2+i+1,cnt[i],0);

    for(int i=1;i<=n/2;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(str[i]==str[n-i+1])
            {
                if(str[i]=='a'+j) mcf.add_edge(n/2+j+1,i,1,min(-a[i],-a[n-i+1]));
                else mcf.add_edge(n/2+j+1,i,1,0);
            }
            else
            {
                if(str[i]=='a'+j) mcf.add_edge(n/2+j+1,i,1,-a[i]);
                else if(str[n-i+1]=='a'+j) mcf.add_edge(n/2+j+1,i,1,-a[n-i+1]);
                else mcf.add_edge(n/2+j+1,i,1,0);
            }
        }

        mcf.add_edge(i,n/2+28,2,0);
    }

    printf("%d\n",-mcf.Mincost());
}

//--------------end--------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}