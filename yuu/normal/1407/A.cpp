#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001];
int cnt[2];
void solve(){
	cin>>n;
	cnt[0]=cnt[1]=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(cnt[1]*2<=n){
		cout<<cnt[0]<<'\n';
		for(int i=1; i<=cnt[0]; i++){
			cout<<0<<" \n"[i==cnt[0]];
		}
	}
	else{
		if(cnt[1]%2) cnt[1]--;
		cout<<cnt[1]<<'\n';
		for(int i=1; i<=cnt[1]; i++){
			cout<<1<<" \n"[i==cnt[1]];
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}