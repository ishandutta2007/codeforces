#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, k;
int x[200001];
int y[200001];
int l[200001];
void solve(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>x[i];
	for(int i=1; i<=n; i++) cin>>y[i];
	sort(x+1, x+n+1);
	int ans=0;
	for(int i=1, j=1; i<=n; i++){
		while(x[i]-x[j]>k) j++;
		l[i]=max(l[i-1], i-j+1);
	}
	for(int i=n, j=n; i>=1; i--){
		while(x[j]-x[i]>k) j--;
		ans=max(ans, l[i-1]+j-i+1);
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}