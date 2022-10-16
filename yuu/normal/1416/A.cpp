#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n;
int a[300001];
int f[300001];
int last[300001];
int ans[300001];
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) f[i]=0;
	for(int i=1; i<=n; i++) last[i]=0;
	for(int i=1; i<=n; i++) ans[i]=n+1;
	for(int i=1; i<=n; i++){
		f[a[i]]=max(f[a[i]], i-last[a[i]]-1);
		last[a[i]]=i;
	}
	for(int i=1; i<=n; i++)	f[i]=max(f[i], n-last[i]);
	for(int i=1; i<=n; i++) if(f[i]<n){
		f[i]++;
		//every segment with length i+1
		ans[f[i]]=min(ans[f[i]], i);
	}
	for(int i=2; i<=n; i++) ans[i]=min(ans[i], ans[i-1]);
	for(int i=1; i<=n; i++) if(ans[i]==n+1) ans[i]=-1;
	for(int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) solve();
}