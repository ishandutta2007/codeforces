#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 1000005
bool del[MAXN];
int u[MAXN], v[MAXN];
int deg[MAXN];
struct Node {
	int val, id;
	bool operator < (Node b) const {return val > b.val;}
};
struct Vertex {
	int v, id;
	bool operator < (Vertex b) const {return deg[v] > deg[b.v];}
};
vector < Vertex > g[MAXN];
priority_queue < Node > Q;
signed main()
{
	memset(del, 0, sizeof(del));
	int n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		u[i] = read(), v[i] = read();
		g[u[i]].push_back((Vertex) {v[i], i});
		g[v[i]].push_back((Vertex) {u[i], i});
		deg[u[i]]++, deg[v[i]]++;
	}
	int delnum = m - (n + m + 1) / 2;
	if(delnum <= 0) {
		printf("%d\n", m);
		for(int i = 1; i <= m; i++)
			printf("%d %d\n", u[i], v[i]);
		return 0;
	}
		
	for(int i = 1; i <= n; i++) {
		deg[i] = deg[i] - (deg[i] + 1) / 2;
		Q.push((Node) {deg[i], i});
	}
//	cout << Q.top().val << endl;
	while(delnum > 0) {
		int U = Q.top().id;
		if(deg[U] <= 0) { Q.pop(); continue; }
		Q.pop();
		sort(g[U].begin(), g[U].end());
		for(int i = 0; i < g[U].size(); i++) {
			if(del[g[U][i].id]) continue;
			int V = g[U][i].v;
			if(deg[V] <= 0) break;//
			del[g[U][i].id] = 1;
			deg[U]--, deg[V]--, delnum--;
			if(deg[V] > 0) {
				Q.push((Node) {deg[V], V});
			}
			if(deg[U] <= 0 || delnum <= 0) break; 
		}
	}
	printf("%d\n", (n + m + 1) / 2);
	For(i, 1, m) {
		if(del[i] == 0) {
			printf("%d %d\n", u[i], v[i]);
		}
	}
    return 0;
}