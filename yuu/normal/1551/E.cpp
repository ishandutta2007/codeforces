#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[2001];
int f[2001];//min original index of the last special number, the number gathered so far
deque <int> pos[2001];
int g[2001];
void solve(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) pos[i].clear();
	for(int i=1; i<=n; i++){
		cin>>a[i];
		pos[a[i]].push_back(i);
	}
	for(int i=1; i<=n; i++) f[i]=n+1;
	//new pos >= old_pos + new - old
	for(int cnt=1; cnt<=k; cnt++){
		if(cnt==1) g[0]=0;
		else g[0]=n+1;
		for(int i=1; i<=n; i++){
			g[i]=g[i-1];
			if(f[i]<=n+1) g[i]=min(g[i], f[i]-i);
		}
		for(int i=1; i<=n; i++){
			while((!pos[i].empty())&&(pos[i].front()<g[i-1]+i)) pos[i].pop_front();
			if(!pos[i].empty()){
				f[i]=pos[i].front();
			}
			else{
				f[i]=n+1;
			}
		}
		// cerr<<cnt<<"\n";
		// for(int i=0; i<=n; i++) cerr<<f[i]<<" \n"[i==n];
	}
	int ans=n+1;
	for(int i=1; i<=n; i++) if(f[i]!=n+1){
		// cerr<<f[i]<<'\n';
		ans=min(ans, f[i]-i);
	}
	if(ans==n+1) ans=-1;
	cout<<ans<<'\n';
	
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}