#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define x first
#define y second
#define mp std::make_pair
#define pb push_back
#define INF 0x7fffffffffffffff
#define ull unsigned long long
const int N=105;
using std::pair;
using std::queue;
using std::vector;
using std::priority_queue;
int n, m, k, tot, s[N];
int is[N], nxt[N][2], fail[N], top;
vector<pair<int, int> > e[N];
ull f[N][N][N], ans;
struct node{
	int x, y, z;
	ull dis;
	bool operator <(const node &a) const { return dis>a.dis; }
};
priority_queue<node> q;
void insert(int *s, int n)
{
	int idx=0;
	for(int i=1; i<=n; ++i)
	{
		if(!nxt[idx][s[i]]) nxt[idx][s[i]]=++top;
		idx=nxt[idx][s[i]];
	}
	is[idx]=1;
}
void build(void)
{
	static queue<int> q;
	for(int i=0; i<2; ++i) if(nxt[0][i]) q.push(nxt[0][i]);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0; i<2; ++i) if(nxt[u][i]) fail[nxt[u][i]]=nxt[fail[u]][i], q.push(nxt[u][i]);
		else nxt[u][i]=nxt[fail[u]][i];
		is[u]|=is[fail[u]];
	}
}
void dij(void)
{
	for(int i=0; i<=1; ++i) for(int j=0; j<=top; ++j) for(int k=0; k<=top; ++k) if(f[i][j][k]<INF)
		q.push(node{i, j, k, f[i][j][k]});
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		int u=tmp.x, i=tmp.y, j=tmp.z;
		if(f[u][i][j]!=tmp.dis) continue;
		for(auto t:e[u])
		{
			int v=t.x, w=t.y;
//			printf("uv %d %d %d %d %d\n", u, v, w, i, j);
			if(v>0)
			{
				if(w==-1)
				{
					if(f[u][i][j]<f[v][i][j])
					{
						f[v][i][j]=f[u][i][j];
						q.push(node{v, i, j, f[v][i][j]});
					}
				}
				else for(int k=0; k<=top; ++k)
				{
					if(f[u][i][j]+f[w][j][k]<f[v][i][k])
					{
						f[v][i][k]=f[u][i][j]+f[w][j][k];
//						printf("upt %d %d %d %d %d %d %llu\n", u, i, j, v, i, k, f[v][i][k]);
						q.push(node{v, i, k, f[v][i][k]});
					}
	//				else if(u==2) printf("w %d %d %d %llu %lld\n", w, j, k, f[w][j][k], f[v][i][k]);
				}
			}
			else
			{
//				puts("fa");
				v=-v;
				for(int k=0; k<=top; ++k)
				{
					if(f[u][i][j]+f[w][k][i]<f[v][k][j])
					{
//						printf("upt1 %d %d %d %d %d %d\n", u, i, j, v, i, k);
						f[v][k][j]=f[u][i][j]+f[w][k][i];
						q.push(node{v, k, j, f[v][k][j]});
					}
//					else printf("w %d %d %d %llu %lld\n", w, k, i, f[w][k][i], f[v][k][j]);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	tot=n-1;
	for(int i=1, a, k; i<=m; ++i)
	{
		scanf("%d%d", &a, &k);
		for(int i=1; i<=k; ++i) scanf("%d", s+i);
		int pr=s[1];
		for(int i=2; i<k; ++i) e[pr].pb(mp(++tot, s[i])), e[s[i]].pb(mp(-tot, pr)), pr=tot;
//		printf("add %d %d %d\n", pr, a, s[k]);
		if(k>1)
		{
			e[s[k]].pb(mp(-a, pr));
			e[pr].pb(mp(a, s[k]));
		}
		else e[s[k]].pb(mp(a, -1));
	}
	for(int i=1, l; i<=k; ++i)
	{
		scanf("%d", &l);
		for(int i=1; i<=l; ++i) scanf("%d", s+i);
		insert(s, l);
	}
	build();
//	printf("top %d\n", tot);
	for(int i=0; i<=tot; ++i) for(int j=0; j<=top; ++j) std::fill(f[i][j], f[i][j]+top+1, INF);
	for(int i=0; i<2; ++i) for(int j=0; j<=top; ++j) if(!is[j]&&!is[nxt[j][i]]) f[i][j][nxt[j][i]]=1;
	dij();
	for(int i=2; i<n; ++i)
	{
		ans=INF;
		for(int j=0; j<=top; ++j) ans=std::min(ans, f[i][0][j]);
		if(ans==INF) puts("YES");
		else printf("NO %llu\n", ans);
	}
	return 0;
}