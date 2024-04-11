#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long      LL;
typedef long double    ld;
typedef pair<int,int>  pii;
typedef pair<LL,LL>    pLL;
typedef vector<int>    vint;
typedef vector<LL>     vLL;
typedef vector<pii>    vpii;
typedef vector<pLL>    vpLL;

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back

#define Si(x) scanf("%d",&(x));
#define Sii(x,y) scanf("%d %d",&(x),&(y));
#define Siii(x,y,z) scanf("%d %d %d",&(x),&(y),&(z));
#define Siiii(x,y,z,w) scanf("%d %d %d %d",&(x),&(y),&(z),&(w));
#define Siiiii(x,y,z,w,a) scanf("%d %d %d %d %d",&(x),&(y),&(z),&(w),&(a));
#define Siiiiii(x,y,z,w,a,b) scanf("%d %d %d %d %d %d",&(x),&(y),&(z),&(w),&(a),&(b));
#define SL(x) scanf("%lld",&(x));
#define SLL(x,y) scanf("%lld %lld",&(x),&(y));
#define SLLL(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
#define SLLLL(x,y,z,w) scanf("%lld %lld %lld %lld",&(x),&(y),&(z),&(w));
#define SLLLLL(x,y,z,w,a) scanf("%lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a));
#define SLLLLLL(x,y,z,w,a,b) scanf("%lld %lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a),&(b));

#define Pi(x) printf("%d\n",(x));
#define Pii(x,y) printf("%d %d\n",(x),(y));
#define Piii(x,y,z) printf("%d %d %d\n",(x),(y),(z));
#define Piiii(x,y,z,w) printf("%d %d %d %d\n",(x),(y),(z),(w));
#define Piiiii(a,b,c,d,e) printf("%d %d %d %d %d\n",(a),(b),(c),(d),(e));
#define Piiiiii(a,b,c,d,e,f) printf("%d %d %d %d %d %d\n",(a),(b),(c),(d),(e),(f));
#define PL(x) printf("%lld\n",(x)*1LL);
#define PLL(x,y) printf("%lld %lld\n",(x)*1LL,(y)*1LL);
#define PLLL(x,y,z) printf("%lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL);
#define PLLLL(x,y,z,w) printf("%lld %lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL,(w)*1LL);
#define PLLLLL(a,b,c,d,e) printf("%lld %lld %lld %lld %lld\n",(a)*1LL,(b)*1LL,(c)*1LL,(d)*1LL,(e)*1LL);
#define PLLLLLL(a,b,c,d,e,f) printf("%lld %lld %lld %lld %lld %lld\n",(a)*1LL,(b)*1LL,(c)*1LL,(d)*1LL,(e)*1LL,(f)*1LL);

#define Pi1(x) printf("%d",  (x));
#define PL1(x) printf("%lld",(x));
#define Pspace putchar(' ');
#define Pendl  puts("");

#define MEM0(x) memset( (x), 0, sizeof( (x) ) )
#define MEM1(x) memset( (x),-1, sizeof( (x) ) )
#define REP1(i,n)  for (int i = 1; (n) >= i ; ++i)
#define REP0(i,n)  for (int i = 0; (n) >  i ; ++i)

#define IOS ios::sync_with_stdio(0); cin.tie(0);

int myRnd() {
    return abs(  ((rand()<<15) ^ rand()) );
}

int myRnd(int L,int R) {
    return abs(( (rand()<<15)^rand() ) ) % (R-L+1) + L;
}

void Parr(int *arr,int L,int R) {
    for (int i=L;R>=i;i++) {
        printf("%d%c",arr[i]," \n"[i==R]);
    }
}

void Pvec(vint v) {
    for (int i=0;SZ(v)>i;i++) {
        printf("%d%c",v[i]," \n"[i==SZ(v)-1]);
    }
}

void Sarr(int *arr,int L,int R) {
    for (int i=L;R>=i;i++)
    {
        Si(arr[i]);
    }
}

const int N = 2e5 + 6;
const int INF = 0x3f3f3f3f;
const int mod = 1000000000 + 7;

int a[N];
int u[N];

vint G[N];

int in_degre[N],out_degree[N];

void add_edge(int from,int to)
{
    out_degree[from]++;
    in_degre[to]++;
    G[from].PB(to);
}

struct SCC {
	static const int MAX_N = 1e5 +6;
	vector<int> edg[MAX_N];
	vector<int> rev_edg[MAX_N];
	int n;
	vector<int> vv[MAX_N];
	void init(int _n) {
		n=_n;
		for(int i=0;n>=i;i++){
			edg[i].clear();
			rev_edg[i].clear();
			v[i].clear();
			vv[i].clear();
		}
	}
	void add_edge(int from,int to) {
		edg[from].push_back(to);
		rev_edg[to].push_back(from);
	}
	bool visit[MAX_N];
	int get_stamp[MAX_N];
	int in_scc[MAX_N];
	int stamp;
	void dfs1(int id) {
		visit[id]=1;
		for (int i:rev_edg[id]) {
			if (!visit[i]) dfs1(i);
		}
		get_stamp[++stamp] = id;
	}
	void dfs2(int id,int scc) {
		visit[id]=1;
		for (int i:edg[id]) {
			if (!visit[i]) dfs2(i,scc);
		}
		in_scc[id] = scc;
		vv[scc].push_back(id);
	}
	int scc;
	void make_scc() {
		memset(visit,0,sizeof(visit));
		stamp=0;
		for (int i=1;n>=i;i++) {
			if (!visit[i]) dfs1(i);
		}
		memset(visit,0,sizeof(visit));
		scc=0;
		for (int i=n;i>=1;i--) {
			if (!visit[get_stamp[i]]) {
				dfs2(get_stamp[i],++scc);
			}
		}
	}
	vector<int> v[MAX_N];
	int deg[MAX_N];
	int _1,_2;
	int meruru[MAX_N];
    vint judge() {
		make_scc();
		memset(visit,0,sizeof(visit));
		memset(meruru,0,sizeof(meruru));
		for (int i=1;n>=i;i++) {
			for (int j:edg[i]) {
				if (in_scc[i] != in_scc[j]) {
					v[in_scc[i]].push_back(in_scc[j]);
					meruru[ in_scc[i] ]++;
				}
			}
		}
		int mn_sz = n+1;
		vint ret;
        for (int i=1;scc>=i;i++)
        {
            if (meruru[i] == 0)
            {
                if (SZ(vv[i]) < mn_sz)
                {
                    mn_sz = SZ(vv[i]);
                    ret = vv[i];
                }
            }
        }
        return ret;
	}
} scc;

int main () {
    srand(time(NULL));
    int n,m,h;
    Siii(n,m,h);
    Sarr(u,1,n);
    REP1(i,m)
    {
        int x,y;
        Sii(x,y);
        if ((u[x]+1)%h == u[y]) add_edge(x,y);
        if ((u[y]+1)%h == u[x]) add_edge(y,x);
    }
    REP1(i,n)
    {
        if(!out_degree[i])
        {
            Pi(1);
            Pi(i);
            return 0;
        }
    }
    scc.init(n);
    REP1(i,n)
    {
        for (int j:G[i])
        {
            scc.add_edge(i,j);
        }
    }
    vint ans = scc.judge();
    Pi(SZ(ans));
    Pvec(ans);
}