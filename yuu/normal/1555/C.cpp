#include <bits/stdc++.h>
using namespace std;
int m;
int a[2][100002];
void solve(){
	cin>>m;
	for(int i=0; i<2; i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
		}
	}
	a[0][m+1]=0;
	for(int i=m; i>=1; i--) a[0][i]+=a[0][i+1];
	a[1][0]=0;
	for(int i=1; i<=m; i++) a[1][i]+=a[1][i-1];
	int ans=1e9;
	for(int i=1; i<=m; i++) ans=min(ans, max(a[0][i+1], a[1][i-1]));
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}