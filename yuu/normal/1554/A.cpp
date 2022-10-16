#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100001];
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++)	cin>>a[i];
	long long ans=0;
	for(int i=1; i<n; i++){
		ans=max(ans, a[i]*a[i+1]);
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}