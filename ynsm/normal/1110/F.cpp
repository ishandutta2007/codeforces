#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );



const int N = 500100, LOG = 19;

int n, m, ver[N], l[N], r[N], p[N];

vector< pair<int, int> > g[N];
vector< pair<int, ll > > vec[N];

int timer, tin[N], tout[N], up[LOG][N], path[LOG];
ll depth[N], ans[N];

int sz[N], pr[N];
bool was[N];

bool cmp(int i, int j){
	return r[i] < r[j];
}
void predfs(int v, int p){
	tin[v] = ++timer;
	up[0][v] = p;
	for(int i = 1; i < LOG; i++)
		up[i][v] = up[i - 1][ up[i - 1][v] ];
	for(auto to : g[v])
		if(to.f != p){
			depth[to.f] = depth[v] + to.s;
			predfs(to.f, v);
		}
	tout[v] = timer;
}
bool upper(int v, int u){
	return tin[v] <= tin[u] && tin[u] <= tout[v];
}
int lca(int v, int u){ 
	if(upper(v, u))
		return v;
	if(upper(u, v))
		return u;
	for(int i = LOG - 1; i >= 0; i--)
		if(!upper(up[i][v], u))
			v = up[i][v];
	return up[0][v];	
}
ll dist(int v, int u){
	return depth[v] + depth[u] - 2 * depth[lca(v, u)];
}
void dfs(int v, int p){
	sz[v] = 1;
	for(auto to : g[v])
		if(to.f != p && !was[to.f]){
			dfs(to.f, v);
			sz[v] += sz[to.f];
		}
}

int cntr(int v, int p, int SZ){
	for(auto to : g[v])
		if(to.f != p && !was[to.f] && sz[to.f] * 2 > SZ)
			return cntr(to.f, v, SZ);
	return v;
} 

void build(int v){
	if(v == -1){
		dfs(1, 1);
		v = cntr(1, 1, sz[1]);
		pr[v] = -1;
	}
	was[v] = 1;
	for(auto to : g[v])
		if(!was[to.f]){
			dfs(to.f, to.f);
			int u = cntr(to.f, to.f, sz[to.f]);
			pr[u] = v;
			build(u);
		}
}
void add(int v){
	for(int u = v; u != -1; u = pr[u]){
		pair<int, ll > val = {v, dist(v, u)};
		while(!vec[u].empty() && vec[u].back().s >= val.s)
			vec[u].pop_back();
		vec[u].pb(val);
	}
}
ll get(int v, int l){
	ll res = 1e18;
	for(int u = v; u != -1; u = pr[u]){
		ll val = 1e18;
		if(!vec[u].empty()){
			val = lower_bound(vec[u].begin(), vec[u].end(), mp(l, 0ll)) - vec[u].begin();
			if(val == vec[u].size())
				val = 1e18;
			else{
				val = vec[u][val].s;	                  
			}
		}
		res = min(res, dist(v, u) + val);
	}
	return res;		
}
int main()
{
	n = readInt();
	m = readInt();

	for(int i = 2; i <= n; i++){
		int v, u, w;
		v = readInt();
        w = readInt();
		u = i;
		g[v].pb({u, w});
		g[u].pb({v, w});
	}
	
	predfs(1, 1);
	build(-1);

	for(int i = 1; i <= m; i++){
		ver[i] = readInt();
		l[i] = readInt();
		r[i] = readInt();
		p[i] = i;
	}
	sort(p + 1, p + 1 + m, cmp);
	for(int q = 1, j = 1; q <= m; q++){
		int i = p[q];
		while(j <= r[i]){
			if(g[j].size() == 1)
				add(j);
			j++;
		}			
		ans[i] = get(ver[i], l[i]);
	}
	for(int i = 1; i <= m; i++)
		writeInt(ans[i], '\n'); 
	return 0;
}





/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}


/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;