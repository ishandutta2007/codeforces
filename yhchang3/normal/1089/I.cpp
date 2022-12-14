#include<bits/stdc++.h>
using namespace std;

int n,mod;
const int maxn = 410;
int ans[maxn];
int dp[maxn];
int fac[maxn];
void add(int &x,int y){
	x+=y;
	if(x>=mod)	x-=mod;
	if(x<0)	x+=mod;
}
int ho[maxn];
int DP[maxn][maxn];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q>>mod;
	dp[1]=fac[1]=1;
	for(int i=2;i<=400;i++)
		fac[i] = 1LL*fac[i-1]*i%mod;
	for(int i=2;i<=400;i++){
		dp[i]=fac[i];
		for(int j=1;j<i;j++)
			add(dp[i],-1LL*dp[j]*fac[i-j]%mod);
	}
	for(int i=4;i<=400;i++){
		for(int j=1;j<i;j++)
			add(ho[i],1LL*dp[j]*fac[i-j]%mod);
		add(ho[i],ho[i]);
	}
	ans[4]=2;
	DP[4][4]=1;
	DP[0][0]=1;
	for(int i=1;i<=400;i++){
		DP[i][i]=1;
		for(int j=1;j<i;j++){
			for(int k=1;k<=i-j+1;k++)
				add(DP[i][j],1LL*fac[k]*DP[i-k][j-1]%mod);
		}
	}
	for(int i=5;i<=400;i++){
		ans[i]=fac[i];
		add(ans[i],-ho[i]);
		for(int j=4;j<i;j++)
			add(ans[i],-1LL*DP[i][j]*ans[j]%mod);
	}
	while(q--){
		int x;
		cin>>x;
		if(x==1)	cout<<1<<'\n';
		else if(x==2)	cout<<2<<'\n';
		else if(x==3)	cout<<0<<'\n';
		else	cout<<ans[x]<<'\n';
	}
}