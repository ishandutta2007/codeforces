#include <bits/stdc++.h>
using namespace std;
#define next baka
int n;
string s;
int next[300001][2];
int main(){
	cin>>n>>s;
	//with a string have both a and b, inserting anything is good
	s='0'+s;
	for(auto &x: s) x-='A';
	next[n][0]=n+1;
	next[n][1]=n+1;
	for(int i=n-1; i>=1; i--){
		next[i][0]=next[i+1][0];
		next[i][1]=next[i+1][1];
		next[i][s[i+1]]=i+1;
	}
	long long ans=0;
	for(int i=1; i<=n; i++){
		if(next[i][s[i]]==n+1) continue;
		ans+=next[i][1-s[i]]-i-1;
		if(next[i][1-s[i]]==n+1) continue;
		int pos=next[i][1-s[i]];
		if(pos==i+1) pos=next[i][s[i]]-1;
		ans+=n-pos;
	}
	cout<<ans<<'\n';
}