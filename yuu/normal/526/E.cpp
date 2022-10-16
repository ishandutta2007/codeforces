#include <bits/stdc++.h>
#define left Aria
using namespace std;
using ll=long long;
int n, q;
int a[2000001];
ll s[2000001];
int left[2000001];
ll b;
void solve(){
	cin>>b;
	for(int i=1, lt=0; i<=n+n; i++){
		while(s[i]-s[lt]>b) lt++;
		left[i]=lt;
	}
	int ans=n;
	int start=n;;
	for(int i=n+1; i<=n+n; i++){
		if(i-left[i]<start-left[start]){
			start=i;
		}
	}
	int len=start-left[start];
	for(int i=0; i<=len; i++){
		if(start+i>n+n) break;
		int s=start+i;
		int u=s;
		int res=0;
		while(s-u<n){
			res++;
			u=left[u];
		}
		ans=min(ans, res);
	}
	for(int i=1; i<=len; i++){
		if(start-i<n) break;
		int s=start-i;
		int u=s;
		int res=0;
		while(s-u<n){
			res++;
			u=left[u];
		}
		ans=min(ans, res);
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) a[i+n]=a[i];
	for(int i=1; i<=n*2; i++) s[i]=s[i-1]+a[i];
	while(q--) solve();
}