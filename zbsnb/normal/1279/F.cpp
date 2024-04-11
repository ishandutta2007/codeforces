#include<iostream>
#include<algorithm>
#include<cstring>
#define pii pair<int,int>
#define ll long long 
using namespace std;
char s[1000010];
int a[1000010];
pii dp[1000010];
int n,k,l;
pii calcu(int m){
	dp[0]=make_pair(0,0);
	for(int i=1;i<=n;i++){
		dp[i]=make_pair(1<<30,0);
		if(i>=l){
			auto tmp=dp[i-l];
			tmp.first+=m;
			tmp.second++;
			dp[i]=min(dp[i],tmp);
		}
		if(i>=1){
			auto tmp=dp[i-1];
			tmp.first+=a[i];
			dp[i]=min(dp[i],tmp);
		}
	}
	return dp[n];
}
int main(){
	cin>>n>>k>>l;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		a[i]=islower(s[i])?1:0;		
	}
	if(1ll*k*l>=n){
		cout<<0<<endl;
		return 0;
	}
	int ans=1<<30;
	for(int i=1;i<=2;i++){
		int l=0,r=n/k+1,res=-1;
		while(l<=r){
			int m=(l+r)>>1;
			auto tmp=calcu(m);
			// cout<<m<<" "<<tmp.first<<" "<<tmp.second<<endl;
			if(tmp.second<=k){
				res=m;
				r=m-1;
			}
			else l=m+1;
		}
		auto tmp=calcu(res);
		// cout<<res<<endl;
		ans=min(ans,tmp.first-res*k);
		for(int i=1;i<=n;i++)a[i]^=1;
	}
	cout<<ans<<endl;
}