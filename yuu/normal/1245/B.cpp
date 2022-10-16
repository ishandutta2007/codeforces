#include <bits/stdc++.h>
using namespace std;
int n, r, p, s;
string t;
string res;
void solve(){
	cin>>n;
	cin>>r>>p>>s;
	cin>>t;
	res=t;
	int cnt=0;
	for(int i=0; i<n; i++){
		if(t[i]=='R'){
			if(p){
				res[i]='P';
				p--;
				cnt++;
			}
			else res[i]='Z';
		}
		else if(t[i]=='P'){
			if(s){
				res[i]='S';
				s--;
				cnt++;
			}
			else res[i]='Z';
		}
		else{
			if(r){
				res[i]='R';
				r--;
				cnt++;
			}
			else res[i]='Z';
		}
	}
	if(cnt*2>=n){
		cout<<"YES\n";
		for(auto &x: res) if(x=='Z'){
			if(p){
				x='P';
				p--;
			}
			else if(s){
				x='S';
				s--;
			}
			else{
				x='R';
				r--;
			}
		}
		cout<<res<<'\n';
	}
	else{
		cout<<"NO\n";
	}
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}