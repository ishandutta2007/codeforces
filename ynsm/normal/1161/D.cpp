#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

vector< pii > g[N];
int n, col[N], ans;
string s;
bool ok;
void dfs(int v, int c){
	if(col[v] == -1)
		col[v] = c;
	else{
		ok &= (col[v] == c);
		return;
	}	
	for(auto it : g[v])
		dfs(it.f, it.s ^ c);
}
void addE(int v, int u, int c){
	g[v].pb({u, c});
	g[u].pb({v, c});
}
int get(int l){            
	for(int i = 0; i <= n + l; i++){
		g[i].clear();
		col[i] = -1;
	}
	for(int i = 0; i < n; i++)
		addE(i, n - i - 1, 0);
	for(int i = 0; i < l; i++)
		addE(i + n, l - i - 1 + n, 0);
	for(int i = 0; i < l; i++)
		if(s[i] == '0')
			addE(i, i + n, 0);
	for(int i = 0; i < l; i++)
		if(s[i] == '1')
			addE(i, i + n, 1);
	for(int i = l; i < n; i++)
		if(s[i] == '0')
			addE(i, n + l, 0);
	for(int i = l; i < n; i++)
		if(s[i] == '1')
			addE(i, n + l, 1);
	addE(n, n + l, 1);
	int res = -1;
	ok = 1;
	for(int i = 0; i <= n + l; i++){
		if(col[i] != -1)
			continue;
		dfs(i, 0);
		if(res == -1)
			res = 1;
		else
			res = res * 2 % mod;
	}         
	return res * ok;
}
int main()
{
	cin >> s;
	reverse(s.begin(), s.end());
	n = s.size();
	for(int j = 1; j < n; j++)
		ans = (ans + get(j)) % mod;
	cout << ans;
	return 0;
}