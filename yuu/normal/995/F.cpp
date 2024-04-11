#include <bits/stdc++.h>
using namespace std;
int n, d;
using ll=long long;
const ll base=1000000007;
vector <int> g[3001];
ll f[3001][3001];
ll c[3001][3001];
int child[3001];
ll power(ll a, ll b){
	if(b==0) return 1;
	ll t=power(a, b/2);
	t=(t*t)%base;
	if(b%2) t=(t*a)%base;
	return t;
}
///F(u, i)=F(u, i-1)+prdt(F(v, i))
void dfs(int u){
	child[u]=1;
	for(int v: g[u]) dfs(v);
	for(int i=1; i<=n; i++) f[u][i]=1;
	for(int v: g[u]){
		for(int i=1; i<=n; i++)	(f[u][i]*=f[v][i])%=base;
	}
	for(int i=1; i<=n; i++) (f[u][i]+=f[u][i-1])%=base;
}
ll C(int n, int k){
	if(n<k) return 0;
	ll top=1, bot=1;
	for(int i=n-k+1; i<=n; i++) top=(top*i)%base;
	for(int i=1; i<=k; i++) bot=(bot*i)%base;
	return (top*power(bot, base-2))%base;
}
int main(){
	cin>>n>>d;
	for(int i=0; i<=n; i++){
		c[i][0]=c[i][i]=1;
		for(int j=1; j<i; j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%base;
	}
	for(int i=2, p; i<=n; i++){
		cin>>p;
		g[p].push_back(i);
	}
	dfs(1);
	ll ans=0;
	for(int i=1; i<=n; i++){
		ll cnt=f[1][i];
		for(int j=1; j<i; j++){
			if((i-j)%2) (cnt-=f[1][j]*c[i][j])%=base;
			else (cnt+=f[1][j]*c[i][j])%=base;
		}
		(ans+=cnt*C(d, i))%=base;
	}
	ans=(ans+base)%base;
	cout<<ans<<'\n';
}