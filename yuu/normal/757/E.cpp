#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=1000000007;
int g[1000001][21];
int p[1000001];
int main(){
	// for(int i=1; i<=30; i++){
		// for(int p=1; p<=i; p++) if(i%p==0) if(__gcd(p, i/p)==1) f[0][i]++;
	// }
	// for(int r=1; r<10; r++){
		// for(int n=1; n<=30; n++) for(int u=1; u<=n; u++) if(n%u==0) f[r][n]+=f[r-1][u];
	// }
	// for(int n=0; n<=30; n++) cerr<<setw(4)<<((n==0)?-1:n)<<" \n"[n==30];
	// for(int r=0; r<10; r++){
		// for(int n=0; n<=30; n++) cerr<<setw(4)<<((n==0)?r:f[r][n])<<" \n"[n==30];
	// }
	for(int i=2; i<=1000000; i++) if(p[i]==0) for(int j=i; j<=1000000; j+=i) if(p[j]==0) p[j]=i; 
	for(int i=0; i<=20; i++) g[0][i]=2;
	g[0][0]=1;
	for(int i=1; i<=1000000; i++){
		g[i][0]=1;
		for(int j=1; j<=20; j++){
			g[i][j]=g[i-1][j]+g[i][j-1];
			while(g[i][j]>=base) g[i][j]-=base;
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		int r, n;
		cin>>r>>n;
		ll ans=1;
		while(n>1){
			int now=p[n];
			int cnt=0;
			while(n%now==0){
				n/=now;
				cnt++;
			}
			ans=(ans*g[r][cnt])%base;
		}
		cout<<ans<<'\n';
	}
}