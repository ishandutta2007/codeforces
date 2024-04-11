#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num = 0, flag = 1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}


int n; 
#define MAXN 1000005
#define MAXM 2000005
struct Edge {
	int v, w, nxt;
}e[MAXM << 1];
int lst[MAXN], Edgetot = 0;
inline void addedge(int u, int v, int w) {
	e[++Edgetot] = (Edge) {v, w, lst[u]};
	lst[u] = Edgetot;
}
struct Segment_tree {
	int l, r;
}b[MAXN << 2], a[MAXN << 2];
#define ls (k << 1)
#define rs (k << 1 | 1)
int num = 0;
void build1(int k, int l, int r) {
	a[k].l = l, a[k].r = r, num = max(num, k);
	if(l == r) {addedge(k+n, l, 0);return;}
	int mid = (l + r) >> 1;
	build1(ls, l, mid); build1(rs, mid+1, r);
	addedge(k+n, ls+n, 0); addedge(k+n, rs+n, 0);
}
void build2(int k, int l, int r) {
	if(l == r) {addedge(l, k+n+num, 0);return;}
	int mid = (l + r) >> 1;
	build2(ls, l, mid); build2(rs, mid+1, r);
	addedge(ls+n+num, k+n+num, 0); addedge(rs+n+num, k+n+num, 0);
}
void update1(int k, int ul, int ur, int u, int val) {
//	cout << k << endl;
	int l = a[k].l, r = a[k].r, mid = (l + r) >> 1;
//	cout << l << ' ' << r << endl;
	if(ul <= l && r <= ur) {
		addedge(u, k+n, val);
		return;
	}
	if(mid >= ur) update1(ls, ul, ur, u, val);
	else if(mid < ul) update1(rs, ul, ur, u, val);
	else {
		update1(ls, ul, mid, u, val);
		update1(rs, mid+1, ur, u, val);
	}
}
void update2(int k, int ul, int ur, int u, int val) {
	int l = a[k].l, r = a[k].r, mid = (l + r) >> 1;
	if(ul <= l && r <= ur) {
		addedge(k+n+num, u, val);
		return;
	}
	if(mid >= ur) update2(ls, ul, ur, u, val);
	else if(mid < ul) update2(rs, ul, ur, u, val);
	else {
		update2(ls, ul, mid, u, val);
		update2(rs, mid+1, ur, u, val);
	}
}

struct node {
	int id;
	ll val;
	bool operator < (const node b) const {return val > b.val;}
};
priority_queue < node > Q;
ll dis[MAXN * 5];
char used[MAXN * 5];
void Dij(int s) {
	memset(used, 0, sizeof(used));
	For(i, 1, 1000000)
		dis[i] = (1ll << 60);
	dis[s] = 0;
	Q.push((node) {s, 0});
	while(!Q.empty()) {
		int u = Q.top().id; Q.pop();
		if(used[u]) continue;
		used[u] = 1;
		for(int i = lst[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				Q.push((node) {v, dis[v]});
			}
		}
	}
}

signed main()
{
	n = read();
	build1(1, 1, n);
	build2(1, 1, n);
	
//	cout << num << endl;
	int Tnum = read(), S = read();
	while(Tnum--) {
		int opt = read(), u = read();
		if(opt == 1) {
			int v = read(), w = read();
			addedge(u, v, w);
		} else if(opt == 2) {
			int l = read(), r = read(), w = read();
			update1(1, l, r, u, w);
		} else {
			int l = read(), r = read(), w = read();
			update2(1, l, r, u, w);
		}
	}
	
	Dij(S);
	For(i, 1, n)  {
		if(dis[i] == (1ll << 60)) {
			printf("-1 ");
		} else {
			printf("%lld ", dis[i]);
		}
	}
    return 0;
}