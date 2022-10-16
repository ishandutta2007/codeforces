#include <bits/stdc++.h>
using namespace std;
int n, a, b;
string s;
void solve(){
	cin>>n>>a>>b;
	cin>>s;
	int score=a*n;
	if(b>0) score+=n*b;
	else{
		int zone=1;
		for(int i=1; i<n; i++) zone+=(s[i]!=s[i-1]);
		score+=(zone/2+1)*b;
	}
	cout<<score<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}