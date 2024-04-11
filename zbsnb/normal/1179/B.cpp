#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=m;j++){
			cout<<i<<" "<<j<<"\n";
			cout<<n+1-i<<" "<<m+1-j<<"\n";
		}
	}
	if(n%2){
		for(int i=1;i<=m/2;i++){
			cout<<n/2+1<<" "<<i<<"\n";
			cout<<n/2+1<<" "<<m+1-i<<"\n";
		}
		if(m%2) cout<<n/2+1<<" "<<m/2+1<<"\n";
	}
	
}