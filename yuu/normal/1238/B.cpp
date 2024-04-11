#include <bits/stdc++.h>
using namespace std;
int n, r;
int x[100001];
void solve(){
	cin>>n>>r;
	for(int i=1; i<=n; i++)	cin>>x[i];
	sort(x+1, x+n+1);
	n=unique(x+1, x+n+1)-x-1;
	int ans=n;
	for(int i=1; i<=n; i++)	ans=min(ans, max(n-i, (x[i]-1)/r+1));
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin>>q;
	while(q--) solve();
}