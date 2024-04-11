#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000100, mod = 998244353;

int n, m, k, a[N], b[550], p[550], l[550], r[550];
ll dp[550][550], val[550];
bool was[550][550];
vector< int > v[550];
int getp(int v){
	if(v == p[v])
		return v;
	return p[v] = getp(p[v]);
}
void Merge(int v, int u){
	v = getp(v);
	u = getp(u);
	if(v == u)
		return;
	if(v < u)
		swap(v, u);
	p[v] = u;
}
void solve(int l, int r){
	if(was[l][r])
		return;
	was[l][r] = 1;
	if(l > r){
		dp[l][r] = 1;
		return;
	}
	int p = l;
	for(int i = l; i <= r; i++)
		if(b[i] < b[p])
			p = i;
	ll aa = 0, bb = 0;
	for(int i = l; i <= p; i++){                   
		solve(l, i - 1);
		solve(i, p - 1);
		aa = (aa + dp[l][i - 1] * dp[i][p - 1]) % mod;	
	}
    for(int i = p; i <= r; i++){
		solve(p + 1, i);
		solve(i + 1, r);
		bb = (bb + dp[p + 1][i] * dp[i + 1][r]) % mod;
	}
	dp[l][r] = aa * bb % mod * val[b[p]] % mod;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		p[i] = i;
	
	v[0].pb(0);
	v[0].pb(m + 1);
	for(int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
		v[a[i]].pb(i);
	}
    for(int i = n; i >= 0; i--){
    	val[i] = 1;
 		for(int j = 0; j + 1 < v[i].size(); j++){
			int q = v[i][j] + 1;
			k = 0;			
			while(q < v[i][j + 1]){
				int x = getp(a[q]);
				if(x < i){
					printf("0");
					exit(0);
				}
				q = r[x] + 1;			
				b[++k] = x;
			}	
			for(int i = 1; i <= k; i++)
				for(int j = 1; j <= k; j++)	
					was[i][j] = 0;
			solve(1, k);
			for(int w = 1; w <= k; w++)
				p[b[w]] = i;
			val[i] = val[i] * dp[1][k] % mod;   	
 		}
 		l[i] = v[i][0];
 		r[i] = v[i].back();
   }
	printf("%lld", val[0]);
	return 0;
}