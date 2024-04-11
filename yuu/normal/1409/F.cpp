#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, l;
string s, t;
int f[202][202][202];
void solve(){
	cin>>n>>l>>s>>t;
	for(int i=0; i<=200; i++) for(int j=0; j<=200; j++) for(int k=0; k<=200; k++) f[i][j][k]=-1e9;
	f[0][0][0]=0;
	for(int i=0; i<n; i++) for(int j=0; j<=i; j++) for(int k=0; k<=l; k++) if(f[i][j][k]>=0){
		// cerr<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
		f[i+1][j+(s[i]==t[0])][k]=max(f[i+1][j+(s[i]==t[0])][k], f[i][j][k]+j*(s[i]==t[1]));
		for(char c: t){
			// cerr<<c<<'\n';
			f[i+1][j+(c==t[0])][k+1]=max(f[i+1][j+(c==t[0])][k+1], f[i][j][k]+j*(c==t[1]));
		}
	}
	int ans=0;
	for(int j=0; j<=n; j++) for(int k=0; k<=l; k++) ans=max(ans, f[n][j][k]);
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--) solve();
}