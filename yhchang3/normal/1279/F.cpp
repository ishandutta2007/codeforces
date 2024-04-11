#include<bits/stdc++.h>
using namespace std;


bool type[1000001];
int n,k,l;
pair<long long int,int> dp[1000001];
bool check(int m){
	dp[0]=make_pair(0,0);
	for(int i=1;i<=n;i++){
		dp[i]=make_pair(dp[i-1].first+type[i],dp[i-1].second);
		if(i>=l)
			dp[i]=min(dp[i],make_pair(dp[i-l].first+m,dp[i-l].second+1));
	}
	return dp[n].second<=k;
}

int solve(){
	int L=0,r=1000010;
	while(L<r){
		int mid=(L+r)>>1;
		if(check(mid))
			r=mid;
		else
			L=mid+1;
	}
	check(L);
	return dp[n].first-L*k;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>l;
	string s;
	cin>>s;
	s.insert(0," ");
	for(int i=1;i<=n;i++)
		if(s[i]>='a'&&s[i]<='z')
			type[i]=false;
		else
			type[i]=true;
	if((long long int)k*l>=n){
		cout<<0<<endl;
		return 0;
	}
	int ans=1e9;
	ans=min(ans,solve());
	for(int i=1;i<=n;i++)
		type[i]^=true;
	ans=min(ans,solve());
	cout<<ans<<endl;
	
}