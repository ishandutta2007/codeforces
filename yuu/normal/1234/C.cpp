#include <bits/stdc++.h>
using namespace std;
int n;
string s[2];
void solve(){
	cin>>n>>s[0]>>s[1];
	int px=0, py=0, dir=0;
	bool good=1;
	while(py<n){
		if(dir==0){
			if(s[px][py]=='1'||s[px][py]=='2'){
				py++;
			}
			else{
				px=!px;
				dir=1;
			}
		}
		else{
			if(s[px][py]=='1'||s[px][py]=='2'){
				good=0;
				break;
			}
			else{
				dir=0;
				py++;
			}
		}
	}
	if(good) if(px==0) good=0;
	if(good) cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	int q;
	cin>>q;
	while(q--) solve();
}