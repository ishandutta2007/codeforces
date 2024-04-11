#include <bits/stdc++.h>
using namespace std;
int p[200002];
int n, h, entai;
void solve(){
	cin>>h>>n;
	p[n+1]=0;
	for(int i=1; i<=n; i++) cin>>p[i];
	int ans=0;
	for(int i=2; i<=n; i++){
		if(p[i+1]==p[i]-1) i++;
		else ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin>>q;
	while(q--) solve();
}