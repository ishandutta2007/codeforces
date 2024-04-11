#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, ans;
set< int> g[N], st;
bool was[N];
void dfs(int v){
	vector< int > vv;
	for(auto to : st)
		if(g[v].find(to) == g[v].end()){
			was[to] = 1;
			vv.pb(to);
		}
	for(auto to : vv)
		st.erase(to);	
	for(auto to : vv)
		dfs(to);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].insert(u);
		g[u].insert(v);
	}              
	for(int i = 1; i <= n; i++)
		st.insert(i);
	for(int i = 1; i <= n; i++){
		if(!was[i]){
			was[i] = 1;
			st.erase(i);	
			dfs(i);
			ans++;
		}
	}
	printf("%d", ans-1);
	return 0;
}