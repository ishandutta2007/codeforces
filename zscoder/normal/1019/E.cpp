#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const ll is_query = (1LL<<62);
struct Line
{
	ll m,c;
	bool operator <(const Line &rhs) const
	{
		if(m!=rhs.m) return m<rhs.m;
		else return c<rhs.c;
	}
	ll sub(ll x){return m*x+c;}
	Line(ll _m,ll _c):m(_m),c(_c){}
	Line():m(0),c(0){}
};

struct ConvexHull : public vector<Line>
{
	int ptr=0; vi id;
	bool bad(Line z)
	{
		auto y = prev(end());
		auto x = prev(y); 
		return (x->c-y->c)*1.0L*(z.m-y->m)>=(y->c-z.c)*1.0L*(y->m-x->m);
	}
	void insert_line(Line L, int _id)
	{
		while(size()>=2&&bad(L)) pop_back(),id.pop_back();
		push_back(L); id.pb(_id);
	}
	ll queryMonotone(ll x)
	{
		if(empty()) return 0;
		while(ptr+1<size())
		{
			auto l1=at(ptr); auto l2=at(ptr+1);
			if(l1.sub(x)<=l2.sub(x)) ptr++;
			else break;
		}
		auto l = at(ptr);
		return l.sub(x);
	}
};

struct Edge
{
	int to; Line cost;
	Edge():to(0),cost(Line(0,0)){}
	Edge(int _to, Line _cost):to(_to),cost(_cost){}
};
vector<Edge> adj[211111];
int n;
vector<Edge> adjtmp[211111];
int cnt;

void dfs_transform(int u, int p)
{
	int child=0; int curu=u;
	for(auto v:adj[u])
	{
		if(v.to==p) continue;
		if(!child)
		{
			adjtmp[u].pb(v); adjtmp[v.to].pb(Edge(u,v.cost));
			dfs_transform(v.to,u);
		}
		else
		{
			adjtmp[curu].pb(Edge(cnt,Line(0,0))); adjtmp[cnt].pb(Edge(curu,Line(0,0)));
			curu=cnt;
			adjtmp[cnt].pb(v); adjtmp[v.to].pb(Edge(cnt,v.cost));
			cnt++;
			dfs_transform(v.to,u);
		}
		child++;
	}
}

void transform()
{
	cnt=n;
	dfs_transform(0,-1);
	swap(n,cnt);
	for(int i=0;i<n;i++)
	{
		adj[i]=adjtmp[i];
	}
	/*
	cerr<<n<<'\n';
	for(int i=0;i<n;i++)
	{
		for(auto x:adj[i])
		{
			cerr<<i<<' '<<x.to<<' '<<x.cost.m<<' '<<x.cost.c<<'\n';
		}
	}
	*/
}

bool visited[211111];
int sub[211111];

void calc_siz(int u, int p=-1)
{
	sub[u]=1;
	for(auto edge:adj[u])
	{
		int v=edge.to;
		if(v==p||visited[v]) continue;
		calc_siz(v,u); sub[u]+=sub[v];
	}
}

int centroid(int u, int rt, int p=-1)
{
	for(auto edge:adj[u])
	{
		int v=edge.to;
		if(v==p||visited[v]) continue;
		if(sub[v]*2>sub[rt]) return centroid(v,rt,u);
	}
	return u;
}

ConvexHull cht[200111][3];
ConvexHull total;
vector<ii> centroidlist[200111];
vector<Line> centroidLine[200111];
vector<pair<Line,int> > lines;
int ct;
void go_root(int u, int p, Line cur, int rt, int id)
{
	lines.pb(mp(cur,id));//insert_line(cur); 
	ct++;
	centroidlist[u].pb(mp(rt,id)); centroidLine[u].pb(cur);
	for(auto edge:adj[u])
	{
		if(visited[edge.to]||edge.to==p) continue;
		go_root(edge.to,u,Line(cur.m+edge.cost.m, cur.c+edge.cost.c),rt,id);
	}
}

void go_all(int u=0)
{
	calc_siz(u);
	int cent=centroid(u,u);
	int id=0;
	centroidlist[cent].pb(mp(cent,-1));centroidLine[cent].pb(Line(0,0));
	for(auto edge:adj[cent])
	{
		if(visited[edge.to]) continue;
		//cerr<<cent<<' '<<edge.to<<' '<<sub[u]<<' '<<sub[edge.to]<<'\n';
		//assert(sub[edge.to]*2<=sub[u]);
		lines.clear(); ct=0;
		go_root(edge.to,cent,Line(edge.cost.m,edge.cost.c),cent,id);
		assert(ct*2<=sub[u]);
		sort(lines.begin(),lines.end());
		for(auto x:lines) cht[cent][id].insert_line(x.fi,x.se);
		id++;
	}
	visited[cent]=1;
	for(auto edge:adj[cent])
	{
		if(visited[edge.to]) continue;
		go_all(edge.to);
	}
}

void dfs_begin(int u, int p, ll m, ll c)
{
	lines.pb(mp(Line(m,c),u));
	for(Edge v:adj[u])
	{
		if(v.to==p) continue;
		dfs_begin(v.to,u,m+v.cost.m,c+v.cost.c);
	}
}

template<int input_SZ, int output_SZ> struct IO {
	char s[input_SZ], t[output_SZ], *a, *b;

	IO() { fread(s, 1, input_SZ, stdin); a = s; b = t; }
	~IO() { fwrite(t, 1, b - t, stdout); }

	char nextchar(char c) {
		return *a++;
	}

	int nextint() {
		while(*a != '-' && (*a < '0' || *a > '9')) ++a;
		bool flag = 0; int x = 0;
		if(*a == '-') ++a, flag = 1;
		while(*a >= '0' && *a <= '9') x = x * 10 + *a++ - '0';
		if(flag) x = -x;
		return x;
	}

	long long nextll() {
		while(*a != '-' && (*a < '0' || *a > '9')) ++a;
		bool flag = 0; long long x = 0;
		if(*a == '-') ++a, flag = 1;
		while(*a >= '0' && *a <= '9') x = x * 10 + *a++ - '0';
		if(flag) x = -x;
		return x;
	}

	void outchar(char c) {
		*b++ = c;
		if(b - t > output_SZ - 25) { fwrite(t, 1, b - t, stdout); b = t; }
		return;
	}

	template<typename T> void outnum(T x) {
		if(!x) { *b++ = '0'; return; }
		if(x < 0) *b++ = '-', x = -x;
		static char s[20], *a;
		a = s;
		while(x) {
			T y = x / 10;
			*a++ = x - y * 10 + '0';
			x = y;
		}
		while(a != s) *b++ = *--a;
		if(b - t > output_SZ - 25) { fwrite(t, 1, b - t, stdout); b = t; }
		return;
	}

	template<typename T> void outnum(T x, char c) {
		return outnum(x), outchar(c);
	}
};

IO<(1 << 22) | 10, (1 << 23) | 10> io;
int main()
{
	int m; n=io.nextint(); m=io.nextint();
	if(n == 1) { for (int i = 0; i < m; ++i) io.outnum(0, (i == m - 1 ? '\n' : ' ')); return 0; }
	for(int i=0;i<n-1;i++)
	{
		int u,v; int a,b; u = io.nextint(); v = io.nextint(); a = io.nextint(); b = io.nextint(); u--; v--;
		adj[u].pb(Edge(v,Line(a,b))); adj[v].pb(Edge(u,Line(a,b)));
	}
	transform();
	dfs_begin(0,-1,0,0);
	sort(lines.begin(),lines.end());
	for(auto x:lines) total.insert_line(x.fi,x.se);
	go_all();
	for(int i=0;i<n;i++) assert(int(adj[i].size())<=3);
	for(int i=0;i<m;i++)
	{
		total.queryMonotone(i);
		int u = total.id[total.ptr];
		ll ans=0;
		int z=0;
		for(auto C:centroidlist[u])
		{
			int cent=C.fi; int childno=C.se;
			ll res=centroidLine[u][z++].sub(i); ans=max(ans,res);
			for(int j=0;j<3;j++)
			{
				if(childno==j) continue;
				ans=max(ans,res+cht[cent][j].queryMonotone(i));
			}
		}
		io.outnum(ans, (i == m - 1 ? '\n' : ' '));
	}
}