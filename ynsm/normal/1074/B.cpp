#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

vector< int > g[N];
int t, n, k1, k2, a[N], b[N];
bool good1[N], good2[N];
bool dfs(int v, int pr){
	if(good1[v]){
		cout << "A "<< v << endl;
		int x;
		cin >> x;
		if(good2[x])                  
			cout << "C " << v << endl;
		else
			cout << "C " << -1 << endl;	
		return 1;
	}
	for(auto to : g[v])
		if(to != pr && dfs(to, v))
			return 1;
	return 0;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n;

		for(int i = 1; i <= n; i++){
			g[i].clear();   
			good1[i] = 0;
			good2[i] = 0;
		}
		for(int i = 1; i < n; i++){
			int v, u;
			cin >> v >> u;
			g[v].pb(u);
			g[u].pb(v);
		}

		cin >> k1;
		for(int i = 1; i <= k1; i++){
			cin >> a[i];
			good1[a[i]] = 1;
		}

		cin >> k2;
		for(int i = 1; i <= k2; i++){
			cin >> b[i];
			good2[b[i]] = 1;
		}
		cout << "B " << b[1] << endl;
		int x;
		cin >> x;
		dfs(x, x);
	}
	return 0;
}