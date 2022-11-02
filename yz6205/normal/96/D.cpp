#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define int long long
#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 

const int INF = (int)1e12;
const int N = 1000;
int t[N],c[N];
int n,m,x,y;
typedef pair < int , int > Edge;
vector < Edge > _e [N];
vector < Edge >  e [N];
int _dis[N][N];
int  dis[N][N];

void init(){
    scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
    rep (i,m) {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        u--;
        v--;
        _e[u].push_back( Edge(v,w) );
        _e[v].push_back( Edge(u,w) );
    }
    rep (i,n) {
        scanf("%lld%lld",&t[i],&c[i]);
    }
}

void djk(int d[][N],vector < Edge > edge[]) {
    rep (out , n) {
        fill (d[out] , d[out] + n,INF);
        d[out][out] = 0;
        priority_queue < Edge , vector < Edge > , greater < Edge > > que;
        que.push ( Edge(0,out) );
        while (!que.empty()) {
            Edge pos = que.top();
            que.pop();
            int posd = pos.first , posw = pos.second;
            if ( posd > d[out][posw] ) continue;
            foreach (i,edge[posw]) {
                int v = edge[posw][i].first , w = edge[posw][i].second;
                if (posd + w < d[out][v]) {
                    d[out][v] = posd + w;
                    que.push ( Edge(d[out][v] , v) );   
                }
            }
        }
    }
}

void djk2(int d[][N],vector < Edge > edge[]) {
    int out = x - 1;
        fill (d[out] , d[out] + n,INF);
        d[out][out] = 0;
        priority_queue < Edge , vector < Edge > , greater < Edge > > que;
        que.push ( Edge(0,out) );
        while (!que.empty()) {
            Edge pos = que.top();
            que.pop();
            int posd = pos.first , posw = pos.second;
            if ( posd > d[out][posw] ) continue;
            foreach (i,edge[posw]) {
                int v = edge[posw][i].first , w = edge[posw][i].second;
                if (posd + w < d[out][v]) {
                    d[out][v] = posd + w;
                    que.push ( Edge(d[out][v] , v) );   
                }
            }
        }
    
}

void show(int d[][N]){
    rep (i,n) {
        rep (j,n) printf("%15lld ",d[i][j]);
        puts("");
    }
    puts("");
}

void solve(){
    djk (_dis,_e);
    rep (i,n) rep (j,n) if(i != j && _dis[i][j] <= t[i]) e[i].push_back( Edge(j,c[i]) );
    djk2 (dis,e);
    printf("%lld\n",(dis[x - 1][y - 1] == INF ? -1 : dis[x - 1][y - 1]));
}

#undef int
int main(){
    init();
    solve(); 
    return 0;
}