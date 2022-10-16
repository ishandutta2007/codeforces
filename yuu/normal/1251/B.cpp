#include <bits/stdc++.h>
using namespace std;
int n;
pair <int, int> f[50];
void solve(){
	cin>>n;
	for(int i=0; i<n; i++) f[i].first=f[i].second=0;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		for(char c: s) if(c=='0') f[i].first++; else f[i].second++;
	}
	//even and both odd
	int cnt=0;
	int ans=0;
	for(int i=0; i<n; i++) if((f[i].first%2)&&(f[i].second%2)) cnt++;
	else ans++;
	ans+=cnt-cnt%2;
	cnt%=2;
	if(cnt%2){
		for(int i=0; i<n; i++) if((f[i].first+f[i].second)%2){
			ans++;
			break;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int q;
	cin>>q;
	while(q--) solve();
}