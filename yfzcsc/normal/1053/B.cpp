#include<bits/stdc++.h>
#define get(x) (__builtin_popcountll(x))
#define maxn 310000
using namespace std;
typedef long long ll;
int n,dp[maxn][2],s[maxn];
ll a[maxn];
int main(){
//	n=1000;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
//		a[i]=rand()+1;
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)s[i]=s[i-1]^(get(a[i])&1);
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		dp[i][s[i]]++;
	}
	ll ans=0;
	int M=100;
	for(int i=1;i<=n;++i){
		ll mx=get(a[i]),sum=0;
		for(int j=i;j>=1&&j>=i-M;--j){
			mx=max(mx,(ll)get(a[j]));
			sum+=get(a[j]);
//			printf("[(%d,%d)%lld,%lld]",i,j,mx,sum);
			if((~sum&1)&&mx<=sum-mx)ans++;
		}
		if(i-M-2>=0){
			ans+=dp[i-M-2][s[i]];
		}
	}
	cout<<ans;
}