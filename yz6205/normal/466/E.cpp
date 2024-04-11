#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
template <typename T> bool checkMax(T& a, T b) { return a<b ? a=b,1 : 0; }
template <typename T> bool checkMin(T& a, T b) { return b<a ? a=b,1 : 0; }
#ifdef __LOCALE__
#define ses(a) cout << #a << "=" << a << ' '
#define see(a) cout << #a << "=" << a << endl
#else
#define ses(a)
#define see(a)
#endif

const int N = 100005;

struct Dsu {
	int p[N];
	Dsu () { rep (i,N) p[i] = i;  }
	int get(int u) { return u==p[u] ? u : p[u] = get(p[u]); }
	void merge(int u, int v) { p[ get(u) ] = get(v); }
	bool query(int u, int v) { return get(u) == get(v); }	
};

const int B = 20;
int upCnt[N];
vector <int> e[N];
int d[N], fa[N][B];
void dfs(int u, int f) {
	d[u] = d[f] + 1; 
	fa[u][0] = f; rep (i,B-1) { fa[u][i+1] = fa[ fa[u][i] ][i]; }
	for (vector<int>::iterator v=e[u].begin(); v!=e[u].end(); ++v) if (*v != f) {
		dfs( *v, u ); } }
bool isFa(int u, int f) {
	if (d[u] < d[f]) { return 0; }
	int del = d[u] - d[f];
	rep (i,B) if ((del>>i) & 1) { u = fa[u][i]; }
	return u == f; }

struct Query { int opt, x,y; };
vector <Query> qs;
struct Files { int x, id, ans; };
vector <Files> qf[N];

int n,m;

bool ansCmp(Files a, Files b) { return a.id < b.id; }

int main() {
	scanf("%d%d",&n,&m);
	rep (i,m) {
		int opt; scanf("%d",&opt);
		if (opt == 1) {
			int u,v; scanf("%d%d",&u,&v);
			upCnt[u]++; e[u].push_back(v); e[v].push_back(u); 
			qs.push_back( (Query){1,u,v} ); }
		else if (opt == 2) {
			int u; scanf("%d",&u);
			qs.push_back( (Query){2,u,0} ); }
		else {
			int x, id; scanf("%d%d",&x,&id);
			qf[id].push_back( (Files){x,i,0} ); } }
	repa (i,n) if (upCnt[i] == 0) { dfs(i, 0); }
	Dsu st;
	int fileCnt = 1;
	vector <Files> ans;
	for (vector<Query>::iterator q=qs.begin(); q!=qs.end(); ++q) {
		if (q->opt == 1) { st.merge(q->x, q->y); }
		else if (q->opt == 2) {
			for (vector<Files>::iterator fs = qf[fileCnt].begin(); fs != qf[fileCnt].end(); ++fs) {
				ses(q->x); see(fs->x);
				if (!st.query(fs->x, q->x)) { fs->ans = 0; ans.push_back(*fs); }
				else { fs->ans = isFa(q->x, fs->x); ans.push_back(*fs); } }
			fileCnt++; } }
	sort(ans.begin(), ans.end(), ansCmp);
	for (vector<Files>::iterator fs = ans.begin(); fs != ans.end(); ++fs) {
		puts( fs->ans ? "YES" : "NO" ); }
	return 0;
}