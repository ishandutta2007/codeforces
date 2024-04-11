#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define pb push_back
using std::queue;
using std::vector;
const int N=100005;
namespace FLOW{
	const int M=2000005;
	struct edge{
		int to, nxt, fl;
	}e[M];
	int n, S, T, head[N], dis[N], iter[N], top;
	inline void init(void)
	{
		std::fill(head+1, head+n+1, 0);
		top=1;
	}
	inline void adde(int x, int y, int fl)
	{
		e[++top]=edge{y, head[x], fl};
		head[x]=top;
	}
	inline void add(int x, int y, int fl)
	{
		adde(x, y, fl);
		adde(y, x, 0);
	}
	void bfs(void)
	{
		static queue<int> q;
		std::fill(dis+1, dis+n+1, -1);
		while(!q.empty()) q.pop();
		q.push(S);
		dis[S]=0;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=head[u]; i; i=e[i].nxt) if(e[i].fl)
			{
				int v=e[i].to;
				if(dis[v]==-1)
				{
					dis[v]=dis[u]+1;
					if(v==T) return;
					q.push(v);
				}
			}
		}
	}
	int dfs(int u, int fl)
	{
		if(u==T) return fl;
		int ret=0;
		for(int &i=iter[u]; i; i=e[i].nxt) if(e[i].fl)
		{
			int v=e[i].to;
			if(dis[v]!=dis[u]+1) continue;
			int s=dfs(v, std::min(fl, e[i].fl));
			fl-=s, ret+=s, e[i].fl-=s, e[i^1].fl+=s;
			if(!fl) break;
		}
		return ret;
	}
	int dinic(int nn, int s, int t)
	{
		n=nn, S=s, T=t;
		int ret=0;
		while(1)
		{
			bfs();
			if(dis[t]==-1) break;
			std::copy(head, head+n+1, iter);
			ret+=dfs(s, 0x3f3f3f3f);
		}
		return ret;
	}
}
using FLOW::init;
using FLOW::top;
using FLOW::add;
using FLOW::e;
using FLOW::dinic;
using FLOW::head;
int T, n, m, s, t, rs, rt, nm, n1m, val[N], vis[N], cnt, rid[N], cr;
int ansval[N];
char ans[N], _Fc[5]="LRUD";
int id[N];
inline int gid(int x, int y) { return (x-1)*m+y; }
inline int L(int x)
{
	if(m==1||x%m==1) return 0;
	return x-1;
}
inline int R(int x)
{
	if(m==1||x%m==0) return 0;
	return x+1;
}
inline int U(int x)
{
	return x<=m?0:x-m;
}
inline int D(int x)
{
	return x>n1m?0:x+m;
}
int (*_F[4])(int)={L, R, U, D};
int eid[N][4];
int dx[N];
bool cmp(int a, int b) { return val[a]<val[b]; }
inline int gcol(int x) { return ((x-1)/m+1+(x-1)%m+1)&1; }
inline void radd(int x, int y, int lfl, int rfl)
{
	dx[x]+=lfl, dx[y]-=lfl;
	if(rfl-lfl) add(x, y, rfl-lfl);
}
void dfs(int u)
{
	int ok=0;
	for(int i=0; i<4; ++i) if(val[_F[i](u)]<cr)
	{
		ok=1;
		ans[u]=_Fc[i];
		ansval[u]=val[u]-val[_F[i](u)];
		break;
	}
	vis[u]=1;
	rid[u]=++cnt;
	if(gcol(u)) radd(s, rid[u], ok^1, 1);
	else radd(rid[u], t, ok^1, 1);
	for(int i=0; i<4; ++i)
	{
		auto F=_F[i];
		if(val[F(u)]==cr)
		{
			if(vis[F(u)]&&rid[F(u)]<rid[u]) continue;
			if(!vis[F(u)]) dfs(F(u));
			if(gcol(u)) radd(rid[u], rid[F(u)], 0, 1);
			else radd(rid[F(u)], rid[u], 0, 1);
			eid[u][i]=eid[F(u)][i^1]=top;
		}
	}
}
void rdfs(int u)
{
	vis[u]=2;
	for(int i=0; i<4; ++i) if(eid[u][i]&&e[eid[u][i]].fl)
	{
		ans[u]=_Fc[i];
		ansval[u]=gcol(u)?cr-1:1;
		break;
	}
	for(int i=0; i<4; ++i)
	{
		auto F=_F[i];
		if(vis[F(u)]==1&&val[F(u)]==cr) rdfs(F(u));
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		nm=n*m, n1m=(n-1)*m;
		val[0]=0x3f3f3f3f;
		for(int i=1; i<=nm; ++i) scanf("%d", val+i), id[i]=i, std::fill(eid[i], eid[i]+4, 0);
		id[nm+1]=0;
		std::sort(id+1, id+nm+1, cmp);
		std::fill(vis+1, vis+nm+1, 0);
		std::fill(rid+1, rid+nm+1, 0);
		std::fill(ans+1, ans+nm+1, 0);
		std::fill(ansval+1, ansval+nm+1, 0);
		for(int l=1, r; l<=nm; l=r+1)
		{
			r=l;
			while(val[id[r+1]]==val[id[l]]) ++r;
			cr=val[id[l]];
			for(int i=l; i<=r; ++i)
			{
				int u=id[i];
				if(vis[u]) continue;
				s=1, t=2, rs=3, rt=4;
				std::fill(dx+1, dx+cnt+1, 0);
				cnt=4;
				init();
				dfs(u);
				int sum=0;
				for(int i=1; i<=cnt; ++i)
				{
					if(dx[i]>0) add(i, rt, dx[i]), sum+=dx[i];
					if(dx[i]<0) add(rs, i, -dx[i]);
				}
				radd(t, s, 0, 0x3f3f3f3f);
				int fl=dinic(cnt, rs, rt);
				if(fl!=sum) goto FAIL;
				rdfs(u);
			}
		}
		puts("YES");
		for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=m; ++j) printf("%d ", ansval[gid(i, j)]);
		for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=m; ++j) printf("%c ", ans[gid(i, j)]);
		if(0)
		{
			FAIL:;
			puts("NO");
		}
	}
	return 0;
}