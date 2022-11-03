// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 1000000007 
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 100003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, u, v, P[mx][20], level[mx];
vector<int> g[mx], ve[mx], apa[mx];
int jauh, mana;
void dfs(int now, int par = 0, int lev = 0){
	P[now][0] = par;
	level[now] = lev;
	for(int i : g[now])
		if(i != par)
			dfs(i, now, lev + 1);
	if(jauh < lev)
		jauh = lev, mana = now;
}


int LCA(int p, int q){
	if(level[p] > level[q])
		swap(p, q);
	for(int i = 18; i >= 0; i--)
		if(level[q] - level[p] >= (1 << i))
			q = P[q][i];
	if(p == q)
		return p;
	for(int i = 18; i >= 0; i--)
		if(P[p][i] != P[q][i]){
			p = P[p][i];
			q = P[q][i];
		}
	return P[p][0];
}

int dist(int p, int q){
	return level[p] + level[q] - 2 * level[LCA(p, q)];
}

int pp[mx];

void DFS(int now, int par, int lev){
	// debug(now);
	pp[now] = par;
	apa[lev].pb(now);
	for(int i : g[now])
		if(i != par)
			DFS(i, now, lev + 1);
}

int tengah(int p, int q){
	int jarak = dist(p, q);
	if(jarak % 2 == 1)
		return -1;
	if(level[p] >= level[q])
		swap(p, q);
	jarak /= 2;
	for(int i = 18; i >= 0; i--){
		if(jarak >= (1 << i)){
			q = P[q][i];
			jarak -= 1 << i;
		}
	}
	return q;
}

void cek(int mid){
	for(int i = 0; i <= n; i++)
		apa[i].clear();
	DFS(mid, 0, 0);
	bool ya = true;
	for(int i = 0; i <= n; i++){
		for(int j : apa[i]){
			if(sz(g[j]) != sz(g[apa[i][0]]))
				ya = false;
		}
	}
	if(ya){
		cout << mid << endl;
		exit(0);
	}
}

int maks[mx];

void asu(int now, int par, int lev){
	maks[now] = max(maks[now], lev);
	for(int i : g[now]){
		if(i != par)
			asu(i, now, lev + 1);
	}
}

bool sudah[mx];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	jauh = -1;
	dfs(1);
	jauh = -1;
	int dari = mana;
	dfs(mana);

	for(int i = 1; i <= 18; i++)
		for(int j = 1; j <= n; j++)
			P[j][i] = P[P[j][i - 1]][i - 1];
	for(int i = 1; i <= n; i++){
		ve[sz(g[i])].pb(i);
	}
	int mid = tengah(dari, mana);
	if(mid != -1){
		cek(mid);
	}
	cek(dari);
	cek(mana);
	asu(dari, 0, 0);
	asu(mana, 0, 0);
	int ma = 0;
	for(int i : ve[1])
		ma = max(ma, maks[i]);
	int piro = 0;
	for(int i : ve[1])
		if(ma != maks[i])
			piro ++;
	if(piro > 1){
		cout << -1 << endl;
		return 0;
	}
	if(piro == 1){
		for(int i : ve[1])
			if(ma != maks[i])
				cek(i);
		cout << -1 << endl;
		return 0;
	}
	cout << -1 << endl;
}