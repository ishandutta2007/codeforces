#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int bad[256][256];
int f[256];
int g[256];
int main(){
	cin>>s;
	cin>>k;
	for(int i=0; i<k; i++){
		char a, b;
		cin>>a>>b;
		bad[a][b]=bad[b][a]=1;
	}
	for(char c: s){
		for(int i='a'; i<='z'; i++) g[i]=f[i]+1;
		for(int i='a'; i<='z'; i++) if(!bad[i][c]) g[c]=min(g[c], f[i]);
		for(int i='a'; i<='z'; i++) f[i]=g[i];
	}
	int ans=1e9;
	for(int i='a'; i<='z'; i++) ans=min(ans, f[i]);
	cout<<ans<<'\n';
}