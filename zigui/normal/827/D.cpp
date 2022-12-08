#include<stdio.h>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> t3;
typedef tuple<int,int,int,int> t4;
typedef long long ll;

const int MM = 1000000007;
const int MX = 200005;

struct UF{
	int t[MX];
	int find(int x){ return t[x]? t[x] = find(t[x]) : x; }
	int merge(int a, int b){
		a = find(a), b = find(b);
		return a == b ? 0 : (t[a] = b, 1);
	}
}uf;

vector<t3> G[MX];
vector<t4> E, F;

int P[20][MX], mn[20][MX], lev[MX];
int ans[MX];

vector<int> add[MX], sub[MX];

void dfs(int x, int p){
	lev[x] = lev[p] + 1;
	for(t3 e : G[x]){
		int b, c, ad;
		tie(b, c, ad) = e;
		if( b == p ) continue;
		P[0][b] = x; mn[0][b] = c;
		for(int i = 1; i < 20; i++){
			int q = P[i-1][b];
			P[i][b] = P[i-1][q];
			mn[i][b] = max(mn[i-1][b], mn[i-1][q]);
		}
		dfs(b, x);
	}
}

void dfs2(int x, int p, multiset<int> &L){
	for(int c : add[x]) L.insert(c);
	for(t3 e : G[x]){
		int b, c, ad;
		tie(b, c, ad) = e;
		if( b == p ) continue;

		multiset<int> X;
		dfs2(b, x, X);
		if( X.empty() ) ans[ad] = -1;
		else ans[ad] = *X.begin() - 1;
		if( X.size() > L.size() ) L.swap(X);
		for(int c : X) L.insert(c);
	}
	for(int c : sub[x]) L.erase(L.find(c));
}

int up(int x, int d, int &v){
	if( d < 0 ) return x;
	for(int i = 0; i < 20; i++) if( d&1<<i ){
		v = max(v, mn[i][x]);
		x = P[i][x];
	}
	return x;
}

pii LCA(int a, int b){
	int v = 0;
	a = up(a, lev[a] - lev[b], v);
	b = up(b, lev[b] - lev[a], v);
	if( a == b ) return pii(a, v);
	for(int i = 19; i >= 0; i--){
		if( P[i][a] == P[i][b] ) continue;
		v = max({v, mn[i][a], mn[i][b]});
		a = P[i][a], b = P[i][b];
	}
	v = max({v, mn[0][a], mn[0][b]});
	return pii(P[0][a], v);
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E.emplace_back(c, a, b, i);
	}
	sort(E.begin(), E.end());
	for(t4 e : E){
		int a, b, c, ad;
		tie(c, a, b, ad) = e;
		if( uf.merge(a, b) ){
			G[a].emplace_back(b, c, ad);
			G[b].emplace_back(a, c, ad);
		}
		else{
			F.push_back(e);
		}
	}
	dfs(1, 0);
	for(t4 e : F){
		int a, b, c, ad;
		tie(c, a, b, ad) = e;
		pii t = LCA(a, b);
		ans[ad] = t.second - 1;
		add[b].push_back(c);
		add[a].push_back(c);
		sub[t.first].push_back(c);
		sub[t.first].push_back(c);
	}
	multiset<int> L;
	dfs2(1, 0, L);
	for(int i = 1; i <= M; i++) printf("%d ", ans[i]);
}