#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 100005
struct Edge {
	int v, w, nxt;
}e[MAXN << 2];
int lst[MAXN], tot = 0;
inline void addedge(int u, int v, int w) {
	e[++tot] = (Edge){v, w, lst[u]};
	lst[u] = tot;
}
int n, m;
char used[MAXN], vis[MAXN];
inline bool dfs(int u, int val) {
	vis[u] = 1;
	used[u] = 1;
	bool ans = 0;
	for(int i = lst[u]; i; i = e[i].nxt)
		if(e[i].w > val)
			if(used[e[i].v] || dfs(e[i].v, val)) return 1;
	used[u] = 0; 
	return ans;
}
inline bool check(int val) {
	memset(used, 0, sizeof(used));
	memset(vis, 0, sizeof(vis));
	For(i, 1, n)
		if(!vis[i] && dfs(i, val)) return 0;
	return 1;
}
vector < int > cha;
int d[MAXN], ind[MAXN], t;
queue < int > q;
void topsort(int now) {
	For(i, 1, n) if(!d[i]) q.push(i);
	while(q.size()) {
		int u = q.front(); q.pop();
		ind[u] = ++t;
		for(int i = lst[u]; i; i = e[i].nxt) {
			int v = e[i].v, w = e[i].w;
			if(w > now && !--d[v]) q.push(v);
		}
	} 
}
int work(int now) {
	For(i, 1, m)
		if(e[i].w > now) ++ d[e[i].v];
	topsort(now);
	For(i, 1, n) if(!ind[i]) ind[i] = ++t;
	For(u, 1, n) {
		for(int i = lst[u]; i; i = e[i].nxt) {
			int v = e[i].v, w = e[i].w;
			if(w <= now && ind[u] > ind[v]) cha.push_back(i); 
		}
	}
	return cha.size();
}
signed main()
{
	n = reaD(), m = read();
	For(i, 1, m) {
		int u = read(), v = read(), w = read();
		addedge(u, v, w);
	}
	int l = 0, r = 1000000000, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid-1;
			ans = mid;
		} else l = mid + 1;
	}
	cout << ans << ' ' << work(ans) << endl;
	sort(cha.begin(), cha.end());
	for(int i = 0; i < cha.size(); i++) printf("%d ", cha[i]);
    return 0;
}