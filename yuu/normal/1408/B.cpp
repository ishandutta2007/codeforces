#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, k;
int a[101];
void solve(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(k==1){
		if(a[1]!=a[n]) cout<<"-1\n";
		else cout<<"1\n";
		return;
	}
	set <int> s;
	for(int i=1; i<=n; i++) s.insert(a[i]);
	int sz=s.size();
	int ans=0;
	while(sz>0){
		ans++;
		sz-=k;
		if(ans==1) k--;
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) solve();
}