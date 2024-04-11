#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
bool check(int a, int b, int c){
	if(a==b) return 0;
	if(a>b) return b<c;
	return b>c;
}
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	int ans=0;
	for(int i=1; i<=n; i++){
		ans++;
		if(i<n) ans++;
		if(i<n-1){
			if(check(a[i], a[i+1], a[i+2])){
				ans++;
				if(i<n-2) ans+=check(a[i], a[i+1], a[i+3])&&check(a[i], a[i+2], a[i+3])&&check(a[i+1], a[i+2], a[i+3]);
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}