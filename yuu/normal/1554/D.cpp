#include <bits/stdc++.h>
using namespace std;
int n;
void solve(){
	cin>>n;
	string padding;
	string res="";
	if(n<=26){
		for(int i=0; i<n; i++) res+=char('a'+i);
	}
	else{
		char f='a';
		while(n%4!=3){
			res+=f;
			f++;
			n--;
		}
		char x=f+1;
		char y=f+2;
		int k=(n-3)/4;
		for(int i=0; i<k; i++) res+=x;
		for(int i=0; i<=k; i++) res+=y;
		res+=f;
		for(int i=0; i<k; i++) res+=y;
		for(int i=0; i<=k; i++) res+=x;
	}
	cout<<res<<'\n';
}
int take[100001];
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}