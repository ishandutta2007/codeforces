#include <bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin>>s;
	s+='0';
	s='0'+s;
	set <char> ans;
	for(int i=1; i+1<s.size(); i++){
		int j=i;
		while(s[j+1]==s[i]) j++;
		if((j-i+1)%2) ans.insert(s[i]);
		i=j;
	}
	for(auto c: ans) cout<<c;
	cout<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}