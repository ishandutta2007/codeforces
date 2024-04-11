#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#define mp std::make_pair
#define x first
#define y second
using std::queue;
using std::set;
using std::pair;

const int N=((1<<20)+5);
int id[N], mx[N], tp;
set<pair<int, int> > st;
	const int M=100005;
	struct edge{
		int nxt, to, fl, c;
	}e[M];
	queue<int> q;
	int S, T, head[N], dis[N], pr[N], in[N], top=1, ans;
	inline void adde(int x, int y, int fl, int c)
	{
		e[++top]=edge{head[x], y, fl, c};
		head[x]=top;
	}
	inline void add(int x, int y, int fl, int c)
	{
//		printf("add %d %d %d %d\n", x, y, fl, c);
		adde(x, y, fl, c);
		adde(y, x, 0, -c);
	}
	inline void spfa(void)
	{
		for(int i=1; i<=tp; ++i) dis[id[i]]=-1;
//		std::fill(dis, dis+n+1, -1);
		dis[S]=0;
		q.push(S);
		in[S]=1;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			in[u]=0;
//			printf("now %d %d\n", u, dis[u]);
			for(int i=head[u]; i; i=e[i].nxt)
			{
				int v=e[i].to;
				if(e[i].fl&&dis[v]<dis[u]+e[i].c)
				{
					dis[v]=dis[u]+e[i].c;
					pr[v]=i^1;
					if(!in[v]) q.push(v), in[v]=1;
				}
			}
		}
	}
int n, k, a[N], ok[N], is[N];
inline void ins(int s)
{
//	printf("ins %d\n", s);
	if(__builtin_popcount(s)&1)
	{
		ok[s]=1;
		add(S, s, 1, a[s]);
		for(int i=0; i<n; ++i) if(ok[s^(1<<i)])
			add(s, s^(1<<i), 1, 0);
	}
	else
	{
		ok[s]=1;
		add(s, T, 1, a[s]);
		for(int i=0; i<n; ++i) if(ok[s^(1<<i)])
			add(s^(1<<i), s, 1, 0);
	}
	id[++tp]=s;
}
inline void rp(int x, bool fl=1)
{
	if(fl)
	{
		st.erase(mp(a[x]+a[mx[x]], x));
		if(!ok[x]) ins(x);
	}
	mx[x]=1<<n;
	for(int i=0; i<n; ++i) if(!is[x^(1<<i)]&&a[x^(1<<i)]>a[mx[x]])
		mx[x]=x^(1<<i);
	st.insert(mp(a[x]+a[mx[x]], x));
}
inline void run(void)
{
	spfa();
	if(!st.empty()&&st.rbegin()->x>dis[T])
	{
		int u=st.rbegin()->y;
		st.erase(prev(st.end()));
		if(!ok[u]) ins(u);
		if(!ok[mx[u]]) ins(mx[u]);
		spfa();
	}
	if(dis[T]==-1) return;
//	printf("run %d\n", pr[T]);
	int u=T, v=e[pr[T]].to;
	while(e[pr[u]].to!=S)
	{
		++e[pr[u]].fl;
		--e[pr[u]^1].fl;
		u=e[pr[u]].to;
	}
//	printf("run %d %d\n", u, v);
	++e[pr[u]].fl;
	--e[pr[u]^1].fl;
	is[u]=is[v]=1;
	ans+=a[u]+a[v];
	st.erase(mp(a[u]+a[mx[u]], u));
	for(int i=0; i<n; ++i) if(!is[v^(1<<i)])
	{
		rp(v^(1<<i));
	}
	for(int i=0; i<n; ++i) if(!ok[u^(1<<i)])
	{
		ins(u^(1<<i));
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	S=1<<n, T=S+1;
	a[S]=-0x3f3f3f3f;
	id[1]=S, id[2]=T;
	tp=2;
	for(int i=0; i<(1<<n); ++i) scanf("%d", a+i);
	for(int s=0; s<(1<<n); ++s)
	{
		if(__builtin_popcount(s)&1)
		{
			rp(s, 0);
		}
	}
	while(k--) run();
	printf("%d\n",  ans);
	return 0;
}