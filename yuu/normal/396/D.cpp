#include <bits/stdc++.h>
using namespace std;
int n;
using ll=long long;
const ll base=1000000007;
int p[1000001];
ll f[1000001];
ll r[1000001];
ll rank_at[1000001];
ll less_at[1000001];
ll power(ll a, ll b){
	if(b==0) return 1;
	ll t=power(a, b/2);
	t=(t*t)%base;
	if(b%2) t=(t*a)%base;
	return t;
}
ll C(int n, int k){
	return ((f[n]*r[k])%base*r[n-k])%base;
}
int ft[1000001];
void update(int u){
	for(; u>0; u-=u&-u) ft[u]++;
}
int get(int u){
	int res=0;
	for(; u<=n; u+=u&-u) res+=ft[u];
	return res;	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	f[0]=1;
	for(int i=1; i<=n; i++) f[i]=(f[i-1]*i)%base;
	r[n]=power(f[n], base-2);
	for(int i=n; i>=1; i--) r[i-1]=(r[i]*i)%base;
	ll ans=0;
	ll rank=0;
	for(int i=1, x; i<=n; i++){
		cin>>x;
		///chose some number less than x
		ll more=get(x);
		update(x);
		more=n-x-more;
		ll less=n-i-more;
		rank=(rank+less*f[n-i])%base;
		rank_at[i]=rank;
		less_at[i]+=less;
		//choose some lesser element:
		//for element y, number created = (n-i)!*(y-1)
		//x*(x-1)/2*(n-i)!
		// cerr<<less<<'\n';
		// cerr<<ans<<'\n';
		ans=(ans+((less*(less-1))/2%base)*f[n-i])%base;
		//total created = C(n, 2)*C(n, 2)*(n-2)!
		// cerr<<ans<<'\n';
		if(n-i>1)	ans=(ans+((C(n-i, 2)*C(n-i, 2))%base*f[n-i-2])%base*less)%base;
		// cerr<<ans<<'\n';
	}
	// for(int i=1; i<=n; i++) cerr<<rank_at[i]<<" \n"[i==n];
	// for(int i=1; i<=n; i++) cerr<<less_at[i]<<" \n"[i==n];
	for(int i=1; i<=n; i++) ans=(ans+(rank-rank_at[i]+1)*less_at[i])%base;
	ans=(ans+base)%base;
	cout<<ans<<'\n';
}