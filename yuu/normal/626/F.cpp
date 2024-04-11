#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[201];
int f[104][1001];
int g[104][1001];
const int base=1000000007;
int main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	f[0][0]=1;
	for(int i=1; i<=n; i++){
		for(int x=0; x<=n/2; x++) for(int y=0; y<=k; y++) g[x][y]=0;
		for(int x=0; x<=n/2; x++) for(int y=0; y<=k; y++) if(f[x][y]) if((a[i]-a[i-1])*x+y<=k) g[x][(a[i]-a[i-1])*x+y]=f[x][y];
		for(int x=0; x<=n/2; x++) for(int y=0; y<=k; y++) f[x][y]=g[x][y];
		// for(int x=0; x<=n; x++) for(int y=0; y<=k; y++) g[x][y]=0;
		//add as an element in some group or a single element group
		for(long long x=0; x<=n/2; x++) for(int y=0; y<=k; y++) if(f[x][y])	g[x][y]=((x+1)*f[x][y])%base;
		
		// add as a single person group
		// for(long long x=0; x<=n/2; x++) for(int y=0; y<=k; y++) if(f[x][y])	g[x][y]=(g[x][y]+f[x][y])%base;
		
		//add as a new element
		for(long long x=0; x<=n/2; x++) for(int y=0; y<=k; y++) if(f[x][y])	g[x+1][y]=(f[x][y]+g[x+1][y])%base;
		//add as an ending element
		for(long long x=1; x<=n/2; x++) for(int y=0; y<=k; y++) if(f[x][y])	g[x-1][y]=(x*f[x][y]+g[x-1][y])%base;
		for(int x=0; x<=n/2; x++) for(int y=0; y<=k; y++) f[x][y]=g[x][y];
	}
	int ans=0;
	for(int i=0; i<=k; i++) ans=(ans+f[0][i])%base;
	cout<<ans<<'\n';
}