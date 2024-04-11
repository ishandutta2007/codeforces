#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,dp[2][100][2];
int p=0,np=1;
void solve(ll s,int h1,int h2,int used){
	if(s&1)return ;
//	printf("[ok]");
	for(int i=0;i<=used;++i)
		for(int j=0;j<2;++j)
			dp[p][i][j]=dp[np][i][j]=0;
	dp[np][0][0]=1;
	for(int i=1;i<=60;++i,swap(p,np))
		for(int l=0;l<2;++l)
			for(int t=0;t<=used;++t)if(dp[np][t][l]){
				for(int j=0;j<2;++j)if(j==0||i<=h1-1)
					for(int k=0;k<2;++k)if(k==0||i<=h2-1)
						if((l+j+k)%2==!!(s&(1ll<<i)))dp[p][t+j+k][(l+j+k)/2]+=dp[np][t][l];
				dp[np][t][l]=0;
			}
//	printf("[%lld]",dp[np][used][0]);
	ans+=dp[np][used][0];
}
int main(){
	cin>>n;
	for(int i=1;i<=60;++i){
		if(n<(1ll<<i)-1)break;
		ll _n=n%((1ll<<i)-1);
		for(int j=i-1;j>=1;--j)if(_n>=(1ll<<j)-1)
			_n-=(1ll<<j)-1;
		if(!_n)ans++;
	}
//	return ans;
	for(int h1=1;h1<=60;++h1)
		for(int h2=1;h2<=60;++h2){
			ll _n=(n-((1ll<<h2)-1))%((1ll<<h1+1)+(1ll<<h2+1)-3);
			if(n<(1ll<<h2)-1+((1ll<<h1+1)+(1ll<<h2+1)-3))break;
//			_n-=(1ll<<h2)-1;
			for(int k=0;k<=h1+h2-2;++k)
				solve(_n+k,h1,h2,k);
//			printf("[%d,%d,%lld]",h1,h2,ans);
		}
	cout<<ans;
}