#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 107;
int n, xn;
bitset < N > f[N][N];
char s[N];

vi e[N];
void dfs(vi S) {
	int n = sz(S);
	if(n == 1) 
		return ;
	if(n == 2) 
		return e[S[0]].emplace_back(S[1]), e[S[1]].emplace_back(S[0]), void ();
		
	bitset < N > cur, xcur;
	for(const int &u : S) cur.set(u);
	xcur = cur;
//	bool ok = false; 
//	for(const int &u : S) 
//		for(const int &v : S) 
//			if(u != v && ((int) (f[u][v] & cur).count()) == n - 2) 
//				xcur.reset(u), xcur.reset(v), ok = true;
//	if(!ok || n == 3) {
//		bitset < N > p;
//		for(const int &u : S) 
//			for(const int &v : S) 
//				p |= f[u][v] & cur;
//		int rt = 0;
//		for(const int &u : S)
//			if(!p[u]) 
//				rt = u;

		vi rts;
		for(const int &u : S) {
			bitset < N > p = cur;
			for(const int &x : S) if(x != u) for(const int &y : S) 
				if(x < y && x != u && y != u && f[x][y][u]) 
					p &= f[x][y] & cur;
			if((int) p.count() != 1) 
				rts.emplace_back(u), xcur.reset(u);
		}
		if(!sz(rts)) return ;
//		cout << "RT = " << rt << endl;
		
		vi qwq;
		for(const int &u : S) if(xcur[u]) qwq.emplace_back(u);
		dfs(qwq);
		
		for(const int &rt : rts) {
			if(sz(qwq) == 1) {
				e[rt].emplace_back(qwq[0]);
				e[qwq[0]].emplace_back(rt);
			} else {
				for(const int &u : qwq) if(sz(e[u])) {
					bitset < N > S = f[rt][e[u][0]] & cur;
					if(S[u]) e[u].emplace_back(rt), e[rt].emplace_back(u); //, cout << rt << " with " << u << endl;
				}
			}
		}
		return ;
//	}
//	
//	vi qwq;
//	for(const int &u : S) if(xcur[u]) qwq.emplace_back(u);
//	dfs(qwq); 
//	for(const int &u : S) if(!xcur[u]) {
//		bitset < N > Z;
//		for(const int &v : S) if(u != v && ((int) (f[u][v] & cur).count()) == n - 2) Z.set(v);
//		for(const int &v : S) if((int) (f[u][v] & Z).count()) 
//			e[v].emplace_back(u), e[u].emplace_back(v); //, cout << u << " and " << v << endl;
//	}
}

int dist[N][N]; 

void Main () {
	cin >> n, xn = n;
	L(i, 0, n) e[i].clear();
	L(i, 1, n) {
		L(j, i + 1, n) {
			cin >> (s + 1);
			L(k, 1, n) f[i][j][k] = s[k] - '0';
			f[j][i] = f[i][j];
		}
	}
	vi G;
	L(i, 1, n) G.emplace_back(i);
	dfs(G);
	L(i, 1, n) {
		me(dist[i], 0x3f);
		dist[i][i] = 0;
		queue < int > q;
		q.push(i);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(const int &v : e[u]) 
				if(dist[i][v] > dist[i][u] + 1) 
					dist[i][v] = dist[i][u] + 1, q.push(v);
		} 
		L(j, 1, n) 
			if(dist[i][j] > n) 
				return cout << "No\n", void ();
	}
	L(i, 1, n) L(j, i + 1, n) {
		L(k, 1, n) {
			int c = f[i][j][k];
//			cout << i << ' ' << j << ' ' << k << " : " << c << endl;
//			cout << dist[i][k] << ' ' << dist[j][k] << endl;
			if(c != (dist[i][k] == dist[j][k])) 
				return cout << "No\n", void ();
		}
	}
	cout << "Yes\n";
	L(u, 1, n) 
		for(const int &v : e[u]) 
			if(u < v) 
				cout << u << ' ' << v << '\n';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}