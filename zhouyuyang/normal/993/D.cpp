#include<bits/stdc++.h>
#define ll long long
#define pa pair<ll,ll>
using namespace std;
pa p[55];
ll f[55][55];
ll sum[55];
int n;
bool check(ll mid){
	memset(f,60,sizeof(f));
	f[0][0]=0;
	for (int i=1,j;i<=n;i=j){
		for (j=i;p[j].first==p[i].first&&j<=n;j++);
		for (int k=i;k<j;k++)
			sum[k-i+1]=sum[k-i]+p[k].first-p[k].second*mid;
		for (int k=0;k<=n;k++)
			for (int l=0;l<=min(k,j-i);l++)
				f[j-1][(k-l)+(j-i)-l]=min(f[j-1][(k-l)+(j-i)-l],f[i-1][k]+sum[(j-i)-l]);
	}
	for (int i=0;i<=n;i++)
		if (f[n][i]<=0) return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&p[i].first),
		p[i].first*=1000;
	}
	for (int i=1;i<=n;i++)
		scanf("%lld",&p[i].second);
	sort(p+1,p+n+1,greater<pa>());
	ll l=1,r=1000000000000,ans;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	} 
	printf("%lld\n",ans);
}