#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, m, a[N];
int deg[N];

vi e[N];
void dfs(int x, int fa, int w) {
	a[x] = w * deg[x];
//	cout << x << " : " << "w = " << w << '\n';
	for(const int &v : e[x]) if(v != fa) dfs(v, x, -w);
}

void Main () {
	cin >> n;
	L(i, 1, n) deg[i] = 0, e[i].clear();
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u); 
		deg[u] += 1;
		deg[v] += 1;
	}
	L(i, 1, n) 
		if(deg[i] <= 1) {
			dfs(i, 0, 1);
			break ;
		}
	L(i, 1, n) cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}