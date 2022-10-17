#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int MAXN = 2e5 + 10;
const int MAXM = 1e6 + 10;
const int MAXLOG = 20;
 
struct Edge
{
        int x,y;
        int w;
} edge[MAXM];
 
int T,n,m,i;
int val;
vector< pair<int,int> > e[MAXN];
int fa[MAXN],anc[MAXN][MAXLOG],dep[MAXN];
int mx[MAXN][MAXLOG];
 
inline bool cmp(Edge a,Edge b) { return a.w < b.w; }
inline int get_root(int x)
{
        if (fa[x] == x) return x;
        return fa[x] = get_root(fa[x]);
}
inline void kruskal()
{
        int i,x,y,sx,sy;
        int w;
        for (i = 1; i <= n; i++) fa[i] = i;
        sort(edge + 2 , edge + m+1 , cmp);
        for (i = 2; i <= m; i++)
        {
            x = edge[i].x;
            y = edge[i].y;
            w = edge[i].w;
            sx = get_root(x); 
            sy = get_root(y);
            if (sx != sy)
            {
                  fa[sx] = sy;
                  e[x].push_back(make_pair(y,w));
                  e[y].push_back(make_pair(x,w));    
            }    
        }    
}
inline void build(int u)
{
        int i,v;
        for (i = 1; i < MAXLOG; i++)  {
            anc[u][i] = anc[anc[u][i-1]][i-1];
            mx[u][i] = max(mx[u][i-1],mx[anc[u][i-1]][i-1]);
        }
        for (i = 0; i < e[u].size(); i++) {
              v = e[u][i].first;
              if (anc[u][0] != v)
              {
                      dep[v] = dep[u] + 1;
                      anc[v][0] = u;
                      mx[v][0] = e[u][i].second;
                      build(v);                        
              }
        }
}
inline int get(int x,int y)
{
        int i,t;
        int ans = 0;
        if (dep[x] > dep[y]) swap(x,y);
        t = dep[y] - dep[x];
        for (i = 0; i < MAXLOG; i++) {
            if (t & (1 << i)) {
                ans = max(ans,mx[y][i]);
                y = anc[y][i];
            }
        }
        if (x == y) return ans;
        for (i = MAXLOG - 1; i >= 0; i--)
        {
            if (anc[x][i] != anc[y][i]) {
                ans = max(ans,max(mx[x][i],mx[y][i]));
                x = anc[x][i];
                y = anc[y][i];
            }
        }
        return max(ans,max(mx[x][0],mx[y][0]));
}
int main() 
{
        
      scanf("%d%d",&n,&m);
      if (m == n - 1) {
      		printf("%d\n" , (int)1e9);
      		return 0;
			}
      int U , V;
      for (i = 1; i <= m; i++) {
					scanf("%d%d%lld",&edge[i].x,&edge[i].y,&edge[i].w);
					if (i == 1) {
							U = edge[1].x;
							V = edge[1].y;
					}
			}
			kruskal();
			build( 1 );
      cout<< get(U , V) << '\n';
      
    	return 0;
    
}