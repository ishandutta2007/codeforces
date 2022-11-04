#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long 
using namespace std;
int n,k,x;
ll ans,f[2][5005],inv[5005];
ll P(ll a,ll b){
	int ans=1,i;
	for (int i=a-b+1;i<=a;i++)
		ans=1ll*ans*i%mo;
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	inv[1]=1;
	for (int i=2;i<=n;i++)
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		f[i&1][0]=1;
		for (int j=1;j<=i;j++)
			f[i&1][j]=(f[(i&1)^1][j]+1ll*f[(i&1)^1][j-1]*x)%mo;
	}
	for (int i=1,j=1,l=inv[n];i<=n&&i<=k;i++,j=-j,l=1ll*l*inv[n]%mo)
		ans+=1ll*j*P(k,i)*l%mo*f[n&1][n-i]%mo;
	printf("%I64d",(ans%mo+mo)%mo);
}