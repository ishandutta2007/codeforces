#include <bits/stdc++.h>
using namespace std;
int n;
using ll=long long;
const ll base=1000000007;
ll f[4001];
int main(){
	cin>>n;
	f[1]=1;
	for(int i=1; i<n; i++) for(int j=n; j>=1; j--) f[j]=(f[j]*(j+1)+f[j-1])%base;
	ll ans=0;
	for(int i=0; i<=n; i++) ans+=f[i];
	ans%=base;
	cout<<ans<<'\n';
}