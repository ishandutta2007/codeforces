#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
typedef long long ll;
const ll inf=1ll<<60;
int n,a,b,p=0,np=1,id[maxn];
ll dp[2][30][30][30],hp[201000],dmg[201000];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;++i)id[i]=i,scanf("%lld%lld",&hp[i],&dmg[i]);
	sort(id+1,id+n+1,[&](int x,int y){return hp[x]-dmg[x]>hp[y]-dmg[y];});
	
	for(int j=0;j<=a;++j)
		for(int k=0;k<=a;++k)
			for(int l=0;l<=j;++l) 
				dp[np][j][k][l]=dp[p][j][k][l]=-inf;
	for(int j=0;j<=a;++j)dp[np][j][0][0]=0;
	for(int i=1;i<=n;++i,swap(p,np)){
		ll A=dmg[id[i]],B=hp[id[i]];
		for(int j=0;j<=1;++j)
			for(int k=0;k<=a;++k)
				for(int l=0;l<=j;++l) 
					dp[p][j][k][l]=-inf;
		for(int j=0;j<=1;++j)
			for(int k=0;k<=a;++k)
				for(int l=0;l<=j;++l){
					if(i-l<=b-j)dp[p][j][k][l]=max(dp[p][j][k][l],dp[np][j][k][l]+max(A,B));
					else dp[p][j][k][l]=max(dp[p][j][k][l],dp[np][j][k][l]+A);
					if(l<j&&l+1<=b)for(int z=1;z<=a-k;++z)
						dp[p][j][k+z][l+1]=max(dp[p][j][k+z][l+1],dp[np][j][k][l]+max(A,B<<z));
				}
	}
	ll ans=0;
	for(int i=0;i<=1;++i)for(int k=0;k<=a;++k)
		ans=max(ans,dp[np][i][k][i]);
	printf("%lld",ans);
}