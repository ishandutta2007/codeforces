#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=1000000007;
int n;
ll k;
ll f[251][251];
ll c[251][251];
ll w[251];
ll e[251];
int main(){
	cin>>n>>k;
	for(int i=0; i<=n; i++){
		c[i][0]=c[i][i]=1;
		for(int j=1; j<i; j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%base;
	}
	w[0]=1;
	e[0]=1;
	for(int i=1; i<=n; i++) w[i]=(w[i-1]*k)%base;
	for(int i=1; i<=n; i++) e[i]=(e[i-1]*(k-1))%base;
	f[0][n]=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<=n; j++){
			for(int l=0; l<j; l++) f[i+1][l]=(f[i+1][l]+((f[i][j]*c[j][l])%base)*((w[n-j]*e[l])%base))%base;
			f[i+1][j]=(f[i+1][j]+((f[i][j]*(w[n-j]-e[n-j]))%base)*e[j])%base;
		}
	}
	f[n][0]=(f[n][0]+base)%base;
	cout<<f[n][0]<<'\n';
}