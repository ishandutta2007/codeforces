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
using namespace std;

#define LL   long long
#define ld   long double
#define pii  pair<int,int>
#define pLL  pair<LL,LL>
#define vint vector<int>
#define vLL  vector<LL>

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
#define PLLLLL(a,b,c,d,e) printf("%lld %lld %lld %lld %lld\n",(a),(b),(c),(d),(e));
#define PLLLLLL(a,b,c,d,e,f) printf("%lld %lld %lld %lld %lld %lld\n",(a),(b),(c),(d),(e),(f));

#define Pi1(x) printf("%d",  (x));
#define PL1(x) printf("%lld",(x));
#define Pspace putchar(' ');
#define Pendl  puts("");

#define MEM0(x) memset( (x), 0, sizeof( (x) ) )
#define MEM1(x) memset( (x),-1, sizeof( (x) ) )
#define REP1(i,n)  for (int i = 1; (n) >= i ; ++i)
#define REP0(i,n)  for (int i = 0; (n) >  i ; ++i)
#define REP(L,R,k) for (int i = (L); (R) >= i; i+= (k) )

int myRnd(int L,int R) {
    return abs(( (rand()<<15)|rand() ) ) % (R-L+1) + L;
}

#define vpii vector<pii>

struct Dijkstra {
    static const int N = 2e6 +6;
    vpii G[N];
    int n,s;
    void init(int n,int s) {
        this->n = n;
        this->s = s;
        REP0(i,n+1) {
            G[i].clear();
        }
    }
    void add_edge(int from,int to,int cost) {
        G[from].PB({to,cost});
    }
    LL d[N];
    static const LL INF = 1e17 + 6;
    void solve() {
        REP0(i,n+1)
        {
            d[i] = INF;
        }
        d[s]=0;
        priority_queue<pLL,vector<pLL>,greater<pLL> > pq;
        pq.push({d[s],s});
        while (!pq.empty()) {
            pLL p= pq.top();
            pq.pop();
            if (d[p.S] != p.F) continue;
            for (pii pp:G[p.S]) {
                if (d[pp.F] > d[p.S] + pp.S) {
                    d[pp.F] = d[p.S] + pp.S;
                    pq.push({d[pp.F],pp.F});
                }
            }
        }
    }
} dijkstra;

const int N = 2e6 + 6;

int lc[N],rc[N];
int cnt;

void build1(int now,int L,int R) {
    if (L==R) {
        lc[now] = rc[now] = -1;
        dijkstra.add_edge(now,L,0);
        return;
    }
    int mid=(L+R)>>1;
    lc[now] = cnt++;
    rc[now] = cnt++;
    dijkstra.add_edge(now,lc[now],0);
    dijkstra.add_edge(now,rc[now],0);
    build1(lc[now],L,mid);
    build1(rc[now],mid+1,R);
}

void build2(int now,int L,int R,int par) {
    if (par != now) dijkstra.add_edge(now,par,0);
    if (L==R) {
        dijkstra.add_edge(L,now,0);
        lc[now] = rc[now] = -1;
        return;
    }
    int mid=(L+R)>>1;
    lc[now] = cnt++;
    rc[now] = cnt++;
    build2(lc[now],L,mid,now);
    build2(rc[now],mid+1,R,now);
    return;
}

void query1(int now,int L,int R,int l,int r,int v,int w) {
    if (L > r || l > R) return;
    else if (l<= L && R<=r) {
        dijkstra.add_edge(v,now,w);
        return;
    }
    int mid = (L+R)>>1;
    query1(lc[now],L,mid,l,r,v,w);
    query1(rc[now],mid+1,R,l,r,v,w);
}

void query2(int now,int L,int R,int l,int r,int v,int w) {
    if (L > r || l > R) return;
    else if (l<= L && R<=r) {
        dijkstra.add_edge(now,v,w);
        return;
    }
    int mid = (L+R)>>1;
    query2(lc[now],L,mid,l,r,v,w);
    query2(rc[now],mid+1,R,l,r,v,w);
}

int main () {
    srand(time(NULL));
    int n,q,s;
    Siii(n,q,s);
    dijkstra.init(N-1,s);
    cnt = n+1;
    int root1=cnt++;
    build1(root1,1,n);
    int root2=cnt++;
    build2(root2,1,n,root2);
    REP1(i,q)
    {
        int type;
        Si(type);
        if (type == 1) {
            int u,v,w;
            Siii(u,v,w);
            dijkstra.add_edge(u,v,w);
        }
        else if (type == 2) {
            int v,l,r,w;
            Siiii(v,l,r,w);
            query1(root1,1,n,l,r,v,w);
        }
        else if (type == 3) {
            int v,l,r,w;
            Siiii(v,l,r,w);
            query2(root2,1,n,l,r,v,w);
        }
    }
    dijkstra.solve();
    REP1(i,n) {
        LL val=dijkstra.d[i];
        if (i!=1) Pspace;
        if (val == dijkstra.INF) Pi1(-1)
        else PL1(val);
    }
    Pendl;
}