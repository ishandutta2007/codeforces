#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=1;
map<ll,ll> dp[55][55];
ll calc(ll x){
	ll ans=x;
	for (;x;ans+=(x>>=1));
	return ans;
}
ll dfs(int x,int y,ll v){
	if (x>y) swap(x,y);
	if (!x&&!y) return !v;
	if (v<0||v>(2ll<<x)+(2ll<<y)-x-y-4) return 0;
	if (dp[x][y].count(v)) return dp[x][y][v];
	return dp[x][y][v]=dfs(x,y-1,v)+dfs(x,y-1,v-(1ll<<y)+1);
}
int main(){
	scanf("%lld",&n);
	for (int i=1;(2ll<<i)<=n+1;i++){
		ll lft=n%((2ll<<i)-1),x=lft>>1;
		for (;x<(1ll<<i)-1&&calc(x)<lft;x++);
		for (;x>0&&calc(x)>lft;x--);
		if (calc(x)==lft) ans++;
	}
	for (int l=1;(2ll<<l)<=n-2;l++)
		for (int r=1;(2ll<<l)+(3ll<<r)-4<=n;r++){
			ll lft=(n-(1ll<<r)+1)%((2ll<<l)+(2ll<<r)-3);
			ans+=dfs(l-1,r-1,lft);
		}
	printf("%lld",ans);
}