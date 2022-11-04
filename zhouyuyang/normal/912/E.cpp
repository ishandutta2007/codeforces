#include<bits/stdc++.h>
using namespace std;
int n,a[20];
long long rk;
map<long long,long long> mp[20];
vector<long long> vec[20];
vector<long long> Vec[20];
long long gayyy(long long x,int at){
	return lower_bound(vec[at].begin(),vec[at].end(),x+1)-vec[at].begin();
}
long long calc(long long x){
	if (x<=50000000000ll) return gayyy(x,1);
	long long lim=x/50000000000ll+(x%50000000000ll!=0);
	long long ans=gayyy(50000000000ll,1);
	for (int i=0;i<=n;i++)
		for (int j=0;j<Vec[i].size();j++)
			if (1ll*Vec[i][j]*a[i]>=lim&&Vec[i][j]<lim){
				ans+=gayyy(x/Vec[i][j]/a[i],i);
				ans-=gayyy(50000000000ll/Vec[i][j]/a[i],i);
			}
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	vec[n+1].push_back(1);
	vec[n+1].push_back(50000000007ll);
	for (int i=n;i;i--){
		for (int j=0;j<vec[i+1].size();j++)
			vec[i].push_back(vec[i+1][j]);
		for (int j=0;j<vec[i].size();j++)
			if (1ll*vec[i][j]*a[i]<=50000000000ll)
				vec[i].push_back(1ll*vec[i][j]*a[i]);
		sort(vec[i].begin(),vec[i].end());
	}
	int tmp=0;
	Vec[0].push_back(1);
	Vec[0].push_back(20000007);
	for (int i=1;i<=n;i++){
		for (int j=0;j<Vec[i-1].size();j++)
			Vec[i].push_back(Vec[i-1][j]);
		for (int j=0;j<Vec[i].size();j++)
			if (1ll*Vec[i][j]*a[i]<=20000000)
				Vec[i].push_back(1ll*Vec[i][j]*a[i]);
		sort(Vec[i].begin(),Vec[i].end());
		tmp+=Vec[i].size();
	}
	scanf("%I64d",&rk);
	long long l=1,r=1e18,ans;
	while (l<=r){
		long long mid=(l+r)/2;
		if (calc(mid)>=rk)
			ans=mid,r=mid-1;
		else l=mid+1; 
	}
	printf("%I64d",ans);
}