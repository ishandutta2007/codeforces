#include <bits/stdc++.h>
using namespace std;
int n;
int a[300001];
int low[300001];
int high[300001];
queue <int> q;
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) low[i]=0;
	for(int i=1; i<=n; i++) high[i]=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(low[a[i]]==0) low[a[i]]=i;
		high[a[i]]=i;
	}
	int after=0;
	for(int i=1; i<=n; i++) if(low[i]) after++;
	int before=0;
	int ans=n;
	int hg=1e9;
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(low[i]==0) continue;
		after--;
		if(hg>low[i]){
			cnt=0;
		}
		else{
			cnt++;
		}
		hg=high[i];
		ans=min(ans, before-cnt+after);
		before++;
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