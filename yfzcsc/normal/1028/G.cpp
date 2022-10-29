#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
typedef long long ll;
const int M=1e4;
const ll R=10004205361450474ll;
ll f[maxn][6],dp[10];
ll mul(ll a,ll b){
	if(R/a<b)return R;
	return min(R,a*b);
}
ll sol(ll x,ll y){
	if(x>=M)return dp[y];
	if(y==0)return 0;
	if(f[x][y])return f[x][y];
// 	sol(i,j) ask:a 0:sol(i,j-1) 1:sol(a,j-1)
	ll r=sol(x,y-1);
	for(int i=1;i<=x;++i)
		r=sol(r+1+x,y-1)+1+r;
	return f[x][y]=r;
}
int ask(vector<ll> G){
	printf("%d ",G.size());
	for(auto c:G)printf("%lld ",c);
	puts("");
	fflush(stdout);
	ll ret;
	scanf("%d",&ret);
	return ret;
}
int main(){
	dp[1]=M;
	for(int i=2;i<=6;++i)
		dp[i]=mul(dp[i-1],M+1)+M;
	int rest=5;
	ll nw=1; 
	while(1){
		vector<ll> G;
		ll use=min(nw,(ll)M);
		ll r=nw;
		for(int i=1;i<=use;++i){
			ll x=sol(r,rest-1);
			G.push_back(x+r);
			r=r+x+1;
		}
		int ret=ask(G);
		if(ret==-1)return 0;
		if(ret==0){
			rest--;
		} else {
			if(ret==G.size()){
				nw=G.back()+1;
				rest--;
			} else {
				nw=G[ret-1]+1;
				rest--;
			}
		}
	}
}