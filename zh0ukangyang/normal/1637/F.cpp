#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 3e5 + 7;
int n, m, a[N], rx[N], mx; 
ll dp[N];

ll ns;

vi e[N];
void dfs (int x, int fa) {
	for(const int &v : e[x]) if(v != fa) {
		
		dfs(v, x);
		rx[x] = max(rx[x], rx[v]);
	}
	
	if(rx[x] < a[x]) 
		ns += a[x] - rx[x], rx[x] = a[x];
} 

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n ;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	mx = 1;
	L(i, 1, n) if(a[i] > a[mx]) mx = i;
	
	vector < int > vc;
	vc.push_back(0);
	for(const int &v : e[mx])
		dfs(v, mx), vc.push_back(rx[v]);
	sort(vc.begin(), vc.end());
	reverse(vc.begin(), vc.end());
	ns += a[mx] - vc[0] + a[mx] - vc[1];
	
	cout << ns << '\n';
	
	return 0;
}