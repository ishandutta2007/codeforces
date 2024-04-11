#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long

#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 100005
struct Edge {
	int v, nxt;
}e[MAXN];
int lst[MAXN], tot = 0;
inline void addedge(int u, int v) {
	e[++tot] = (Edge) {v, lst[u]};
	lst[u] = tot;
}
int n, m;
int ind[MAXN], tmp[MAXN];
queue < int > q;
int topsort() {
	int tot = 0;
	For(i, 1, n) if(!ind[i]) q.push(i), tot++;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = lst[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(!(--ind[v])) {
				tot++;
				q.push(v);
			}
		}
	}
	return tot == n;
}
signed main()
{
	n = read(), m = read();
	For(i, 1, m) {
		int u = read(), v = read();
		addedge(u, v);
		ind[v]++;
	}
	For(i, 1, n) tmp[i] = ind[i];
	For(i, 1, n) {
		while(q.size()) q.pop();
		For(j, 1, n) ind[j] = tmp[j];
		if(ind[i]) {
			ind[i]--;
			if(topsort()) {
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}