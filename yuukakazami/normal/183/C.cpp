#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define tr(e,x) for(vector<Edge>::iterator e=x.begin();e!=x.end();e++)
#define All(x) x.begin(),x.end()
#define pb push_back
#define OK puts("OK")
const int inf = ~0U >> 1, maxn = 100000 + 10;
using namespace std;
struct Edge {
	int t, c;
	Edge(int _t, int _c) :
			t(_t), c(_c) {
	}
};
int n, m;
vector<Edge> E[maxn];
void AddEdge(int a, int b) //a can see b
		{
	E[a].pb(Edge(b, 1));
	E[b].pb(Edge(a, -1));
}
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
bool Vis[maxn] = { };
int Mark[maxn];
int Len, MaxMark, MinMark;
void Dfs(int at) {
	Vis[at] = true;
	MaxMark = max(MaxMark, Mark[at]);
	MinMark = min(MinMark, Mark[at]);
	tr(e,E[at])
		if (!Vis[e->t]) {
			Mark[e->t] = Mark[at] + e->c;
			Dfs(e->t);
		} else {
			int diff = Mark[at] + e->c - Mark[e->t];
			if (!diff)
				continue;
			if (diff < 0)
				diff *= -1;
			if (!Len)
				Len = diff;
			else
				Len = gcd(Len, diff);
		}
}
void Init() {
	cin >> n >> m;
	int s, t;
	rep(i,m) {
		scanf("%d %d", &s, &t);
		--s;
		--t;
		AddEdge(s, t);
	}
}
void Solve() {
	Len = 0;
	int ans;
	rep(i,n)
		if (!Vis[i]) {
			MaxMark = -inf;
			MinMark = inf;
			Dfs(i);
			ans += MaxMark - MinMark + 1;
		}
	if (Len) {
		printf("%d\n", Len);
	} else {
		printf("%d\n", n);
	}
}
int main() {
	//freopen("in","r",stdin);
	Init();
	Solve();
}