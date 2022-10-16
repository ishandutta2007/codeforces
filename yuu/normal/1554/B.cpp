#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[100001];
void solve(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	long long ans=-1e18;
	for(long long i=n; i>=1; i--){
		for(long long j=i-1; j>=1; j--){
			long long temp=i*j;
			if(temp<ans) break;
			ans=max(ans, i*j-k*(a[i]|a[j]));
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}